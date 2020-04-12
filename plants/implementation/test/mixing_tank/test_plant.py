
import unittest, sys

from src.mixing_tank.mixing_tank import MixingTank

class TestPlant(unittest.TestCase):

    def setUp(self):
        self.mixing_tank= MixingTank()

    def test_initialization(self):
        # Upon initialization, liquid level and mix percentage should be zero
        # Assert liquid level
        self.assertEqual(self.mixing_tank.t_l_l, 0) 
        # Assert mix percentage
        self.assertEqual(self.mixing_tank.m_p, 0) 

    def test_valves(self):
        # Open valves V1 and V2 each fill 1% per operation cycle
        # Valve V3 drains 1.5% per operation cycle
        
        # V1
        self.mixing_tank.update(V1=1)
        # Assert that t_l_l= 1
        exp= 1
        self.assertEqual(self.mixing_tank.t_l_l, exp)
        
        # V2
        self.mixing_tank.update(V2=1)
        # Assert that t_l_l has increased by 1%
        exp= exp+1
        self.assertEqual(self.mixing_tank.t_l_l, exp)

        # V3
        self.mixing_tank.update(V3=1)
        # Assert that t_l_l has not reduced by 1.5%
        # Beacuse 2% still falls within the category of an empty tank (<10%)
        # And should not be drained
        self.assertEqual(self.mixing_tank.t_l_l, exp)

        # self.mixing_tank.print()

    def test_tank_fill_mix_and_empty(self):

        # Fill the tank
        while not self.mixing_tank.ls_2:
            self.mixing_tank.update(V1=1, V2=1)
        
        # Assert that tank is full
        self.assertTrue( (self.mixing_tank.t_l_l > 95) )

        # Mix the tank- With mixer ON, mix percentage increases by 1.5% per operation cycle
        exp= 0
        # Mix tank for 10 op cycles
        for idx in range(10):
            self.mixing_tank.mix()
            exp= exp+1.5
            
        # Assertion
        self.assertEqual(self.mixing_tank.m_p, exp)

        # Empty the tank
        while self.mixing_tank.ls_1:
            self.mixing_tank.update(V3=1)

        # Assert that tank is empty
        self.assertTrue( (self.mixing_tank.t_l_l < 10) )

        # self.mixing_tank.print()
