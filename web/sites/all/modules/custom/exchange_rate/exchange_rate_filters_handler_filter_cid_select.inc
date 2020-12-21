<?php
/**
 * Class exchange_rate_filters_handler_filter_cid_select.
 */

class exchange_rate_filters_handler_filter_cid_select extends views_handler_filter_in_operator {
  /**
   * @inheritDoc
   */
  function get_value_options() {
    $list = array();

    $query = db_select(EXCHANGE_RATE_CURRENCY_ENTITY_TYPE, 'c')
      ->distinct()
      ->fields('c', array('cid', 'Name'))
      ->orderBy('c.Name');
    $results = $query->execute();

    foreach($results as $result) {
      $list[$result->cid] = $result->Name;
    }

    $this->value_options = $list;

    return $list;
  }
}
