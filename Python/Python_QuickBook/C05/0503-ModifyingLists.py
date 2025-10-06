x = [1, 2, 3, 4]
x[1] = "two"
print(x)

x = [1, 2, 3, 4]
x[len(x):] = [5, 6, 7]      # Appends list to end of list
print(x)

x[:0] = [-1, 0]             # Appends list to front of list
print(x)

x[1:-1] = []                # Removes elements from list
print(x)

x = [1, 2, 3]
x.append("fourth")
print(x)

x = [1, 2, 3, 4]
y = [5, 6, 7]
x.append(y)
print(x)

x = [1, 2, 3, 4]
y = [5, 6, 7]
x.extend(y)
print(x)

x = [1, 2, 3]
x.insert(2, "hello")
print(x)
x.insert(0, "start")
print(x)