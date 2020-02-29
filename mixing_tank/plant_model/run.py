#!/usr/bin/python3

import numpy as np

from time import sleep

from gpiozero import Button
from gpiozero import LED

from plant import Plant


# CONFIGURE INPUTS

# Configure Valve 1 on GPIO 26
V1_input= Button(26)
# Configure Valve 3 on GPIO 21
V3_input= Button(21)
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


def binary_stream_prep(number):
    """ Prepares a number into the required format for binary stream transfer for this project
        Only the first 2 digits are transmitted-  a zero is appended to the end.
        e.g:    80 is transmitted as 8
                75 is transmitted as 8 also (7.5~= 8)
                10 is transmitted as 1
    """
    # Number must not exceed 100
    if number > 100:
        number= 100
    
    # Take out last digit
    number= round(number/10)
    # Convert to binary string
    bin_num= bin(number)
    # Cut off the '0b' at beginning of string
    bin_num= bin_num.lstrip('0b')
    # Ensure string is of 4 characters, if not, left fill it with zeros
    while len(bin_num) < 4:
        bin_num= '0' + bin_num
    
    # Return list of 0s and 1s
    result= np.array(np.zeros(4), dtype=np.int64);
    for idx in range(0, len(bin_num)):
        result[idx]= int(bin_num[idx])

    return result
    

# Initialize Plant
plant= Plant()
    
# Forever loop
while True:
    
    # Read inputs
    # V1
    if V1_input.is_pressed:
        V1= 1
    # V2
    if V3_input.is_pressed:
        V3= 1
    # M
    if M_input.is_pressed:
        M= 1

    plant.update(V1=V1, V3=V3, M=M)

    # Set outputs
    # ls_1
    if plant.ls_1:
        ls_1_led.on()
    else:
        ls_1_led.off()

    # ls_2
    if plant.ls_2:
        ls_2_led.on()
    else:
        ls_2_led.off()

    # Tank liquid level
    ll= binary_stream_prep(plant.tank_l_l)
    ll_0, ll_1, ll_2, ll_3= ll

    # Tank mix percentage
    mp= binary_stream_prep(plant.mix_p)
    mp_0, mp_1, mp_2, mp_3= mp

    #Set period to 1 second
    sleep(1)
    