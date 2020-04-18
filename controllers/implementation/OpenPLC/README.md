### Controller- OpenPLC

OpenPLC is an open source Programmable Logic Controller (PLC) tool [1]. In this project, the OpenPLC runtime software is run on a host PC and interfaces with the plant (RPi model) through the ports of an Arduino UNO. This is made possible by configuring the Arduino UNO as a slave device to OpenPLC program.   

Supervision of the controller functionality is performed using ScadaBR. ScadaBR is an open source Supervisory Control and Data Acquisition (SCADA) system that can be used to provide Human Machine Interface (HMI) [2]. In this project, ScadaBR is run as a virtual machine on the host PC that runs the OpenPLC runtime.  

A rundown of required steps is given below:
- Implement controller logic in OpenPLC Editor.
- Install and launch OpenPLC runtime on host PC.
- Configure Arduino UNO as slave device.
- Setup and launch ScadaBR on host PC.


---------------------------------------------------------------------------
#### Setting up ScadaBR with OpenPLC runtime via Modbus IP

**Note:** To get an IP that works from the ScadaBR virtual machine, it might be required to setup a local network.

- **Add Data Source**: Add a new data source of type *Modbus IP* with it's Host set to the IP address of the running OpenPLC runtime, make sure to "Start PLC" on the OpenPLC interface. A couple of settings that seemed to work well can be found in this detailed post by @astang on the OpenPLC community discussion board [3]. The gist of it is:  
  ```
  Update period: 1 second
  Timeout: 5000
  Retries: 200
  Transporttype: "TCP with keep-alive"
  ```

- **Add Data Points**: Data points can be configured for the added data source. The I/O address mapping on OpenPLCS runtime is mapped to the Modbus address space as shown in [4]. The mapping ends at %IX99.7 and %QX99.7 for digital input and output addresses respectively. Although, slave addresses start from position 100 (e.g. %IX100.0), the mapping is easily extensible.  
  
  | PLC Address         | Modbus Address    | ScadaBR Register      |
  | -----------------   | ---------------   | -----------------     |
  | %IX100.0            | 800               | Input status          |
  | %IX101.3            | 903               | Input status          |
  | %QX100.2            | 802               | Coil status           |
  | %QX101.0            | 900               | Coil status           |


    
    

      

------------------------------------------------------------------------------------
#### References
1- [OpenPLC](https://www.openplcproject.com/getting-started).  
2- [OpenPLC- Installing ScadaBR](https://www.openplcproject.com/reference-installing-scadabr).  
3- [My First Project- OpenPLC Community](https://openplc.discussion.community/post/my-first-project-9671952).
4- [OpenPLC- Modbus Address Mapping](https://www.openplcproject.com/scada).