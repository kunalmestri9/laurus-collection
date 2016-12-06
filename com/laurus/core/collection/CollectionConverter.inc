<?php
/**
 * Description of CollectionConverter
 *
 * @author Kunal Mestri <kunal@laurus-it.com>
 */
import("com.laurus.core.collection.SimpleList");
import("com.laurus.core.collection.map.ExMap");


class CollectionConverter {
    public static function mapToSimpleList(Iterable $map,$old=false){
        $simpleList=new SimpleList();
        /* @var $iterator MIterator*/
        $iterator=$map->getIterator();
        while ($iterator->hasNext()){
            $val=$iterator->next();
            $simpleList->add(($old)?$val->getValue():$val);
        }
        return $simpleList;
    }
    
    public static function simpleListToExMap(SimpleList $simpleList,$methodName){
        $exMap=new ExMap();
        for ($index = 0; $index < $simpleList->size(); $index++) {
            $obj=$simpleList->get($index);
            $key=call_user_method($methodName, $obj);
            $exMap->put($key, $obj);
        }
        return $exMap;
    }
    
    public static function removeDuplicatedValuesFromSimpleList(SimpleList $simpleList){
        $exMap=new ExMap();
        for ($index = 0; $index < $simpleList->size(); $index++) {
            $str=$simpleList->get($index);
            $exMap->put($str, $str);
        }
        return self::mapToSimpleList($exMap);
    }
    
}

?>
