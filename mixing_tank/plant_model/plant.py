#!/usr/bin/python3

class Plant:
    
    def __init__(self, tank_l_l=0, mix_p=0):
        """Constructor"""

        # Tank liquid level
        self.tank_l_l= tank_l_l

        # Tank liquid mix percentage
        self.mix_p= mix_p

        # Update sensor values
        self.update_sensors()

        # Initialize error
        self.error= 0;


    def update_sensors(self):
        """Update tank sensor values"""

        # Empty sensor
        if (self.tank_l_l < 10):
            self.ls_1= 0
        else:
            self.ls_1= 1

        # Full sensor
        if (self.tank_l_l > 90):
            self.ls_2= 1
        else:
            self.ls_2= 0

        # If tank is empty, reset mix percentage
        if not self.ls_1:
            self.mix_p= 0


    def valve(self, operation):
        """ Update the tank level based on the valve signals.
            Number operation: if < 0, an outlet valve is open. if > 0, an inlet valve is open. 
        """
        self.update_sensors()

        if (operation<0 and self.ls_1 != 0):
            # Outlet valve
            self.tank_l_l-= 15

        if (operation>0 and self.ls_2 != 1):
            # Inlet valve
            self.tank_l_l+= 10

        # Limit lower tank level
        if self.tank_l_l < 0:
            self.tank_l_l= 0;

        # Limit upper tank level
        if self.tank_l_l > 100:
            self.tank_l_l= 100


    def mix(self):
        """ Update tank liquid mix percentage """
        self.update_sensors()

        if self.ls_1 == 0:
            self.error= 1
        else:
            self.mix_p+= 15

        # Limit miz percentage to 100
        if self.mix_p > 100:
            self.mix_p= 100


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