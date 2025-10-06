# Lists: A list can contain a mixture of other types as its elements, including strings, tuples, lists, dictionaries,
# functions, file objects, and any type of number.

a = []
b = [1]
c = [1, 2, 3, 4, 5, 6, 7]
d = [1, "two", 3, 4.0, ["a", "b"], (5, 6)]

x = ["first", "second", "third", "fourth"]

# indices: zero-started index
print(x[2])
print(x[-1])

# slices
print(x[1:-1])
print(x[-2:-1])
print(x[0:3])
print(x[:3])
print(x[3:])
print(x[-2:])

x = [1, 2, 3, 4, 5, 6, 7, 8, 9]

x[1] = "two"
x[8:9] = []
print(x)
x[5:7] = [6.0, 6.5, 7.0]
print(x)
