a = int(input())
b = int(input())
c = int(input())

v = [a, b, c]
v.sort()

f1 = (v[1] - v[0] == v[2] - v[1]) and (v[1] - v[0] >= 0)
f2 = (v[1] / v[0] == v[2] / v[1]) and (v[1] / v[0] > 1)

if f1:
    print("A ", end="")
    print(*v)
elif f2:
    print("G ", end="")
    print(*v)
else:
    print("No")
