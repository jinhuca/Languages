a = [1, 2, 3]
b = a
c = b
b[1] = 5
print(a, b, c)
print(b)
print(c)

a = 1
b = a
c = b
b = 5
print(a, b, c)

# variables can be set to any object:
x = "Hello"
print(x)
x = 5           # A new assignment overrides any previous assignments.
print(x)

del x           # delete variable x
# print(x)      # error: name 'x' is not defined

print(a)
