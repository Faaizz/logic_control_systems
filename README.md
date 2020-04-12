# Logic Control Systems
Simplified industrial plants are modelled as finite state machines and implemented on Raspberry Pi using Python. Logic controllers are designed for these plants and implemented on an ATMega828P microcontroller. An alternative implementation of the Logic Controllers as Programmable Logic Controllers (PLCs) is also carried out using OpenPLC.  
Using a Raspberry Pi and an ATMega828P equipped Arduino UNO, real-time industrial contorl processes can be simulated!  

_As a possible future extension, fault states & transitions may be added to the plants and dignosis systems may be incorporated to tackle these._  

------------------------------------------------------------------------------------
#### Simplified Industrial Plants
Basic industrial plants are simplified and [modelled](https://github.com/Faaizz/logic_control_systems/tree/master/plants/modelling) as finite state machines using Mathworks's Stateflow. Stateflow is a control logic tool used to model reactive systems via state machines and flow charts [1]. The simplified plants are [implemented](https://github.com/Faaizz/logic_control_systems/tree/master/plants/implementation) on a Raspberry Pi using the Python programming language. 
The choice of using the Raspberry Pi is due to the ease of communicating with the logic controller via it's general purpose input/output (GPIO) ports.  

------------------------------------------------------------------------------------
#### Logic Controllers
The logic controllers are [designed](https://github.com/Faaizz/logic_control_systems/tree/master/controllers/design) as finite state machines and the designed controllers are [validated and verified](https://github.com/Faaizz/logic_control_systems/tree/master/controllers/validation_and_verification) using [NuSMV](http://nusmv.fbk.eu/). Then they are [implemented](https://github.com/Faaizz/logic_control_systems/tree/master/controllers/implementation) on an ATMega828P using avr-libc package and also as PLCs using the [openPLC software](https://www.openplcproject.com/).

------------------------------------------------------------------------------------
#### Plants
The following plants are modelled:  
- [Mixing Tank]()


------------------------------------------------------------------------------------
### References
1- [Stateflow- Wikipedia](https://en.wikipedia.org/wiki/Stateflow)