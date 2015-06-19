<?php
/**
 * @file
 * Class that allows to asynchronously communicate to
 * an external mass-mailing system by means of an operation queue.
 */

class OperationQueue {

  /**
   * Instance of Peytz Mail API client.
   * @var PeytzMailer
   */
  protected $mailer;

  /**
   * Object constructor.
   *
   * @param PeytzMailer $mailer_instance
   *   Mailer instance.
   */
  public function __construct(PeytzMailer $mailer_instance) {
    $this->mailer = $mailer_instance;
  }

  /**
   * Execute mailer action.
   *
   * @throws MailerException
   *
   * @param string $method
   *   Mailer method.
   * @param string $entity_id
   *   Entity id.
   * @param array $arguments
   *   List of arguments.
   *
   * @return mixed
   *   The last insert ID of the query, if one exists. If the query
   *   was given multiple sets of values to insert, the return value is
   *   undefined.
   */
  public function put($method, $entity_id, array $arguments) {
    if (!method_exists($this->mailer, $method)) {
      $e = new MailerException('Unknown Peytz Mail API method ' . $method, WATCHDOG_CRITICAL);
      watchdog_exception('peytz_mail', $e, array(), WATCHDOG_CRITICAL);
      throw $e;
    }

    $item = array(
      'entity_id' => $entity_id,
      'method'    => $method,
      'arguments' => serialize($arguments),
      'response'  => '',
      'created'   => time(),
    );

    return db_insert('peytz_mail_queue')->fields($item)->execute();
  }

  /**
   * Process all the queue items eligible for processing (new and failed).
   */
  public function processAll() {

    // Do not allow other calls to acquire this lock until it's not released.
    if (!lock_acquire('peytz_mail', 3600)) {
      watchdog('peytz_mail', 'Cannot start queue processing because it is being processed', NULL, WATCHDOG_WARNING);
      return;
    }

    try {
      $ops = $this->fetchOperations();

      // Start operation processing.
      if (count($ops)) {
        $this->onBeforeProcessAll();
        foreach ($ops as $op) {
          $this->processOperation($op);
        }
        $this->onAfterProcessAll();
      }
    }
    catch (Exception $e) {
      lock_release('peytz_mail');
      watchdog_exception('peytz_mail', $e);
      throw $e;
    }

    lock_release('peytz_mail');
  }

  /**
   * Fetch items from queue.
   *
   * @return array
   *   list of operations.
   */
  protected function fetchOperations() {
    $ops = db_select('peytz_mail_queue', 'q')
      ->fields('q')
      ->condition('status', array(
          Operation::AWAITNG,
          Operation::FAILED_CONNECTION,
      ))
      ->execute()
      ->fetchAll(PDO::FETCH_CLASS, 'Operation');

    function _dump_helper($op) {
      $dump_op = clone $op;
      $dump_op->arguments = unserialize($op->arguments);
      $dump_op->response = unserialize($op->response);
      return var_export($dump_op, TRUE);
    }

    if ($this->mailer->isDebugMode()) {
      $operations_dump = array_map('_dump_helper', $ops);
      if ($ops) {
        watchdog(
          'peytz_mail',
          "Queue processing started. Operations to process: @cnt.\n\nOperations:\n<pre>@operations</pre>",
          array(
            '@cnt' => count($ops),
            '@operations' => implode("\n\n===================\n\n", $operations_dump),
          ),
          WATCHDOG_DEBUG
        );
      }
      else {
        watchdog(
          'peytz_mail',
          "There are no operations in queue for processing.",
          NULL,
          WATCHDOG_DEBUG
        );
      }
    }

    return $ops;
  }

  /**
   * Special event will fire up right before processing.
   *
   * @throws MailerException
   */
  protected function onBeforeProcessAll() {
    if ($this->mailer->isNotReadyForRequests()) {
      $error_msg = 'Empty service URL or API key, the queue can not be processed.';
      watchdog('peytz_mail', $error_msg, array(), WATCHDOG_CRITICAL);
      throw new MailerException($error_msg, WATCHDOG_CRITICAL);
    }
  }

  /**
   * Special event will fire up right after processing.
   */
  protected function onAfterProcessAll() {
    if ($this->mailer->isDebugMode()) {
      watchdog('peytz_mail', 'Queue processing finished.', NULL, WATCHDOG_DEBUG);
    }
  }

  /**
   * Process single operation.
   *
   * @param stdClass $op
   *   operation row.
   */
  protected function processOperation(Operation $op) {

    $op->process($this->mailer);

    // Mark the operation as processed.
    db_update('peytz_mail_queue')
      ->fields(array(
        'status'    => $op->status,
        'response'  => serialize($op->response),
        'processed' => time()))
      ->condition('id', $op->id)
      ->execute();
  }

  /**
   * Returns an instance of associated Peytz Mail API client.
   * @return PeytzMailer instance.
   */
  public function getMailer() {
    return $this->mailer;
  }
}
