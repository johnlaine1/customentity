<?php
/**
 * @file
 * Admin pages for customentity.module.
 */

/**
 * Form for adding or editing a CustomEntity entity.
 *
 * The name of the form function is constructed as follows:
 * [entity machine name]_form.
 */
function customentity_form($form, &$form_state, $customentity) {
  $form['label'] = array(
    '#title' => t('CustomEntity ID'),
    '#type' => 'textfield',
    '#default_value' => isset($customentity->label) ? $customentity->label : '',
    '#description' => t('The label for this CustomEntity entity'),
    '#required' => TRUE,
    '#weight' => -50,
  );  

  field_attach_form('customentity', $customentity, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($customentity->id) ? t('Update CustomEntity') : t('Save CustomEntity'),
    ),
  );
  return $form;  
}

/**
 * Validation form for customentity_form.
 */
function customentity_form_validate($form, &$form_state) {
  // Validation code.
}

/**
 * Submit handler for customentity_form.
 */
function customentity_form_submit($form, &$form_state) {
  $customentity = entity_ui_form_submit_build_entity($form, $form_state);
  $customentity->save();
  drupal_set_message(t('The entity @customentity_label has been saved.', array('@customentity_label' => $customentity->label)));
  $form_state['redirect'] = 'admin/structure/customentity';
}