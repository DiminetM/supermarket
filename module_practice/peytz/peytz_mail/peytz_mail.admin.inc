<?php
/**
 * @file
 * Peytz Mail module admin pages.
 *
 * @author Christian Nikolajsen <cn@peytz.dk>
 */


/**
 * Configuration form.
 */
function peytz_mail_settings_form($form, &$form_state) {
  $form = array();

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Peyt mail settings'),
    '#collapsible' => FALSE,
  );

  $form['settings']['peytz_mail_service_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Service URL'),
    '#description' => t('URL of Peytz mail service that will be used as a base while accessing the service.'),
    '#default_value' => variable_get('peytz_mail_service_url', ''),
    '#required' => TRUE,
  );

  $form['settings']['peytz_mail_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API key'),
    '#description' => t('Key used as access credential for the service.'),
    '#default_value' => variable_get('peytz_mail_api_key', ''),
    '#required' => TRUE,
  );

  $form['settings']['peytz_mail_unsubscribe_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Secret'),
    '#description' => t('A token used to validate unsubscribe requests that ensures security.'),
    '#default_value' => variable_get('peytz_mail_unsubscribe_token', ''),
    '#required' => TRUE,
  );

  $form['settings']['peytz_mail_debug_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Debug mode'),
    '#default_value' => variable_get('peytz_mail_debug_enabled', 0),
    '#description' => t('Log the extended information during service requests.'),
  );

  return system_settings_form($form);
}

/**
 * Validate settings.
 */
function peytz_mail_settings_form_validate($form, &$form_state) {
  require_once 'mailer/PeytzMailer.class.php';
  require_once 'mailer/OperationQueue.class.php';
  require_once 'mailer/Operation.class.php';

  $service_url = $form_state['values']['peytz_mail_service_url'];
  $api_key = $form_state['values']['peytz_mail_api_key'];

  $mailer = new PeytzMailer($service_url, $api_key);
  $result = $mailer->checkSettings();

  if ($result !== TRUE) {
    drupal_set_message(t('Validation failed. @msg', array('@msg' => $result)), 'error');
    form_set_error('settings');
  }
}

/**
 * Synchronization errors overview page.
 */
function peytz_mail_admin_syncerrors() {
  require_once 'mailer/Operation.class.php';

  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l('Peytz Mail', 'admin/config/peytz_mail'),
  );
  drupal_set_title(t('Synchronization errors'));
  $breadcrumb[] = drupal_get_title();
  drupal_set_breadcrumb($breadcrumb);

  $output = '';

  $errors = _peytz_mail_get_syncerrors();

  if (!count($errors)) {
    return t('There are no errors.');
  }

  $rows = array();
  foreach($errors as $error) {
    $row = array();
    $row[] = $error->method;
    //TODO: generate a link to the entity (user, term or newsletter).
    $row[] = $error->entity_id;
    $row[] = $error->status == Operation::FAILED_ERROR ? t('failed') : t('resolved');
    $row[] = format_date($error->created, 'long');
    $row[] = format_date($error->processed, 'long');
    // Operations on queue errors. Check colspan of the header.
    $row[] = l(t('Details'), 'admin/config/peytz_mail/syncerrors/view/nojs/' . $error->id, array('attributes' => array('class' => 'ctools-use-modal')));
    if ($error->status == Operation::FAILED_ERROR) {
      $title = t('Resolve');
      $op = 'resolve';
    }
    else {
      $title = t('Unresolve');
      $op = 'unresolve';
    }
    $row[] = l($title, 'admin/config/peytz_mail/syncerrors/' . $op . '/' . $error->id, array('query' => drupal_get_destination()));

    $rows[] = $row;
  }

  $headers = array(t('Operation'), t('Entity ID'), t('Status'), t('Created'), t('Processed'), array('data' => t('Operations'), 'colspan' => 2));
  $output .= theme('table', array('header' => $headers, 'rows' => $rows));

  ctools_include('modal');
  ctools_modal_add_js();

  return $output;
}

/**
 * Display error details.
 */
function peytz_mail_syncerror_view($js, $error) {
  require_once 'mailer/Operation.class.php';

  if (!$error) {
    $build = 'Error not found.';
  }
  else {
    $rows = array(
      array(
        array('data' => t('ID'), 'header' => TRUE),
        $error->id,
      ),
      array(
        array('data' => t('Entity ID'), 'header' => TRUE),
        $error->entity_id,
      ),
      array(
        array('data' => t('Status'), 'header' => TRUE),
        $error->status == Operation::FAILED_ERROR ? t('failed') : t('resolved')
      ),
      array(
        array('data' => t('Operation'), 'header' => TRUE),
        $error->method
      ),
      array(
        array('data' => t('Request'), 'header' => TRUE),
        '<pre>' . check_plain(print_r(unserialize($error->arguments), TRUE)) . '</pre>'
      ),
      array(
        array('data' => t('Response'), 'header' => TRUE),
        '<pre>' . check_plain(var_export(unserialize($error->response), TRUE)) . '</pre>'
      ),
      array(
        array('data' => t('Created'), 'header' => TRUE),
        format_date($error->created, 'long')
      ),
      array(
        array('data' => t('Processed'), 'header' => TRUE),
        format_date($error->processed, 'long')
      ),
    );

    $build['synclog_table'] = array(
      '#theme' => 'table',
      '#rows' => $rows,
      '#attributes' => array('class' => array('dblog-event')),
    );
  }

  if ($js) {
    ctools_include('ajax');
    ctools_include('modal');
    ctools_modal_render(t('Error details'), $build);
  }
  else {
    return render($build);
  }
}

/**
 * Mark errors as (un)resolved.
 */
function peytz_mail_syncerror_manage($op, $error) {
  // Include because of error definitions.
  require_once('mailer/Operation.class.php');

  if ($op == 'resolve') {
    $error->status = Operation::FAILED_PROCESSED;
  }
  elseif ($op == 'unresolve' && $error->status == Operation::FAILED_PROCESSED) {
    $error->status = Operation::FAILED_ERROR;
  }

  drupal_write_record('peytz_mail_queue', $error, array('id'));
  drupal_set_message(t('You have marked the error as @status', array('@status' => $error->status == Operation::FAILED_PROCESSED ? t('resolved') : t('unresolved'))));
  drupal_goto(drupal_get_destination());
}

/**
 * Helper function to retrieve the list of application sync errors.
 *
 * @return Array of all application errors.
 */
function _peytz_mail_get_syncerrors($unresolved_only = FALSE) {
  // Include because of error definitions.
  require_once('mailer/Operation.class.php');
  $errors = db_query('SELECT * FROM {peytz_mail_queue} WHERE status IN (:status) ORDER BY status, id', array(':status' => array(Operation::FAILED_ERROR, $unresolved_only ? NULL : Operation::FAILED_PROCESSED)))->fetchAll();
  return $errors;
}
