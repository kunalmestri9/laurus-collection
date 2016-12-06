<?php

import("com.laurus.core.collection.map.Map");

/**
 * Description of JsonMap
 *
 * @author Kunal Mestri
 */
class JsonMap extends Map{
    
    public function put($key, $value) {
        if(!is_null($value)){
            parent::put($key, $value);
        }
    }
}

?>
