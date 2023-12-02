a, b, c, d = map(int, input().split())

s = abs(a * b - c * d)
s = abs(s)

q = int(s**0.5) + 1

for k in range(q, 1, -1):
    if s % k == 0:
        print(s // k)
        break
