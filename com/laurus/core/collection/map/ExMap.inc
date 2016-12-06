<?php

import("com.laurus.core.collection.map.Map");

/**
 * Description of ExMap
 *
 * @author Amruta Vichare
 */
class ExMap extends Map{
    public function size(){
       return count($this->entries);
    }
    public  function put($key,$value){
       if(!$this->isKeyPresent($key)){
               
           $this->entries[$key]=$value;
       }
       
   }
   
   protected /*bool*/function isKeyPresent($key){
       if($this->entries[$key]){
           return true;
       }
       return false;
   }
   
   
   public  function getValue($key){
       if($this->isKeyPresent($key)){
           return $this->entries[$key];
       }
            
       return false;
   }
   public  function getKeys(){
       $keyArray=array();
       $i=0;
       foreach ($this->entries as $key => $value) {
            $keyArray[$i++]=$key;
       }
       return $keyArray;
   }
   
   public function contains($key){
       return $this->isKeyPresent($key);
   }
   
    public function & getInternalIterable() {
        return array_values($this->entries);
    }
    /**
     * 
     * @return \MIterator
     */
    public function getIterator() {
        return new MIterator($this);
    }
    public function remove($key){
         if($this->isKeyPresent($key)){
             unset($this->entries[$key]);  
         }
    }
    public function toJson(){
        
        $str="{";
        $keys=$this->getKeys();
       
        for($i=0;$i< count($keys); $i++){
             $str.="\"". $keys[$i] ."\" : ";
             $str.=(is_object($this->entries[$keys[$i]]) && method_exists($this->entries[$keys[$i]] ,"toJson")) ? $this->entries[$keys[$i]] ->toJson(): json_encode($this->entries[$keys[$i]] )  ;
             if($i !=(count($keys)-1))$str.=",";
        
       
        }
        $str.="}";
        return $str;
    }
}

?>
