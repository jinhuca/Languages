# Slice
tag = '<a href="http://www.python.org">Python web site</a>'
print(tag[9:30])
print(tag[32:-4])

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(numbers[3:6])
print(numbers[0:1])
print(numbers[:3])
print(numbers[:])
print(numbers[0:10:1])
print(numbers[0:10:2])
print(numbers[::2])

# Split up a URL of the form http://www.something.com

# url = input('Please enter the URL: ')
# domain = url[11:-4]
# print("Domain name: " + domain)