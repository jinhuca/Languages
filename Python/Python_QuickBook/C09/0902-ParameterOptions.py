# Positional parameters
def power(x, y=2):            # default parameter: y=2
  r = 1
  while y > 0:
    r = r * x
    y = y - 1
  return r

print(power(3, 3))
print(power(x=3, y=4))        # passing arguments by parameter name

# Variable numbers of arguments
def maximum(*numbers):
  if len(numbers) == 0:
    return None
  else:
    maxnum = numbers[0]
    for n in numbers[1:]:
      if n > maxnum:
        maxnum = n
    return maxnum

print(maximum(3, 2, 8, 4))