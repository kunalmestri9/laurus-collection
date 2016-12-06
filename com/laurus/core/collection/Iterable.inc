<?php
/**
 * Description of Iterable
 * 
 * @author Kunal Mestri <kunal@laurus-it.com>
 */
interface Iterable {
    public function & getInternalIterable();
    public function getIterator();   
}

?>
