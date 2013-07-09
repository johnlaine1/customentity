<?php
/**
 * @file
 * Admin pages for ect.module.
 */

/**
 * Form for adding or editing a ect entity.
 *
 * The name of the form function is constructed as follows:
 * [entity machine name]_form.
 */
function ect_form($form, &$form_state, $ect) {
  $form['label'] = array(
    '#title' => t('ECT ID'),
    '#type' => 'textfield',
    '#default_value' => isset($ect->label) ? $ect->label : '',
    '#description' => t('The label for this ECT entity'),
    '#required' => TRUE,
    '#weight' => -50,
  );  

  field_attach_form('ect', $ect, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($ect->id) ? t('Update Entity') : t('Save Entity'),
    ),
  );
  return $form;  
}

/**
 * Validation form for ect_form.
 */
function ect_form_validate($form, &$form_state) {
  // Validation code.
}

/**
 * Submit handler for ect_form.
 */
function ect_form_submit($form, &$form_state) {
  $ect = entity_ui_form_submit_build_entity($form, $form_state);
  $ect->save();
  drupal_set_message(t('The entity @ect_label has been saved.', array('@ect_label' => $ect->label)));
  $form_state['redirect'] = 'admin/structure/ect';
}