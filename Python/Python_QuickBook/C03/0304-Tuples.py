# Tuples are similar to lists but are immutable - that is, they can't be modified after created.
from typing import List


x = ()
print(x)
x = (1,)                # one element tuple needs a comma
print(x)                
x = (1, 2, 3, 4, 5, 6)
print(x)

# convert list to tuple
x = [1, 2, 3, 4]
tuple(x)
print(x)

# convert tuple to list
y = (1, 2, 3, 4)
list(y)
print(y)
