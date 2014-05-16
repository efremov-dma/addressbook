<?php
/**
 * @file
 * addressbook_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function addressbook_feature_taxonomy_default_vocabularies() {
  return array(
    'addresbook_categories' => array(
      'name' => 'Address Book Categories',
      'machine_name' => 'addresbook_categories',
      'description' => 'Categories for your contact.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
