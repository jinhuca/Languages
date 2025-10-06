m = [[0, 1, 2], [10, 11, 12], [20, 21, 22]]
print(m[0])
print(m[0][1])
print(m[2])
print(m[2][2])

nested = [0]
original = [nested, 1]
print(original)

nested[0] = 'zero'
print(original)
original[0][0] = 0
print(nested)
print(original)

nested = [2]
print(original)

original = [[0], 1]
shallow = original[:]
import copy
deep = copy.deepcopy(original)
print(deep)

shallow[1] = 2
print(shallow)
print(original)
shallow[0][0] = 'zero'
print(original)

deep[0][0] = 5
print(deep)
print(original)
