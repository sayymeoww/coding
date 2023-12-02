n = int(input())
a = int(input())
b = int(input())
p = (n * a) // (a + b)
if (n - p) * a == p * b:
    print(p)
else:
    print(-1)
