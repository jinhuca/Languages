x = ["first", "second", "third", "fourth"]
print(x[0], x[2], x[-1], x[-2])
print(x[1:-1])
print(x[-2:-1])

print(x[-1:2])      # empty list if second index before first index

print(x[:3])        # Go from the beginning of the list
print(x[2:])        # Go to the end of the list

y = x[:]            # Omitting both indices makes a new list, copies the list.
y[0] = "1 st"
print(y)
print(x)
z = x[0:1]
print(z)
z[0] = "0"
print(x)
print(z)