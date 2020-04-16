### Circuit Components

1- **Raspberry Pi(RPi) 4**: The GPIO pins use 3.3v logic levels and current flow into or out of them should be limited to within 2mA and 16mA.  

1- **BC547 Transistor**: This is an NPN Transistor. The pins are labelled Emitter (E), Base (B), Collector (C) from right to left with the transistor standing on its legs and its flat face towards the observer. The transistor is used as an electronic button which conducts current from C to E when current flows into B. To keep the current flow through the RPi's GPIO ports limited within the allowed range- let's use 5mA, we need to configure the transistor biases appropriately.  

We know V_c= 3.3V (from RPi's GPIO), and V_b= 3V (from ATMega328P output pin) by consulting the *BC547* datasheet, we can select $I_B < 50uA by selecting R_B >= 60kOhm.  


------------------------------------------------------------
### References
1- [circuits.dk- Everything about Raspberry GPIO](https://www.circuits.dk/everything-about-raspberry-gpio/)