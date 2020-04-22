TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM mixing_tank
  VAR
    B1 : BOOL;
    B2 : BOOL;
    LS_1 : BOOL;
    LS_2 : BOOL;
    V1 : BOOL;
    V2 : BOOL;
    V3 : BOOL;
    M : BOOL;
  END_VAR
  VAR
    sus : USINT := 0;
    T_5 : TON;
    T_temp : TOF;
    stable : BOOL := 1;
    P1 : BOOL := 1;
    P2 : BOOL := 0;
    P3 : BOOL := 0;
    P4 : BOOL := 0;
    P5 : BOOL := 0;
  END_VAR

              
  (* Timer Call *)
  T_5(IN:= P3, PT:= T#15000ms);
  (*Introduced to eliminate false LOW in sensor LS_1*)
  T_temp(IN:= LS_1, PT:= T#200ms);

  (* TRANSITIONS *)

    (*t1*)
    IF P1 AND NOT P2 AND B1 AND NOT LS_2 THEN
      P1:= 0;
      P2:= 1;
      stable:= 0;
    END_IF;
    
    (*t2*)
    IF P1 AND NOT P3 AND B1 AND LS_2 THEN
      P1:= 0;
      P3:= 1;
      stable:= 0;
    END_IF;
    
    (*t3*)
    IF P2 AND NOT P3 AND LS_2 AND NOT B2 THEN 
      P2:= 0;
      P3:= 1;
      stable:= 0;
    END_IF;
    
    (*t4*)
    IF P3 AND NOT P4 AND T_5.Q AND NOT B2 THEN 
      P3:= 0;
      P4:= 1;
      stable:= 0;
    END_IF;
    
    (*t5*)
    IF P2 AND NOT P5 AND B2 THEN
      P2:= 0;
      P5:= 1;
      sus:= 1;
      stable:= 0;
    END_IF;
    
    (*t6*)
    IF P5 AND NOT P2 AND B1 AND sus=1 THEN 
      P5:= 0;
      P2:= 1;
      stable:= 0;
    END_IF;
    
    (*t7*)
    IF P3 AND NOT P5 AND B2 THEN 
      P3:= 0;
      P5:= 1;
      sus:= 2;
      stable:= 0;
    END_IF;
    
    (*t8*)
    IF P5 AND NOT P3 AND B1 AND sus=2 THEN
      P5:= 0;
      P3:= 1;
      stable:= 0;
    END_IF;
    
    (*t9*)
    IF P4 AND NOT P5 AND B2 THEN
      P4:= 0;
      P5:= 1;
      sus:= 3;
      stable:= 0;
    END_IF;
    
    (*t10*)
    IF P5 AND NOT P4 AND B1 AND sus=3 THEN
      P5:= 0;
      P4:= 1;
      stable:= 0;
    END_IF;
    
    (*t11*)
    IF P4 AND NOT P1 AND NOT T_temp.Q AND NOT B2 THEN
      P4:= 0;
      P1:= 1;
      stable:= 0;
    END_IF;


  (* OUTPUTS *)

  (*P1/P5*)
  IF P1 OR P5 THEN
    V1:= 0;
    V2:= 0;
    V3:= 0;
    M:= 0;
  END_IF;

  (*P2*)
  IF P2 THEN
    V1:= 1;
    V2:= 1;
    V3:= 0;
    M:= 0;
  END_IF;

  (*P3*)
  IF P3 THEN
    V1:= 0;
    V2:= 0;
    V3:= 0;
    M:= 1;
  END_IF;

  (*P4*)
  IF P4 THEN
    V1:= 0;
    V2:= 0;
    V3:= 1;
    M:= 0;
  END_IF;








END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : mixing_tank;
  END_RESOURCE
END_CONFIGURATION
