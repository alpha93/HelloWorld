<?php
    class Test {
        public static $val = 14;   // Properties may or may not have a default value set. A static                                     property cannont be directly accessed by an object of the class                                 but a static method can be. Only class references can be used to                                 access a static property. 
        const SUN = 'east';
        
        function print_constant() {
            echo self::SUN;        // Constants are always referenced using a class reference, using                               either the class name(form inside or outside of the class) or the                           'self' keyword(from inside the class).
        }
        
        static function static_method() {
            //echo $val;           // static methods have no access to any(static or non-static)                                   properties of a class.      
        }
    }

    $obj = new Test();
    //echo $obj->SUN;              // It's an error to refer to a constant using object references.                                       Object references are only for properties and methods.
    $obj->print_constant();
    $obj->static_method();
?>