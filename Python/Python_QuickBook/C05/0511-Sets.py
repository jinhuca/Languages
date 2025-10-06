x = set([1, 2, 3, 1, 3, 5])
print(x)
x.add(6)
print(x)

x = set([1, 2, 5, 1, 0, 2, 3, 1, 1, (1, 2, 3)])
print(x, len(x))
print(4 in x)