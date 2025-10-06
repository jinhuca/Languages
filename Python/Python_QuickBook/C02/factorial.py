def factorial(n):
    r = 1
    while n > 0:
        r = r * n
        n = n - 1
    return r

print(factorial(6))

x = 3 + 2j
y = 2 + 3j
print(x + y)