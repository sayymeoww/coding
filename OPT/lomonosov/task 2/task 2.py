def convert(s : str) -> dict:
    d = dict()
    
    temp = 0
    for c in s:
        if c.isdigit():
            temp = 10 * temp + int(c)
        else:
            if c in d:
                d[c] += temp
            else:
                d[c] = temp
            temp = 0
    
    return d

costs = {
    'a' : 0.0001,
    'b' : 0.0005,
    'c' : 0.001,
    'd' : 0.005,
    'e' : 0.01,
    'f' : 0.02,
    'g' : 0.05,
    'h' : 0.1,
    'i' : 0.25,
    'A' : 0.05,
    'B' : 0.1,
    'C' : 0.5,
    'D' : 1,
    'E' : 2,
    'F' : 5,
    'G' : 10,
    'H' : 20,
    'I' : 50
}
def value(d : dict) -> float:
    global costs

    answer = 0
    for c in d:
        answer += d[c] * costs[c]
    
    return answer

n = int(input())
a = []
for _ in range(n):
    s = str(input())
    a.append(value(convert(s)))

mx = 0
ansi, ansj = 0, 0
for i in range(n):
    for j in range(n):
        if i != j:
            if abs(a[i] - a[j]) > mx:
                ansi = i
                ansj = j
                mx = abs(a[i] - a[j])
            if abs(a[i] - a[j]) == mx:
                if ansi + ansj < i + j:
                    ansi = i
                    ansj = j
                    mx = abs(a[i] - a[j])

print(min(ansi, ansj) + 1)
print(max(ansi, ansj) + 1)