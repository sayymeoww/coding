n = int(input())

prs = [
    1,
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    43,
    47,
    53,
    59,
    61,
    67,
    71,
    73,
    79,
    83,
    89,
    97,
    101,
    103,
    107,
    109,
    113,
    127,
    131,
    137,
    139,
    149,
    151,
    157,
    163,
    167,
    173,
    179,
    181,
    191,
    193,
    197,
    199,
    211,
    223,
    227,
    229,
    233,
    239,
    241,
    251,
    257,
    263,
    269,
    271,
    277,
    281,
    283,
    293,
    307,
    311,
]

prim0 = [0 for i in range(len(prs))]

prim0[0] = 1

for i in range(1, len(prim0)):
    prim0[i] = prim0[i - 1] * prs[i]

a = [[int(i) for i in input().split(":")] for j in range(n)]
b = [0 for i in range(n)]
s = dict()

for i in range(len(a)):
    x = 0
    for j in range(len(a[i])):
        x += a[i][j] * prim0[len(a[i]) - j - 1]
    if x in s.keys():
        s[x].append(i)
    else:
        s[x] = [i]
    b[i] = x

b.sort()

for i in s[b[len(b) - 1]]:
    print(i + 1)
