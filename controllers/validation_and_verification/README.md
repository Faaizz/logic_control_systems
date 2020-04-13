## Validation and Verification

Validation and Verification of designed logic controllers are performed using the NuSMV symbolic model verification framework.

------------------------------------------------------------
### Computation Temporal Logic (CTL) Model Checking
The controller logic is specified in NuSMV language and its specifications are specified in CTL formulas. To perform verification for a single controller run:
```bash
./NuSMV/bin/NuSMV plant_name_smv.smv
```

------------------------------------------------------------------------------------
1- [NuSMV](http://nusmv.fbk.eu)
