x = [3, 8, 4, 0, 2, 1]
x.sort()
print(x)

x = [2, 4, 1, 3]
y = x[:]
y.sort()
print(y)
print(x)

x = ["Life", "Is", "Enchanting"]
x.sort()
print(x)

x = [1, 2, 'hello', 3]
# x.sort()      # throw exception

x = [[3, 5], [2, 9], [2, 3], [4, 1], [3, 2, 4]]
x.sort()
print(x)

# Custom sorting
def compare_num_of_chars(string1):
    return len(string1)
word_list = ['Python', 'is', 'better', 'than', 'C']
word_list.sort()
print(word_list)
word_list.sort(key=compare_num_of_chars)
print(word_list)

# sorted function
x = [4, 3, 1, 2]
y = sorted(x)
print(y)
z = sorted(x, reverse=True)
print(z)
print(x)