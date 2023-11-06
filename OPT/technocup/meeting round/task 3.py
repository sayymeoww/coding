n, vmax = map(int, input().split())
time, dist = 0, 0
for _ in range(n):
    v, t = map(int, input().split())
    time += t
    dist += v * t
print(1 if dist / time > vmax else 0)
