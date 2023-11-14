import random
import collections


def f(s: str) -> str:
    letters = list(s)
    random.shuffle(letters)
    while any(s[i] == letters[i] for i in range(len(s))):
        random.shuffle(letters)
    answer = "".join(letters)

    return answer


answer = []
q = int(input())


for i in range(q):
    s = input()
    if collections.Counter(s).most_common(1)[0][1] > len(s) / 2:
        answer.append(-1)
    else:
        answer.append(f(s))

print(*answer, sep="\n")
