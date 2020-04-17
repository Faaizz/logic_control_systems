/**
 * This File holds the controller logic for the mixing_tank plant
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h> 

// STATE VARIABLE
// State variable- Initiallize to 0
int z= 0;
// Internal variable
int sus= 0;

int main(void){

    // CONFIGURE INTERRUPT
    // Enable global interrupt
    sei();
    // Set Prescaler to 256
    TCCR1B |= ( 1<<CS12 & ~(1<<CS11) & ~(1<<CS10) ) | 1<<WGM12;
    // Enable Interrupt Mode
    TIMSK1 |= 1<<OCIE1A;
    // Set Period micro seconds
    int h= 2000;
    OCR1A= (h/1000 * 3906) - 1;    


    // CONFIGURE INPUT PINS
    // Start Button
    DDRD |= ~(1<<PIND4);
    // Stop Button
    DDRD |= ~(1<<PIND5);
    // LS_1
    DDRD |= ~(1<<PIND3);
    // LS_2
    DDRD |= ~(1<<PIND2);

    // CONFIGURE OUTPUT PINS
    // V1 Actuator
    DDRB |= 1<<PINB0;
    // V2 Actuator
    DDRB |= 1<<PINB1;
    // V3 Actuator
    DDRB |= 1<<PINB2;
    // Mixer Motor Actuator
    DDRB |= 1<<PINB3;

    // Initialize all outputs to zero
    PORTB= 0b00000000;
    PORTD= 0b00000000;


    while(1){
        
    }


}

// INTERRUPT SERVICE ROUTINE
ISR(TIMER1_COMPA_vect){

    // PORTB ^= 1<<PINB0;

    // if(bit_is_clear(PIND, 3)){
    //     PORTB |= 1<<PINB0;
    // }else{
    //     PORTB &= ~(1<<PINB0);
    // }

    // CONTROLLER LOGIC
    // Lower sensor
    int ls_1= !bit_is_clear(PIND, 3);
    // Upper sensor
    int ls_2= !bit_is_clear(PIND, 2);
    // Start Button
    int b_1= !bit_is_clear(PIND, 4);
    // Stop Button
    int b_2= !bit_is_clear(PIND, 5);

    switch(z){
        case 0: // Set outputs
                // V1= 0
                PORTB &= ~(1<<PINB0);
                // V2= 0
                PORTB &= ~(1<<PINB1);
                // V3= 0
                PORTB &= ~(1<<PINB2);
                // M= 0
                PORTB &= ~(1<<PINB3);
                // Update state
                // To Z1
                z= (b_1 && !b_2 && !ls_2) ? 1 : z;
                // To Z2
                z= (b_1 && !b_2 && ls_2) ? 2 : z;
                
                break;

        case 1: // Set outputs
                // V1= 1
                PORTB |= 1<<PINB0;
                // V2= 1
                PORTB |= 1<<PINB1;
                // V3= 0
                PORTB &= ~(1<<PINB2);
                // M= 0
                PORTB &= ~(1<<PINB3);
                // Update state
                // To Z2
                z= (!b_2 && ls_2) ? 2 : z;
                // To Z4
                if( b_2 ){
                    z= 4;
                    sus= 1;
                }

                break;

        case 2: // Set outputs
                // V1= 0
                PORTB &= ~(1<<PINB0);
                // V2= 0
                PORTB &= ~(1<<PINB1);
                // V3= 0
                PORTB &= ~(1<<PINB2);
                // M= 0
                PORTB |= 1<<PINB3;
                // Update state
                // To Z4
                if( b_2 ){
                    z= 4;
                    sus= 2;
                }
                // To Z3
                // Delay for 5 seconds
                _delay_ms(5000);
                z= 3;

                break;

        case 3: // Set outputs
                // V1= 0
                PORTB &= ~(1<<PINB0);
                // V2= 0
                PORTB &= ~(1<<PINB1);
                // V3= 1
                PORTB |= 1<<PINB2;
                // M= 0
                PORTB &= ~(1<<PINB3);
                // Update state
                // To Z0
                z= (!b_2 && !ls_1) ? 0 : z;
                // To Z4
                if( b_2 ){
                    z= 4;
                    sus= 3;
                }

                break;

        case 4: // Set outputs
                // V1= 0
                PORTB &= ~(1<<PINB0);
                // V2= 0
                PORTB &= ~(1<<PINB1);
                // V3= 0
                PORTB &= ~(1<<PINB2);
                // M= 0
                PORTB &= ~(1<<PINB3);
                // Update state
                // To Z1
                z= (b_1 && sus==1) ? 1 : z;
                // To Z2
                z= (b_1 && sus==2) ? 2 : z;
                // To Z3
                z= (b_1 && sus==3) ? 3 : z;

                break;


    }


}
