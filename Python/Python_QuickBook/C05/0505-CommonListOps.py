# List membership with the in operator
print(3 in [1, 3, 4, 5])
print(3 not in [1, 3, 4, 5])
print(3 in ["one", "two", "three"])
print(3 not in ["one", "two", "three"])

# List concatenation with the + operator
z = [1, 2, 3] + [4, 5]
print(z)

# List initialization with the * operator
z = [None] * 4
print(z)
z = [3, 1] * 2
print(z)

# List minimum or maximum with min and max
print(min([3, 7, 0, -2, 11]))

# List search with index
x = [1, 3, "five", 7, -2]
print(x.index(7))
# print(x.index(5))

# List matches with count
x = [1, 2, 2, 3, 5, 2, 5]
print(x.count(2))
print(x.count(5))
print(x.count(4))

print(len([[1, 2]]*3))