<?php
import('com.laurus.core.collection.Iterable');
/**
 * Description of MIterator
 * 
 * @author Kunal Mestri <kunal@laurus-it.com>
 */
class MIterator {
    private $currentIndex;
    private $size;
    private $reffArray;
    public function __construct(Iterable $iterable) {
        $this->currentIndex=0;
        $this->reffArray=$iterable->getInternalIterable();
        $this->size=count($this->reffArray);
    }

    public function hasNext(){
        return $this->currentIndex < $this->size;
    }
    
    public function & next(){
        return $this->reffArray[$this->currentIndex++];
    }
    
}

?>
