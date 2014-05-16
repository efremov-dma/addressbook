<?php
/**
 * @file
 * Contains CRUD functions for Contact entities.
 */

/**
 * Create contact entity
 * 
 * @param  $values
 * @return bool
 */
function contact_create($values) {
	return entity_create('contact', $values);
}

/**
 * Save Contact entity.
 * @param $contact
 * @return bool
 */
function contact_save($contact) {
	return entity_save('contact', $contact);
}

/**
 * Load multiple entities.
 * 
 * @param  bool $ids
 * @param  array $conditions
 * @return mixed
 */
function contact_load_multiple($ids = FALSE, $conditions = array()) {
	return entity_load('contact', $ids, $conditions);
}

/**
 * Load single Contact by its ID.
 * 
 * @param $id
 * @return mixed
 */
function contact_load($id) {
	return current(contact_load_multiple((array) $id));
}

/**
 * Delete multiple Contacts at once.
 * 
 * @param  $ids
 * @return bool
 */
function contact_delete_multiple($ids) {
	return entity_delete_multiple('contact', $ids);
}

/**
 * Delete single Contact by its ID.
 * 
 * @param $id
 * @return bool
 */
function contact_delete($id) {
	dsm('delete');
	return entity_delete('contact', $id);
}

/**
 * View Contact entity
 * @param  $contact
 * @param  string $view_mode
 * @param  null $langcode
 * @return bool
 */
// function contact_view($contact, $view_mode = 'full', $langcode = NULL) {
// 	return entity_view('contact', array($contact), $view_mode, $langcode);
// }