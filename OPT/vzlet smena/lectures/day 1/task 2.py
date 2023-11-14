n = int(input())
a = list(map(int, input().split()))
s = 0
for el in a:
    s += el
print(s // 100)
