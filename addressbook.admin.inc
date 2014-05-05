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
function contact_form($form, &$form_state, $contact, $op = 'edit') {

  $form['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => isset($contact->title) ? $contact->title : '',
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

function contact_form_submit($form, &$form_state) {
  $contact = entity_ui_form_submit_build_entity($form, $form_state);
  

  dsm($contact, 'contact');

  $contact->save();

  $form_state['redirect'] = 'admin/content/contact';
}