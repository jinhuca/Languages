def funct1(x, y, z):
    value = x + 2 * y + z ** 2
    if value > 0:
        return x + 2 * y + z ** 2
    else:
        return 0

u, v = 3, 4
print(funct1(u, v, 2))
print(funct1(u, z = v, y = 2))