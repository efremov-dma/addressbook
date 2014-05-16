<?php
/**
 * @file
 * Contains Contact entity add/edit form.
 */

/**
 * Add/edit form calback for Contact entities.
 * 
 * @param $form
 * @param $form_state
 * @param $contact
 * @param string $op
 * @return array
 */
function contact_form($form, &$form_state, $contact, $op = '') {
  global $user;

  /* Load styles and script */
  drupal_add_js(drupal_get_path('module', 'addressbook') . '/js/multistep-form.js');
  drupal_add_css(drupal_get_path('module', 'addressbook') . '/css/multistep-form.css');

  /* Set breadcrumbs */
  switch ($op) {
    case 'add':
      $last_bread = l( t('Add contact'), 'address-book/add' );
      break;
    case 'edit':
      $last_bread = l( t('Edit contact'), 'address-book/manage/' . $contact->cid );
      break;
  }
  $breadcrumbs[] = l(t('Home'), NULL);
  $breadcrumbs[] = l(t('Address book'), 'address-book');
  $breadcrumbs[] = $last_bread;
  drupal_set_breadcrumb($breadcrumbs);

  /* Add properties to the form.*/
  $form['created'] = array(
    '#type' => 'hidden',
    '#title' => t('Created'),
    '#default_value' => time(),
  );

  $form['user_id'] = array(
    '#type' => 'hidden',
    '#title' => t('user_id'),
    '#default_value' => $user->uid,
  );

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save'),
    ),
  );

  /* Attach fields to the form. */
  field_attach_form('contact', $contact, $form, $form_state);

  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter().
 * @param $form
 * @param $form_state
 */
function addressbook_form_contact_form_alter(&$form, &$form_state) {
  /* Step 1 */
  $form['step_1'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Name'), 
    '#attributes' => array(
      'class' => array('addressbook-form-step addressbook-form-step-active'),
    ),
  );

  /* Step 2 */
  $form['step_2'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Photo'), 
    '#attributes' => array(
      'class' => array('addressbook-form-step'),
    ),
  );

  /* Step 3 */
  $form['step_3'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Contacts'), 
    '#attributes' => array(
      'class' => array('addressbook-form-step'),
    ),
  );

  /* Step 4 */
  $form['step_4'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Birthday'), 
    '#attributes' => array(
      'class' => array('addressbook-form-step'),
    ),
  );

  /* Step 5 */
  $form['step_5'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Category'), 
    '#attributes' => array(
      'class' => array('addressbook-form-step'),
    ),
  );

  /* Step 6 */
  $form['step_6'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Notes'), 
    '#attributes' => array(
      'class' => array('addressbook-form-step'),
    ),
  );

  $form['step_1']['field_first_name'] = $form['field_first_name'];
  $form['step_1']['field_last_name']  = $form['field_last_name'];
  $form['step_2']['field_photo'] = $form['field_photo'];
  $form['step_3']['field_email'] = $form['field_email'];
  $form['step_3']['field_phone'] = $form['field_phone'];
  $form['step_4']['field_birthday'] = $form['field_birthday'];
  $form['step_5']['field_category'] = $form['field_category'];
  $form['step_6']['field_notes'] = $form['field_notes'];
  $form['step_6']['actions'] = $form['actions'];
  $form['step_6']['actions']['#weight'] = 8;


  /* Next button */
  for ($i = 1; $i <= 5; $i++) {
    $form['step_'.$i]['next_'.$i] = array(
      '#type' => 'button',
      '#value' => t('Next'),
      '#attributes' => array( 
        'class' => array('addressbook-next-step'),
        ),
      '#weight' => 10,

    );
  }

  /* Previous button */
  for ($i = 2; $i <= 6; $i++) {
    $form['step_'.$i]['prev_'.$i] = array(
      '#type' => 'button',
      '#value' => t('Previous'),
      '#attributes' => array(
        'class' => array('addressbook-prev-step'),
      ),
      '#weight' => 9,
    );
  }

  unset($form['field_first_name']);
  unset($form['field_last_name']);
  unset($form['field_photo']);
  unset($form['field_email']);
  unset($form['field_phone']);
  unset($form['field_birthday']);
  unset($form['field_category']);
  unset($form['field_notes']);
  unset($form['actions']);

}

/**
 * Submit callback.
 * @param $form
 * @param $form_state
 */
function contact_form_submit($form, &$form_state) {
  $contact = entity_ui_form_submit_build_entity($form, $form_state);
  $contact->save();
  $form_state['redirect'] = 'address-book';
}
