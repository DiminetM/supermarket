<?php
/**
 * @file
 * Class that allows to communicate to
 * an Peytz Co. external mass-mailing system
 * using RESTful protocol.
 */

class PeytzMailer {

  /**
   * API key used for authentication.
   * @var string
   */
  private $api_key;


  /**
   * Service domain.
   * @var string
   */
  private $service_url;

  /**
   * cURL handle.
   * @var resource
   */
  private $curl_handle;

  /**
   * Additional options.
   * @var array
   */
  private $options = array();

  /**
   * Service operation response code.
   * @var string
   */
  private $response_code;

  /**
   * Service operation response body.
   * @var string
   */
  private $response_body;

  /**
   * Request debug information.
   * @var string
   */
  private $request_details;

  /**
   * Instantiates mailer objects by setting
   * credentials for HTTP basic authentication.
   *
   * @param string $service_url
   *  Base REST address of the external mailing gateway.
   * @param type $api_key
   *  API key necessary for authentication.
   * @throws MailerException
   */
  public function __construct($service_url, $api_key) {
    $this->service_url = $service_url;
    $this->api_key = $api_key;

    $this->options = array(
      'debug'   => FALSE,
      'timeout' => 30
    );
  }

  /**
   * Check settings of mailer.
   *
   * @return boolean
   *   are the settings valid?
   */
  public function isNotReadyForRequests() {
    return empty($this->service_url) || empty($this->api_key);
  }

  /**
   * Validate configuration setting by attempting an API call.
   */
  public function checkSettings() {
    try {
      $response = $this->getMailingLists();
      if (!empty($response->error)) {
        return $response->error;
      }

      if ($this->response_code != 200) {
        return "An error occurred. Code {$this->response_code}, reponse: " . var_export($this->response_body, TRUE) . ".";
      }
    }
    catch (MailerException $e) {
      return $e->getMessage();
    }

    return TRUE;
  }

  /**
   * Enables/disabled debug mode.
   */
  public function setOptions($options) {
    $this->options = array_merge($this->options, $options);
  }

  /**
   * Retrieves current configuration options.
   */
  public function getOptions() {
    return $this->options;
  }

  /**
   * Check for debug mode.
   *
   * @return boolean
   *   is debug mode enabled.
   */
  public function isDebugMode() {
    return $this->options['debug'];
  }

  /**
   * Performs a RESTful request (using cURL library).
   * @param type $path
   * @param type $method
   * @param type $data
   * @param type $headers
   * @throws MailerException
   */
  private function request($path, $method = 'GET', $data = array(), $headers = NULL) {
    // @todo: Implement error reporting
    if (empty($path)) {
      throw new MailerException('Please supply a non-empty path to make a request.');
    }

    $mandatory_headers = array(
      'Accept: application/json',
      'Content-Type: application/json'
    );
    if ($headers && is_array($headers)) {
      $mandatory_headers = array_merge($mandatory_headers, $headers);
    }
    $json_data = json_encode($data);

    $this->curl_handle = curl_init(rtrim($this->service_url, '/') . '/' . $path);
    curl_setopt($this->curl_handle, CURLOPT_FOLLOWLOCATION, TRUE);
    curl_setopt($this->curl_handle, CURLOPT_HTTPHEADER, $mandatory_headers);
    curl_setopt($this->curl_handle, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($this->curl_handle, CURLOPT_SSL_VERIFYHOST, FALSE);
    curl_setopt($this->curl_handle, CURLOPT_SSL_VERIFYPEER, FALSE);
    curl_setopt($this->curl_handle, CURLOPT_USERPWD, $this->api_key . ':');

    if (!empty($this->options['debug'])) {
      curl_setopt($this->curl_handle, CURLOPT_VERBOSE, TRUE);
      $dbg = fopen('php://temp', 'r+');
      curl_setopt($this->curl_handle, CURLOPT_STDERR, $dbg);
    }

    if (!empty($this->options['timeout'])) {
      curl_setopt($this->curl_handle, CURLOPT_CONNECTTIMEOUT, $this->options['timeout']);
    }

    switch ($method) {
      case 'PUT':
        curl_setopt($this->curl_handle, CURLOPT_CUSTOMREQUEST, 'PUT');
        curl_setopt($this->curl_handle, CURLOPT_POSTFIELDS, $json_data);
        break;
      case 'DELETE':
        curl_setopt($this->curl_handle, CURLOPT_CUSTOMREQUEST, 'DELETE');
        curl_setopt($this->curl_handle, CURLOPT_POSTFIELDS, $json_data);
        break;
      case 'POST':
        curl_setopt($this->curl_handle, CURLOPT_CUSTOMREQUEST, 'POST');
        curl_setopt($this->curl_handle, CURLOPT_POSTFIELDS, $json_data);
        break;
      default: // GET is default
        curl_setopt($this->curl_handle, CURLOPT_HTTPGET, TRUE);
        break;
    }

    $response = curl_exec($this->curl_handle);

    if (!empty($this->options['debug'])) {
      rewind($dbg);
      $this->request_details = stream_get_contents($dbg);
      fclose($dbg);
    }

    if ($response === FALSE) {
      throw new MailerException(curl_error($this->curl_handle));
    }

    $this->response_code = curl_getinfo($this->curl_handle, CURLINFO_HTTP_CODE);
    $this->response_body = json_decode($response);

    curl_close($this->curl_handle);
    $this->curl_handle = NULL;

    return $this->response_body;
  }

  public function getResponseCode() {
    return $this->response_code;
  }

  public function getResponseBody() {
    return $this->response_body;
  }

  public function getRequestDetails($secure = TRUE) {
    // Replace API with asterisks.
    if ($secure) {
      $this->request_details = str_replace($this->api_key, '*****', $this->request_details);
    }
    return $this->request_details;
  }

  /**
   * Creates new subscriber.
   * @param array $data
   *  subscriber details.
   * @throws MailerException
   */
  public function createSubscriber($data) {
    if (empty($data) || empty($data['email'])) {
      throw new MailerException("Subscriber's email is required.");
    }

    $path = 'subscribers.json';
    $data = array('subscriber' => $data);
    return $this->request($path, 'POST', $data);
  }

  /**
   * Subscriber find/get methods.
   */
  public function getSubscriber($id) {
    if ($id) {
      $path = 'subscribers/' . $id . '.json';
    }
    else {
      throw new MailerException("Subscriber ID is required.");
    }
    return $this->request($path);
  }

  public function getSubscribers() {
    $path = 'subscribers.json';
    return $this->request($path);
  }

  public function findSubscribers($parameters) {
    if (empty($parameters)) {
      throw new MailerException("No search parameters supplied.");
    }

    $params = array();
    foreach ($parameters as $key => $value) {
      $params[] = "criteria[$key]=$value";
    }
    $path = 'subscribers/search.json?' . join('&', $params);
    return $this->request($path);
  }

  /**
   * Create new mailinglist.
   */
  public function createMailingList($data) {
    if (empty($data) || !is_array($data)) {
      throw new MailerException("Required parameters: title, send_welcome_mail, send_confirmation_mail, default_template");
    }
    if (!isset($data['title'])) {
      throw new MailerException("Mailinglist title is required.");
    }
    if (!isset($data['send_welcome_mail'])) {
      throw new MailerException("Mailinglist parameter 'send_welcome_mail' is required.");
    }
    if (!isset($data['send_confirmation_mail'])) {
      throw new MailerException("Mailinglist parameter 'send_confirmation_mail' is required.");
    }
    if (!isset($data['default_template'])) {
      throw new MailerException("Mailinglist should have a 'default_template' specified.");
    }

    $path = 'mailinglists.json';
    $data = array('mailinglist' => $data);
    return $this->request($path, 'POST', $data);
  }

  /**
   * Add new subscriber to mailinglist(s).
   */
  public function subscribe($data) {
    if (empty($data['subscriber']) || empty($data['subscriber']['email'])) {
      throw new MailerException("Subscriber's email is required.");
    }

    if (empty($data['mailinglist_ids'])) {
      throw new MailerException("Mailinglist IDs are required and cannot be empty.");
    }

    $path = 'mailinglists/subscribe.json';
    $data = array('subscribe' => $data);
    return $this->request($path, 'POST', $data);
  }

  /**
   * Unsubscribe subscriber from mailinglist(s).
   */
  public function unsubscribe($data) {
    if (empty($data['email'])) {
      throw new MailerException("Unsubscribe email is required.");
    }

    $path = 'mailinglists/unsubscribe.json';
    $data = array('unsubscribe' => $data);
    return $this->request($path, 'POST', $data);
  }

  /**
   * Unsubscribe single subscriber by IF from single mailinglist.
   * @param type $mailinglist_id
   * @param type $subscriber_id
   * @return type
   */
  public function unsubscribeById($mailinglist_id, $subscriber_id) {
    if (empty($mailinglist_id)) {
      throw new MailerException("Mailinglist ID is required and cannot be empty.");
    }

    if (empty($subscriber_id)) {
      throw new MailerException("Subscriber ID is required and cannot be empty.");
    }

    $path = 'mailinglists/' . $mailinglist_id . '/subscribers/' . $subscriber_id . '.json';
    return $this->request($path, 'DELETE');
  }

  /**
   * Get all of the existing mailinglists.
   */
  public function getMailingList($mailinglist_id) {
    if (empty($mailinglist_id)) {
      throw new MailerException("Mailinglist ID is required and cannot be empty.");
    }

    $path = 'mailinglists/' . $mailinglist_id . '.json';
    return $this->request($path);
  }

  /**
   * Get all of the existing mailinglists.
   */
  public function getMailingLists() {
    $path = 'mailinglists.json';
    return $this->request($path);
  }

  /**
   * Get newsletters
   * Required parameters: mailinglist_id
   */
  public function getNewsletters($mailinglist_id) {
    if (empty($mailinglist_id)) {
      throw new MailerException("Mailinglist ID is required and cannot be empty.");
    }

    $path = 'mailinglists/' . $mailinglist_id . '/newsletters.json';
    return $this->request($path);
  }

  /**
   * Create newsletter and assign a mailinglist to it.
   * Required parameters: mailinglist_id, title, template
   */
  public function createNewsletter($mailinglist_id, $data) {
    if (empty($mailinglist_id)) {
      throw new MailerException("Mailinglist ID is required and cannot be empty.");
    }

    if (empty($data) || empty($data['title']) || empty($data['template'])) {
      throw new MailerException("Newsletter title and template are required.");
    }

    $path = 'mailinglists/' . $mailinglist_id . '/newsletters.json';
    $data = array('newsletter' => $data);
    return $this->request($path, 'POST', $data);
  }

  /**
   * Configure newsletter by setting its data feed source.
   */
  public function configureNewsletter($mailinglist_id, $newsletter_id, $data) {
    if (empty($mailinglist_id)) {
      throw new MailerException("Mailinglist ID is required and cannot be empty.");
    }

    if (empty($data['feeds'])) {
      throw new MailerException("Newsletter feed are required.");
    }

    foreach ($data['feeds'] as $feed) {
      if (empty($feed['name'])) {
        throw new MailerException("Feed's name is required.");
      }
    }

    $path = 'mailinglists/' . $mailinglist_id . '/newsletters/' . $newsletter_id . '/push_data.json';
    $data = array('newsletter' => $data);
    return $this->request($path, 'POST', $data);
  }

  /**
   * Performs a test send of newsletter to single email address.
   * @param string $mailinglist_id
   * @param string $newsletter_id
   * @param string $email
   * @return string
   *  response body
   */
  public function testNewsletter($mailinglist_id, $newsletter_id, $email) {
    if (empty($mailinglist_id)) {
      throw new MailerException("Mailinglist ID is required and cannot be empty.");
    }

    if (empty($newsletter_id)) {
      throw new MailerException("Newsletter ID is required and cannot be empty.");
    }

    $path = 'mailinglists/' . $mailinglist_id . '/newsletters/' . $newsletter_id . '/test.json';
    $path .= '?email=' . $email;
    return $this->request($path);
  }

  /**
   * Sends a newsletter.
   * @todo: implement create-and-send method if required.
   * @param string $mailinglist_id
   * @param string $newsletter_id
   * @return string
   *  response body
   */
  public function sendNewsletter($mailinglist_id, $newsletter_id) {
    if (empty($mailinglist_id)) {
      throw new MailerException("Mailinglist ID is required and cannot be empty.");
    }

    if (empty($newsletter_id)) {
      throw new MailerException("Newsletter ID is required and cannot be empty.");
    }

    $path = 'mailinglists/' . $mailinglist_id . '/newsletters/' . $newsletter_id . '/send.json';
    return $this->request($path);
  }

  /**
   * Retrieve detailed information about newsletter including sending statistics.
   * @todo: implement retreival of paginated list of newsletters if needed.
   * @param type $mailinglist_id
   * @param type $newsletter_id
   * @return type
   */
  public function getNewsletterDetails($mailinglist_id, $newsletter_id) {
    if (empty($mailinglist_id)) {
      throw new MailerException("Mailinglist ID is required and cannot be empty.");
    }

    if (empty($newsletter_id)) {
      throw new MailerException("Newsletter ID is required and cannot be empty.");
    }

    $path = 'mailinglists/' . $mailinglist_id . '/newsletters/' . $newsletter_id . '.json';
    return $this->request($path);
  }
}

class MailerException extends Exception {

}
