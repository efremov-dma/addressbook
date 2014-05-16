<?php
/**
 * @file
 * addressbook_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function addressbook_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function addressbook_feature_image_default_styles() {
  $styles = array();

  // Exported image style: contact_preview.
  $styles['contact_preview'] = array(
    'name' => 'contact_preview',
    'label' => 'Contact preview',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 75,
          'height' => 75,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
