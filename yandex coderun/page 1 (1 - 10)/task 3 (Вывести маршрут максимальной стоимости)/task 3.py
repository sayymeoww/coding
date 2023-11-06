n, m = map(int, input().split())
arr = [[] for i in range(n)]

for i in range(n):
    arr[i] = list(map(int, input().split()))

for i in range(n):
    for j in range(m):
        if i - 1 > -1 and j - 1 > -1:
            arr[i][j] += max(arr[i - 1][j], arr[i][j - 1])
        elif i - 1 > -1:
            arr[i][j] += arr[i - 1][j]
        elif j - 1 > -1:
            arr[i][j] += arr[i][j - 1]

i, j = n - 1, m - 1
res = []
while i != 0 or j != 0:
    if i > 0 and j > 0:
        if arr[i - 1][j] > arr[i][j - 1]:
            res.append("D")
            i -= 1
        else:
            res.append("R")
            j -= 1
    elif i > 0:
        res.append("D")
        i -= 1
    elif j > 0:
        j -= 1
        res.append("R")

res.reverse()

print(arr[n - 1][m - 1])
for i in range(len(res)):
    print(res[i], end="")
print()
