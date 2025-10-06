var1 = 1
var2 = 2
print("var1 - ", var1, "var2 - ", var2)
var2, var1 = var1, var2
print(var1, var2)
print("var1 - ", var1, "var2 - ", var2)

def pairwise_sum(list1, list2):
    result = []
    for i in range(len(list1)):
        result.append(list1[i] + list2[i])
    return result

list1 = [1, 2, 3]
list2 = [9, 8, 7]
print(pairwise_sum(list1, list2))

x = "2"
print(type(x), x)
x = int(x)
print(type(x), x)
