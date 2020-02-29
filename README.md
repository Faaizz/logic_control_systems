# Logic Control Systems
Simplified industrial plants are modelled as finite state machines and implemented on Raspberry Pi using Python. Logic controllers are designed for these plants and implemented on Arduino UNO. An alternative implementation of the Logic Controllers as Programmable Logic Controllers (PLCs) is also carried out using openPLC. 
These components are then connected via the communication ports of the Pi and the Arduino, and real-time industrial activities can be simulated! 

_As a possible future extension, fault states & transitions may be added to the plants and dignosis systems may be incorporated to tckle these._

------------------------------------------------------------------------------------
#### Simplified Industrial Plants
Basic industrial plants are simplified and modelled as fiinite state machines. They are implemented on a Raspberry Pi using the Python programming language. 
The choice of using the Raspberry Pi is due to the ease of communicating with the logic controller via it's general purpose input/output (GPIO) ports.

------------------------------------------------------------------------------------
#### Logic Controllers
The logic controllers are designed as finite state machines and the designed controllers are validated and verified using [NuSMV](http://nusmv.fbk.eu/). Then they are implemented on an Arduino UNO in plain C/C++ code and also as PLCs using the [openPLC software](https://www.openplcproject.com/).

------------------------------------------------------------------------------------
