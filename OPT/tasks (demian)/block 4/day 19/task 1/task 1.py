mat = []
for i in range(10):
    mat.append(list(map(int, input().split())))

first = list(map(int, input().split()))
second = list(map(int, input().split()))

test = int(input())
while True:
    if test == 0:
        break

    a, b = map(str, input().split())
    answer = []
    _a = ["."] * 1000
    _b = ["."] * 1000

    maxlen = max(len(a), len(b))

    for i in range(len(str(a))):
        _a[i] = int(a[::-1][i])
    for i in range(len(str(b))):
        _b[i] = int(b[::-1][i])

    _a = _a[:maxlen]
    _b = _b[:maxlen]

    answer = [0] * (maxlen + 1)

    for i in range(maxlen):
        if _a[i] != "." and _b[i] != ".":
            answer[i] = mat[_a[i]][_b[i]]
        elif _a[i] != ".":
            answer[i] = second[_a[i]]
        elif _b[i] != ".":
            answer[i] = first[_b[i]]

    print(*answer[::-1])

    test -= 1
