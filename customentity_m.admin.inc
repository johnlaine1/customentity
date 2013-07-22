<?php
/**
 * @file
 * Admin pages for customentity_m.module.
 */

/**
 * Form for adding or editing a customentity_m entity.
 *
 * The name of the form function is constructed as follows:
 * [entity machine name]_form.
 */
function customentity_m_form($form, &$form_state, $customentity_m) {
  $form['label'] = array(
    '#title' => t('Customentity_h ID'),
    '#type' => 'textfield',
    '#default_value' => isset($customentity_m->label) ? $customentity_m->label : '',
    '#description' => t('The label for this Customentity_h entity'),
    '#required' => TRUE,
    '#weight' => -50,
  );  

  field_attach_form('customentity_m', $customentity_m, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($customentity_m->id) ? t('Update Customentity_h') : t('Save Customentity_h'),
    ),
  );
  return $form;  
}

/**
 * Validation form for customentity_m_form.
 */
function customentity_m_form_validate($form, &$form_state) {
  // Validation code.
}

/**
 * Submit handler for customentity_m_form.
 */
function customentity_m_form_submit($form, &$form_state) {
  $customentity_m = entity_ui_form_submit_build_entity($form, $form_state);
  $customentity_m->save();
  drupal_set_message(t('The entity @customentity_m_label has been saved.', array('@customentity_m_label' => $customentity_m->label)));
  $form_state['redirect'] = 'admin/structure/customentity_m';
}