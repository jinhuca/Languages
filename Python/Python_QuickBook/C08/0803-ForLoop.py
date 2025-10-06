x = [1, 3, -7, 4, 9, -5, 4]
for i in range(len(x)):
  if x[i] < 0:
    print("Found a negative number at index", i)

x = [1, 2, 3, 4]
y = ['a', 'b', 'c', 'd', 'e']
z = zip(x, y)
print(list(z))