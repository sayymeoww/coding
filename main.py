k = 31
mod = 2**64
maxn = 10**6

pref = []
suf = []
powers = [0 for _ in range(maxn + 1)]
powers[0] = 1

for i in range(1, maxn + 1):
    powers[i] = (powers[i - 1] * k) % mod


def getp(s: str, l: int) -> str:
    return s[:l]


def gets(s: str, l: int) -> str:
    return s[len(s) - l :]


def geth(s: str) -> int:
    global k, mod

    h = 0
    for c in s:
        x = ord(c) - ord("a") + 1
        h = (h * k + x) % mod

    return int(h)


def conc(a: int, b: int, lena: int, lenb: int) -> int:
    global powers
    if lena > lenb:
        return a + powers[lena] * b
    else:
        return b + powers[lenb] * a


s = str(input())
t = str(input())

target = geth(s)

for l in range(len(s) + 1):
    pref.append(geth(getp(t, len(s) - l)))
    suf.append(geth(gets(t, l)))

answer = 0
for i in range(len(s) + 1):
    # print(conc(pref[i], suf[i], len(s) - i, i))
    if target == conc(pref[i], suf[i], len(s) - i, i):
        answer += 1

print(answer)
