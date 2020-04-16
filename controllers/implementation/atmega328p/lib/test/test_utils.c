# include <assert.h>
# include <stdio.h>

#include "./dummy.c"
#include "../utils.c"


int main(void){

    
    // Pin port
    int PIN_P= 66;
    // Pin number
    int PIN_N= 0;
    // Pressed confidence
    int yes_conf= 0;
    // Released confidence
    int no_conf= 0;
    // Is button pressed?
    int pressed= 0;

    // Test Button Pressed
    for(int idx=0; idx<1000; idx++){
        pressed= button_debounce(PIN_P, PIN_N, &yes_conf, &no_conf, 500);

    }
    // Assert pressed
    printf("%d %d %d", yes_conf, no_conf, pressed);
    assert(pressed == 1);


    // // Simulate button press
    // pressed= 1;
    // // Test Button Released
    // for(int idx=0; idx<1000; idx++){
    //     pressed= button_debounce(PIN_P, PIN_N, &yes_conf, &no_conf, 500);

    // }
    // // Assert released
    // printf("%d %d %d", yes_conf, no_conf, pressed);
    // assert(pressed == 2);



}