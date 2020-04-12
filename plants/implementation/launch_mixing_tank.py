#!/usr/bin/python3

import sys
import numpy as np

from time import sleep

from gpiozero import Button
from gpiozero import LED

from src.mixing_tank.mixing_plant import MixingTank
from src.utils.util_functions import binary_stream_prep


#   I   N   I   T   I   A   L   I   Z   A   T   I   O   N
# Sample time
h= 5

#   C   O   N   F   I   G   U   R   A   T   I   O   N

# CONFIGURE INPUTS
# Configure Valve 1 on GPIO 21
V1_input= Button(21)
# Configure Valve 3 on GPIO 26
V3_input= Button(26)
# Configure Mixer on GPIO 20
M_input= Button(20)


# CONFIGURE OUTPUTS
# Configure Lower Sensor on GPIO 16
ls_1_led= LED(16)
# Configure Upper Level Sensor on GPIO 19
ls_2_led= LED(19)

# Configure Tank liquid level as a Binary Stream on GPIO 17, 27, 22, 18
# Bit 0
ll_0= LED(17)
# Bit 1
ll_1= LED(27)
# Bit 2
ll_2= LED(22)
# Bit 3
ll_3= LED(18)

# Configure Tank liquid mix percentage as a Binary Stream on GPIO 5, 6, 13, 12
# Bit 0
mp_0= LED(5)
# Bit 1
mp_1= LED(6)
# Bit 2
mp_2= LED(13)
# Bit 3
mp_3= LED(12)


# Initialize Plant
mixing_tank= MixingTank()
    
# Forever loop
while True:
    
    # Read inputs
    # V1
    if V1_input.is_pressed:
        V1= 1
        sys.stdout.write("{0:10}: {1:5}".format("V1", bool(V1)))
    # V3
    if V3_input.is_pressed:
        V3= 1
        sys.stdout.write("{0:10}: {1:5}".format("V3", bool(V3)))
    # M
    if M_input.is_pressed:
        M= 1
        sys.stdout.write("{0:10}: {1:5}".format("Mixer", bool(M)))

    mixing_tank.update(V1=V1, V3=V3, M=M)

    # Set outputs
    # ls_1
    if mixing_tank.ls_1:
        ls_1_led.on()
    else:
        ls_1_led.off()

    # ls_2
    if mixing_tank.ls_2:
        ls_2_led.on()
    else:
        ls_2_led.off()

    # Tank liquid level
    ll= binary_stream_prep(mixing_tank.t_l_l)
    ll_0, ll_1, ll_2, ll_3= ll

    # Tank mix percentage
    mp= binary_stream_prep(mixing_tank.m_p)
    mp_0, mp_1, mp_2, mp_3= mp

    # Print state to console
    self.print()

    #Set operatoin period to sample time
    sleep(h)
    