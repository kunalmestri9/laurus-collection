<?php

import("com.laurus.core.collection.ICollection");

/**
 * @name SimpleList
 *
 * @todo We must create proper interface that must be implemented by Simplelist
 * @author Kunal Mestri
 */
class SimpleList implements ICollection {

    private /* Array<? extends object> */ $origVar;
    private /* int */ $count;
  
    function __construct(/* Array<? extends object> */ $arr = null) {
        if (is_array($arr)) {
            $this->origVar = $arr;
            $this->count = count($arr);
        } else {
            $this->origVar = array();
            $this->count = 0;
        }
    }

    /**
     * @name contains
     * @todo Please update the logic for the checking
     * @param <Object> $element
     * @return <boolean>
     */
    public function contains(/* Object */ $element) {
        foreach ($this->origVar as $val) {
            if ($val == $element) { /* @todo Update the logic for checing equality */
                return true;
            }
        }
        return false;
    }

    /**
     * @name add
     * @param <Object> $element
     * @return <boolean>
     */
    public function add(/* Object */ $element) {
        if (!$this->contains($element)) {
            array_push($this->origVar, $element);
            $this->updateCount();
            return true;
        }
        return false;
    }

    public function remove(/* Object */ $element) {
        if ($this->contains($element)) {
            $this->origVar = $this->removeFromArray($element);
            $this->updateCount();
            return true;
        }
        return false;
    }

    private function removeFromArray($element) {
        $tempVar = array_values($this->origVar);
        //var_dump($tempVar);
        $i = 0;
        foreach ($tempVar as $value) {
            //echo "<br>Element  :: ".$value."::".$element."<br>";
            if ($value == $element) {
                //echo "<br>Element Matched :: ".$value."<br>";
                unset($tempVar[$i]);
            }
            $i++;
        }
        return array_values($tempVar);
    }

    private /* Void */ function updateCount() {
        $this->count = count($this->origVar);
    }

    public /* int */ function size() {
        $this->updateCount();
        return $this->count;
    }

    public /* Object [] */ function toArray() {
        return array_values($this->origVar);
    }

    /**
     * @name get
     * @param <int> $index
     * @return <Object> if found ,Otherwise null
     */
    public function get(/* int */ $index) {
        if ($this->size() > $index) {
            return $this->origVar[$index];
        }
        return null;
    }

    public function addArray($array) {
        for ($index = 0; $index < count($array); $index++) {
            $this->add($array[$index]);
        }
    }

    public function toJson() {
        $str = "[";
        for ($i = 0; $i < $this->size(); $i++) {
            $obj = $this->get($i);
            $str.=(is_object($obj) && method_exists($obj, "toJson")) ? $obj->toJson() : "\"" . $obj . "\"";
            if (($i + 1) != $this->size()) {
                $str.=",";
            }
        }
        $str.="]";
        return $str;
    }

    public function sort($cmp_function) {
        usort($this->origVar, $cmp_function);
        
    }

    

}

?>
