void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void MIXING_TANK_init__(MIXING_TANK *data__, BOOL retain) {
  __INIT_VAR(data__->B1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LS_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LS_2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->V1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->V2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->V3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SUS,0,retain)
  TON_init__(&data__->T_5,retain);
  TOF_init__(&data__->T_TEMP,retain);
  __INIT_VAR(data__->STABLE,1,retain)
  __INIT_VAR(data__->P1,1,retain)
  __INIT_VAR(data__->P2,0,retain)
  __INIT_VAR(data__->P3,0,retain)
  __INIT_VAR(data__->P4,0,retain)
  __INIT_VAR(data__->P5,0,retain)
}

// Code part
void MIXING_TANK_body__(MIXING_TANK *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->T_5.,IN,,__GET_VAR(data__->P3,));
  __SET_VAR(data__->T_5.,PT,,__time_to_timespec(1, 15000, 0, 0, 0, 0));
  TON_body__(&data__->T_5);
  __SET_VAR(data__->T_TEMP.,IN,,__GET_VAR(data__->LS_1,));
  __SET_VAR(data__->T_TEMP.,PT,,__time_to_timespec(1, 200, 0, 0, 0, 0));
  TOF_body__(&data__->T_TEMP);
  if ((((__GET_VAR(data__->P1,) && !(__GET_VAR(data__->P2,))) && __GET_VAR(data__->B1,)) && !(__GET_VAR(data__->LS_2,)))) {
    __SET_VAR(data__->,P1,,0);
    __SET_VAR(data__->,P2,,1);
    __SET_VAR(data__->,STABLE,,0);
  };
  if ((((__GET_VAR(data__->P1,) && !(__GET_VAR(data__->P3,))) && __GET_VAR(data__->B1,)) && __GET_VAR(data__->LS_2,))) {
    __SET_VAR(data__->,P1,,0);
    __SET_VAR(data__->,P3,,1);
    __SET_VAR(data__->,STABLE,,0);
  };
  if ((((__GET_VAR(data__->P2,) && !(__GET_VAR(data__->P3,))) && __GET_VAR(data__->LS_2,)) && !(__GET_VAR(data__->B2,)))) {
    __SET_VAR(data__->,P2,,0);
    __SET_VAR(data__->,P3,,1);
    __SET_VAR(data__->,STABLE,,0);
  };
  if ((((__GET_VAR(data__->P3,) && !(__GET_VAR(data__->P4,))) && __GET_VAR(data__->T_5.Q,)) && !(__GET_VAR(data__->B2,)))) {
    __SET_VAR(data__->,P3,,0);
    __SET_VAR(data__->,P4,,1);
    __SET_VAR(data__->,STABLE,,0);
  };
  if (((__GET_VAR(data__->P2,) && !(__GET_VAR(data__->P5,))) && __GET_VAR(data__->B2,))) {
    __SET_VAR(data__->,P2,,0);
    __SET_VAR(data__->,P5,,1);
    __SET_VAR(data__->,SUS,,1);
    __SET_VAR(data__->,STABLE,,0);
  };
  if ((((__GET_VAR(data__->P5,) && !(__GET_VAR(data__->P2,))) && __GET_VAR(data__->B1,)) && (__GET_VAR(data__->SUS,) == 1))) {
    __SET_VAR(data__->,P5,,0);
    __SET_VAR(data__->,P2,,1);
    __SET_VAR(data__->,STABLE,,0);
  };
  if (((__GET_VAR(data__->P3,) && !(__GET_VAR(data__->P5,))) && __GET_VAR(data__->B2,))) {
    __SET_VAR(data__->,P3,,0);
    __SET_VAR(data__->,P5,,1);
    __SET_VAR(data__->,SUS,,2);
    __SET_VAR(data__->,STABLE,,0);
  };
  if ((((__GET_VAR(data__->P5,) && !(__GET_VAR(data__->P3,))) && __GET_VAR(data__->B1,)) && (__GET_VAR(data__->SUS,) == 2))) {
    __SET_VAR(data__->,P5,,0);
    __SET_VAR(data__->,P3,,1);
    __SET_VAR(data__->,STABLE,,0);
  };
  if (((__GET_VAR(data__->P4,) && !(__GET_VAR(data__->P5,))) && __GET_VAR(data__->B2,))) {
    __SET_VAR(data__->,P4,,0);
    __SET_VAR(data__->,P5,,1);
    __SET_VAR(data__->,SUS,,3);
    __SET_VAR(data__->,STABLE,,0);
  };
  if ((((__GET_VAR(data__->P5,) && !(__GET_VAR(data__->P4,))) && __GET_VAR(data__->B1,)) && (__GET_VAR(data__->SUS,) == 3))) {
    __SET_VAR(data__->,P5,,0);
    __SET_VAR(data__->,P4,,1);
    __SET_VAR(data__->,STABLE,,0);
  };
  if ((((__GET_VAR(data__->P4,) && !(__GET_VAR(data__->P1,))) && !(__GET_VAR(data__->T_TEMP.Q,))) && !(__GET_VAR(data__->B2,)))) {
    __SET_VAR(data__->,P4,,0);
    __SET_VAR(data__->,P1,,1);
    __SET_VAR(data__->,STABLE,,0);
  };
  if ((__GET_VAR(data__->P1,) || __GET_VAR(data__->P5,))) {
    __SET_VAR(data__->,V1,,0);
    __SET_VAR(data__->,V2,,0);
    __SET_VAR(data__->,V3,,0);
    __SET_VAR(data__->,M,,0);
  };
  if (__GET_VAR(data__->P2,)) {
    __SET_VAR(data__->,V1,,1);
    __SET_VAR(data__->,V2,,1);
    __SET_VAR(data__->,V3,,0);
    __SET_VAR(data__->,M,,0);
  };
  if (__GET_VAR(data__->P3,)) {
    __SET_VAR(data__->,V1,,0);
    __SET_VAR(data__->,V2,,0);
    __SET_VAR(data__->,V3,,0);
    __SET_VAR(data__->,M,,1);
  };
  if (__GET_VAR(data__->P4,)) {
    __SET_VAR(data__->,V1,,0);
    __SET_VAR(data__->,V2,,0);
    __SET_VAR(data__->,V3,,1);
    __SET_VAR(data__->,M,,0);
  };

  goto __end;

__end:
  return;
} // MIXING_TANK_body__() 





