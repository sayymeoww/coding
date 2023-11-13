a, k, b, m, x = map(int, input().split())
l = 0
r = x
while l < r:
    mid = (l + r) // 2
    _a = a * (mid - mid // k)
    _b = b * (mid - mid // m)
    if _a + _b >= x:
        r = mid
    else:
        l = mid + 1
print(l)
