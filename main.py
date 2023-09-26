s = input()
result = set()
for i in range(len(s)):
    for j in range(i, len(s)):
        temp = 0
        for k in range(i + 1, j + 1):
            temp += s[k - 1] != s[k]
        if temp <= 1:
            result.add(s[i : j + 1])
print(len(result))
