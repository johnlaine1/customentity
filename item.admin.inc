<?php
/**
 * @file
 * Admin pages for item.module.
 */

/**
 * Form for adding or editing a item entity.
 *
 * The name of the form function is constructed as follows:
 * [entity machine name]_form.
 */
function item_form($form, &$form_state, $item) {
  $form['label'] = array(
    '#title' => t('Item ID'),
    '#type' => 'textfield',
    '#default_value' => isset($item->label) ? $item->label : '',
    '#description' => t('The label for this item entity'),
    '#required' => TRUE,
    '#weight' => -50,
  );  

  field_attach_form('item', $item, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($item->id) ? t('Update Item') : t('Save Item'),
    ),
  );
  return $form;  
}

/**
 * Validation form for item_form.
 */
function item_form_validate($form, &$form_state) {
  // Validation code.
}

/**
 * Submit handler for item_form.
 */
function item_form_submit($form, &$form_state) {
  $item = entity_ui_form_submit_build_entity($form, $form_state);
  $item->save();
  drupal_set_message(t('The entity @item_label has been saved.', array('@item_label' => $item->label)));
  $form_state['redirect'] = 'admin/structure/item';
}