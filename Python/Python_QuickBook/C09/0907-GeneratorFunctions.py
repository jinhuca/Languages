def four():
  x = 0
  while x < 4:
    print("in generator, x =", x)
    yield x
    x += 1

for i in four():
  print(i)
