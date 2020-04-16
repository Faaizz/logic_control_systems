### Controller- ATMega328P

The ATMega328P is a single-chip microcontroller created by Atmel in the megaAVR family. It has a modified Harvard architecture 8-bit RISC processor core [1]. For implementation of logic controllers in this project, C programming language would be used.  
Implementation of a logic controller on an Atmel AVR ATMega328P microcontroller requires the following steps:  
- Write the controller logic as C code.  
- Compile and link the C code (e.g. with *avr-gcc*)  
- Convert the executable binary file (*.elf*) to hexadecimal file object format (*.hex*).  
- Flash the *.hex* file onto the ATMega382P board

---------------------------------------------------------------------------
#### Writing the controller logic as C code

- **avr/io.h**: Contains on information about the AVR microcontrollers. Makes it possible for the program to understand register information such as DDR (Data Direction Register) and PORT.

```C
#include <avr/io.h>
```

- **Data Direction Register (DDR)**: The DDR is used to control the direction of data through the pins of a port. A HIGH value signifies data output while a LOW equals data input.

```C
// Set pin0 of portB to data output mode 
DDRB = 0b00000001;
```

- **PORT Register**: The PORT rregister is used to set the value of a pin (HIGH/LOW). An HIGH value gives 5v through the pin (if it's configured to output data).

```C
// Set pin3 of portD HIGH
PORTD |= 1 << PIND3;

// Set D5 LOW
PORTD &= ~( 1 << PIND5 );
```

- **util/delay.h**: Provides convenient methods to create delays in programs. 
 
```C
#include <avr/io.h>
#include <util/delay.h>

int main(void){

    // Set pin5 of portA to output data
    DDRA |= 1 << PINA5;

    while(1){

        // Toggle the value of A5 HIGH/LOW
        PORTA ^= 1 << PINA5;

        // Delay for 100ms
        _delay_ms(100);

    }
}
```

- **Timers & Counters**: Timer and counter functions generally count in sync with the microcontroller clock. However, since there are only 2 
counter registers- one 8-bit and one 16-bit- which can count up to 256 and 65535 respectively while the microcontroller counts at 1,000,000 ticks per second which none of the register can hold this lead to the introduction of prescalers. 
When a prescaler is set to a value, the counter function skips that number of ticks while counting. AVR microcontrollers allow prescaling values of 8, 64, 256, and 1024.  
Setting a prescaler of 256 for instance means in one second, the counter counts up to 1000000/256= 3906.25. Important timer/counter registers include:  
  

    1- *Timer/Counter Control Register (TCCR1)*: TCCR1 is the control register for the 16-bit timer (TCCR0 is the 8-bit version). TCCR1 is split into two 8-bit registers TCCR1A and TCCR1B.  
    2- *Timer/Counter Register (TCNT1)*: Is the 16-bit register that holds the count value for the 16-bit timer (TCNT0 is the 8-bit version).  
    3- *Output Compare Register (OCR1)*: Is the 16-bit register that holds the count value to match with TCNT1 in order to generate an interrupt.  
    4- *Timer/Counter Interrupt Mask Register (TIMSK)*: Turning on the OCIE1A switch informs the timer/counter that it's interrupt feature is being used.  

Timers can be used in normal mode or to generate interrupts.  

*NORMAL MODE* 
```C
// NORMAL MODE
#include <avr/io.h>

int main(void){

    // Set PINB5 to output mode
    DDRB |= 1 << PINB5;
    // Reset PORTB
    PORTB = 0b00000000;

    // Set prescaler to 256
    TCCR1B |= 1<<CS12 & ~(1<<CS11) & !(1<<CS10);

    while(1){
        // If 500ms= (1000000/256)/2= 1953.125 ticks has passed
        if( TCNT1 > 1953 ){
            TCNT1= 0;
            // Toggle PINB5
            PORTB ^= 1<<PINB5;
        }
    } 

}
```

*INTERRUPT MODE*
```C
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void){

    // Enable global interrupts
    sei();

    // Set PINB5 to output mode
    DDRB |= 1 << PINB5;
    // Reset PORTB
    PORTB = 0b00000000;

    // Set prescaler to 256 
    TCCR1B |= ( 1<<CS12 & ~(1<<CS11) & ~(1<<CS10) );
    // Enable interrupt mode
    TIMSK1 |= 1<<OCIE1A;
    // Set count value to match
    OCR1A= 1953;

    while(1){

    }
}

// INTERRUPT SERVICE ROUTINE
ISR(TIMER1_COMPA_vect){
    PORTB ^= 1<<PINB5;
}
```

---------------------------------------------------------------------------
#### Compiling and Linking with **avr-gcc**

```bash
avr-gcc -g -Os -mmcu=atmega328p -DF_CPU=16000000 *file.c* -o main.elf
```

---------------------------------------------------------------------------
#### Converting **.elf** to **.hex**

```bash
avr-objcopy -O ihex -R .eeprom main.elf main.hex
```

---------------------------------------------------------------------------
#### Flashing **.hex** onto ATMega328P-equipped Arduino Board using AVRDUDE

```Bash
sudo avrdude -p ATMEGA328P -c arduino -e -P /dev/ttyACM0 -U flash:w:main.hex
```

Where */dev/ttyACM0* should be replaces by the port via which the device is connected.


------------------------------------------------------------------------------------
#### References
1- [ATmega328- Wikipedia](https://en.wikipedia.org/wiki/ATmega328).  
2- [NewbieHack.com](https://www.newbiehack.com/MicrocontrollerIntroductionABeginnersGuidetotheAtmelAVRAtmega32.aspx).  
