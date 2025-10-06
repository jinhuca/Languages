# Strings can be delimited by single (' '), double (" "), triple single (''' '''), or triple double (""" """)
# quotations and can contain tab (\t) and newline (\n) characters

a = "A string in double quotes can contain 'single quote' characters."
b = 'A string in single quotes can contain "double quote" characters.'
c = '''\tA string which starts with a tab; ends with a newline character. \n'''
d = """This is a triple double quoted string, the only kind that can
    contain real newlines."""

print(a)
print(b)
print(c)
print(d)

x = "live and       let \t     \tlive"
print(x.split())
print(x.replace("      let \t     \tlive", "enjoy life"))

import re           # re module provides regular-expression functionality.
regexpr = re.compile(r"[\t ]+")
y = regexpr.sub(" ", x)
print(y)