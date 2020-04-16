/*
THIS FILE CONTAINS UTILITY METHODS TO BE USED ACROSS VARIOUS PROGRAMS IN THIS PROJECT
*/

int button_debounce(int PIN_P, int PIN_N, int* yes_conf_pnt, int * no_conf_pnt, int CONFIDENCE_LEVEL){
    /*
    THIS FUNCTION TRIES TO ELIMINATE BUTTON DEBOUNCING
    @param int PIN_P. The port in use.
    @param int PIN_N. The pin number.
    @param int* yes_conf_pnt. Pointer to confidence of button being pressed
    @param int* no_conf_pnt. Pointer to confidence of button being released
    @param int CONFIDENCE_LEVEL. 

    @return int. 1 if we are confident button was pressed. 2 if we are confident 
    the button has been released. 0 otherwise
    */

   // Confidence of button being pressed
   int yes_conf= *yes_conf_pnt;
   // Confidence of button being released
   int no_conf= *no_conf_pnt;

   // Return value
   int ret_val= 0;

   // Check if PIN_PPIN_N is HIGH (Button Pressed)
   if( bit_is_clear(PIN_P, PIN_N) ){
       
       // Increase yes confidence
       yes_conf ++;
       // Reset no confidence
       no_conf= 0;

       // If yes confidence is up to required confidence level
       if( yes_conf >= CONFIDENCE_LEVEL ){
           // Reset confidence level
           yes_conf= 0;
           // Return true
           ret_val= 1;
       }

   }
   // If PIN_PPIN_N is LOW (Button not pressed)
   else{

       // Increment no confidence
       no_conf ++;
       // Reset yes confidence
       yes_conf= 0;

       // If no confidence is up to required confidence level
       if( no_conf >= CONFIDENCE_LEVEL ){
           // Reset confidence level
           no_conf= 0;
           // Return false
           ret_val= 2;
       }
   }

    *yes_conf_pnt= yes_conf;
    *no_conf_pnt= no_conf;

   // Return zero
   return ret_val;

}
