import re

pattern = "[A-Z][1-9]\\d*"
m = re.match(pattern, 'O')
print(bool(m))