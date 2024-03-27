from math import inf
from random import random


def get(a: int, b: int) -> float:
    return a + (b - a) * random()


def circle(x: int, y: int, x0: float, y0: float, r: int):
    return (x - x0) ** 2 + (y - y0) ** 2 <= r * r


n = int(input())

c = []
minl, maxr = inf, -inf
mind, maxu = inf, -inf
for _ in range(n):
    x, y, r = map(int, input().split())
    c.append([x, y, r])

    minl = min(minl, x - r)
    maxr = max(maxr, x + r)

    mind = min(mind, y - r)
    maxu = max(maxu, y + r)

iter = 1_000_000_00

inn, al = 0, 0
for _ in range(iter):
    x0 = get(minl, maxr)
    y0 = get(mind, maxu)

    for [x, y, r] in c:
        if circle(x, y, x0, y0, r):
            inn += 1
            break

    al += 1

print((inn / al) * (maxr - minl) * (maxu - mind))
