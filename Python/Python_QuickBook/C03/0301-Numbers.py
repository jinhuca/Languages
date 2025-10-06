## Numbers: Python's four number types are integers, floats, complex numbers, Booleans.

# Integers: integers aren't limited in size except by available memory
x = 1
y = 999999999999
z = -77777777777
print(z)

print(x, y)
print(5 / 2)        # / results in a float => 2.5
print(5 // 2)       # // integer division => 2
print(5 % 2)        # modulo => 1
print(5 ** 2)       # exponentiation
print(4.3 * 2.4)    

# Complex Numbers
a = 3 + 7j
b = 4 + 2j
print(a.real)
print(a.imag)
print(a + b)
print(a * b)
print(a ** b)
print(100000000000001 ** 3)

# Built-in functions
print(round(3.14))
print(round(3.51))
import math
print(math.ceil(3.14))

print(((3+2j)**(2+3j)).real)
print(((3+2j)**(2+3j)).imag)