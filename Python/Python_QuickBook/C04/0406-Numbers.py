print(5 + 2 - 3 * 2)
print(5 / 2)                        # floating-point result with normal division
print(5 / 2.0)                      # also a floating-point result
print(5 // 2)                       # integer result with truncation when divided using '//'

print(30000000000000)               # This would be too large to be an int in many languages
print(30000000000000 * 3.0)

print(2.0e-8)                       # Scientific notation gives back a float
print(30000000 * 30000000)          

print(int(200.3))
print(int(2e3))
print(float(200))

# Built-in numeric functions: abs, divmod, float, hex, int, max, min, oct, pow, round
print(abs(-1.234))
print(divmod(5, 2))
print(float(321))
print(hex(100), oct(100))

# Advanced numeric functions:
from math import *
print(acos(0.1))

# Numeric computation

# Complex Numbers

# Advanced complex-number functions

import cmath
print(cmath.sqrt(-1))