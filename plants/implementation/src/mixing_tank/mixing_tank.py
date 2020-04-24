#!/usr/bin/python3

import sys

class MixingTank:
    
    def __init__(self, t_l_l=0, m_p=0):
        """Constructor"""

        # Tank liquid level
        self.t_l_l= t_l_l

        # Tank liquid mix percentage
        self.m_p= m_p

        # Update sensor values
        self.update_sensors()

        # Initialize error
        self.err= 0;


    def update_sensors(self):
        """Update tank sensor values"""

        # Empty sensor
        if (self.t_l_l < 10):
            self.ls_1= 0
        else:
            self.ls_1= 1

        # Full sensor
        if (self.t_l_l > 90):
            self.ls_2= 1
        else:
            self.ls_2= 0

        # If tank is empty, reset mix percentage
        if not self.ls_1:
            self.m_p= 0


    def valve(self, operation):
        """ Update the tank level based on the valve signals.
            Number operation: if < 0, an outlet valve is open. if > 0, an inlet valve is open. 
        """
        self.update_sensors()

        # Outlet valve
        if (operation<0):
            if (self.ls_1 != 0):
                # If tank is not empty
                self.t_l_l-= 1.5
            else:
                # Empty tank
                self.err= 1

        if (operation>0):
            # Inlet valve
            if (self.ls_2 != 1):
                # Tank is not full
                self.t_l_l+= 4
            else:
                # Tank is full
                # self.err= 1
                pass

        # Limit lower tank level
        # if self.t_l_l < 0:
        #     self.t_l_l= 0;

        # Limit upper tank level
        # if self.t_l_l > 100:
        #     self.t_l_l= 100


    def mix(self):
        """ Update tank liquid mix percentage """
        self.update_sensors()

        if self.ls_1 == 0:
            self.err= 1
        else:
            self.m_p+= 10

        # Limit mix percentage to 100
        if self.m_p > 100:
            self.m_p= 100


    def update(self, V1=0, V2=0, V3=0, M=0):
        """Update tank state due to input signals"""
        self.update_sensors()

        # Inlet valves
        if V1:
            self.valve(1)

        if V2: 
            self.valve(1)

        # Outlet valves
        if V3:
            self.valve(-1)

        # Mixer
        if M:
            self.mix()


    def print(self):

        level= "{0:10}: {1:5}".format("Level", self.t_l_l)
        mix= "{0:10}: {1:5}".format("Mix %", self.m_p)
        full= "{0:10}: {1:5}".format("Tank full", bool(self.ls_2))
        empty= "{0:10}: {1:5}".format("Tank empty", (not bool(self.ls_1)))
        error= "{0:10}: {1:5}".format("Error", bool(self.err))
        sys.stdout.write(level + "\n")
        sys.stdout.write(mix + "\n")
        sys.stdout.write(full + "\n")
        sys.stdout.write(empty + "\n")
        sys.stdout.write(error + "\n\n\n")

