import numpy as np

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
    