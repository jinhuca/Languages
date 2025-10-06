def fact(n):
  """Return the factorial of the given number."""
  r = 1
  while n > 0:
    r = r * n
    n = n - 1
  return r

print(fact(6))