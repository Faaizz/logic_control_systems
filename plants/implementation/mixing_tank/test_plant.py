#!/usr/bin/python3

from plant import Plant

plant= Plant()

def print_status(plant):
    """Print plant status"""
    print("Tank percentage: " + str(plant.tank_l_l))
    print("Mix percentage: " + str(plant.mix_p))
    print('\n')

print_status(plant)

print("Open valves 1 and 3")
plant.update(V1=1, V3=1)
print_status(plant)

print("Open valves 1 and 2")
plant.update(V1=1, V2=1)
print_status(plant)

print('Fill Tank')
while not plant.ls_2:
    plant.update(V1=1, V2=1)
print_status(plant)

print('Mix tank')
while plant.mix_p < 100:
    plant.update(M=1)
print_status(plant)

print('Empty tank')
while plant.ls_1:
    plant.update(V3=1)
print_status(plant)