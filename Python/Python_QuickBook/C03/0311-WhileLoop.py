u, v, x, y = 0, 0, 100, 30
while x > y:
  u = u + y
  x = x - y
  if x < y + 2:
    v = v + x
    x = 0
  else:
    v = v + y + 2
    x = x - y - 2
print(u, v)