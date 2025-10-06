x = list((1, 2, 3, 4))
y = tuple([1, 2, 3, 4])
print(x)
print(y)

z = list("Hello")
print(z)

x = (3, 1, 4, 2)
y = list(x)
y.sort()
x = tuple(y)
print(x)