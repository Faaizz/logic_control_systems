## Mixing Tank- Modelling

| Signal                | Symbol        | I/O   | Logic Statement           |
| --------------------- | ------------- | ----- | ---------------------     |
| Power                 | P             | I     | P=1; Power ON             |
| Valve 1 Actuator      | V1            | I     | V1= 1; Open Valve 1       |
| Valve 2 Actuator      | V2            | I     | V2= 1; Open Valve 2       |
| Valve 3 Actuator      | V3            | I     | V3= 1; Open Valve 3       |
| Mixer Motor Actuator  | M             | I     | M= 1; Turn ON Mixer       |
| Level Switch 1        | LS_1          | O     | LS_1= 0; Tank level < 10% |
| Level Switch 2        | LS_2          | O     | LS_2= 1; Tank level > 95% |
| Tank Liquid Level     | T_L_L         | O     | T_L_L= int;               |
| Mix Percentage        | M_P           | O     | M_P= int;                 |
| Error                 | err           | O     | err= 1; Error occurred    |


[Controller Design](../../../controllers/design/mixing_tank)

------------------------------------------------------------------------------------
### References
1- Logic Control Lecture Notes- Lehrstuhl für Automatisierungstechnik, Technische Universität Kaiserslautern. Prof. Dr. Ping Zhang.