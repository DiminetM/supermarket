<?php
/**
 * @file
 * Queue operation.
 */

class Operation {

  /**
   * Just created.
   */
  const AWAITNG = 0;

  /**
   * Processed.
   */
  const PROCESSED = 1;

  /**
   * Failed on transportation level.
   */
  const FAILED_CONNECTION = 2;

  /**
   * Failed on application level.
   */
  const FAILED_ERROR = 3;

  /**
   * Operation that failed once but then resolved was marked as "resolved".
   */
  const FAILED_PROCESSED = 4;

  /**
   * Operation attributes.
   */
  public $id;
  public $entity_id;
  public $method;
  public $arguments;
  public $response;
  public $created;
  public $processed;
  public $status;

  /**
   * Process operation.
   *
   * @param PeytzMailer $mailer
   */
  public function process(PeytzMailer $mailer) {
    try {
      $parameters = unserialize($this->arguments);
      call_user_func_array(array($mailer, $this->method), $parameters);
      $code = (int) $mailer->getResponseCode();
      $this->response = $mailer->getResponseBody();

      // TODO: At the moment this is unreliable. We are hand picking ok statuses.
      if (!in_array($code, array(200, 201, 202))) {
        // Application errors are critical since may lead to unsynchronized state.
        // @todo: prevent further processing when a critical error is faced
        // (need to define such situations).
        list($msg, $args) = $this->formatLog($mailer);
        watchdog('peytz_mail', $msg, $args, WATCHDOG_ERROR);
        $this->status = self::FAILED_ERROR;
      }
    }
    // Handle other error situations like connection issues.
    catch (Exception $e) {
      list($msg, $args) = $this->formatLog($mailer);
      watchdog('peytz_mail', (string) $e . "\n\n" . $msg, $args, WATCHDOG_ERROR);
      $this->status = self::FAILED_CONNECTION;
      return FALSE;
    }

    $this->status = self::PROCESSED;

    // Log errors or requests data if debug enalbed.
    if ($mailer->isDebugMode()) {
      list($msg, $args) = $this->formatLog($mailer);
      watchdog('peytz_mail', $msg, $args, WATCHDOG_DEBUG);
    }

    return TRUE;
  }

  /**
   * Prepare log entry for further usage by watchdog.
   *
   * @param PeytzMailer $mailer
   * @return array
   *   first element is log message, second is list of arguments.
   */
  protected function formatLog(PeytzMailer $mailer) {
    return array(
      "<h3>" . $this->method . "</h3> "
      . "\nThe following application code was received: @code."
      . "<pre>\nHEADERS:\n@details\n\nRESPONSE BODY:\n@body\nREQUEST PARAMS:\n @request</pre>",
      array(
        '@code' => $mailer->getResponseCode(),
        '@details' => $mailer->getRequestDetails(),
        '@body' => var_export($mailer->getResponseBody(), TRUE),
        '@request' => print_r(unserialize($this->arguments), TRUE),
      )
    );
  }
}
