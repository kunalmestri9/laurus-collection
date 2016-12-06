<?php
import('com.laurus.core.collection.map.Entry');
import('com.laurus.core.collection.MIterator');
import("com.laurus.core.collection.ICollection");

class Map implements Iterable,ICollection{
   protected /*Entry []*/ $entries=array();
   
   public function size(){
       return count($this->entries);
   }
   
   public  function putEntry(Entry $entry){
       if(!$this->isKeyPresent($entry->getKey())){
        array_push($this->entries, $entry);
       }
       /* else {
          throw new DuplicateKey Exception
       }*/
   }
   
   public  function put($key,$value){
       $entry=new Entry($key,$value);
       if(!$this->isKeyPresent($entry->getKey())){
            array_push($this->entries, $entry);
       }
       /* else {
          throw new DuplicateKey Exception
       }*/
   }
   public  function forceput($key,$value){
       $entry=new Entry($key,$value);
            array_push($this->entries, $entry);
   }
   
   protected /*bool*/function isKeyPresent($key){
       foreach ($this->entries as $entry) {
            if($entry->getKey()==$key){
                return true;
            }
       }
       return false;
   }
   public  function /*Entry*/ get($key){
       foreach ($this->entries as $entry) {
            if($entry->getKey()==$key){
                return $entry;
            }
       }
       return false;
   }
   public  function /*Entry*/ getValue($key){
       foreach ($this->entries as $entry) {
            if($entry->getKey()==$key){
                return $entry->getValue();
            }
       }
       return false;
   }
   
   public function contains($key){
       return $this->isKeyPresent($key);
   }
   
    public function & getInternalIterable() {
        return $this->entries;
    }
    /**
     * 
     * @return \MIterator
     */
    public function getIterator() {
        return new MIterator($this);
    }
    
    public function toJson(){
        $str="{";
        $iterator=$this->getIterator();
        while($iterator->hasNext()){
            /* @var $entry Entry */
            $entry=$iterator->next();
            $str.="\"". $entry->getKey() ."\" : ";
            $str.=(is_object($entry->getValue()) && method_exists($entry->getValue(),"toJson")) ? $entry->getValue()->toJson(): json_encode($entry->getValue())  ;
            if($iterator->hasNext())$str.=",";
        }
        $str.="}";
        return $str;
    }
}

?>
