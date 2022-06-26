import sys

s1 = list(sys.stdin.readline().strip())
s2 = []
m = int(sys.stdin.readline())
n = len(s1)

for i in range(m):
    a = sys.stdin.readline().strip()
    if a[0] == "P":
        s1.append(a[2])
    elif a[0] == "L" and s1 != []:
        s2.append(s1.pop())  
    elif a[0] == "D" and s2 != []:
        s1.append(s2.pop())
    elif a[0] == "B" and s1 != []:
        s1.pop()
print("".join(s1 + list(reversed(s2))))
