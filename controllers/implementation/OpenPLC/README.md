### Controller- OpenPLC

OpenPLC is an open source Programmable Logic Controller (PLC) tool. In this project, the OpenPLC runtime software is run on a host PC and interfaces with the plant (RPi model) through the ports of an Arduino UNO. This is made possible by configuring the Arduino UNO as a slave device to OpenPLC program.   

Supervision of the controller functionality is performed using ScadaBR. ScadaBR is an open source Supervisory Control and Data Acquisition (SCADA) system that can be used to provide Human Machine Interface (HMI). In this project, ScadaBR is run as a virtual machine on the host PC that runs the OpenPLC runtime.  

A rundown of required steps is given below:
- Implement controller logic in OpenPLC Editor.
- Install and launch OpenPLC runtime on host PC.
- Configure Arduino UNO as slave device.
- Setup and launch ScadaBR on host PC.


