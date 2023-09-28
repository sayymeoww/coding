from scipy.spatial import Delaunay
import matplotlib.pyplot as plt
import numpy as np

n = int(input())
p = []

for iteration in range(n):
    x, y = map(int, input().split())
    p.append([x, y])

t = Delaunay(np.array(p))
plt.triplot(np.array(p)[:, 0], np.array(p)[:, 1], t.simplices.copy())
plt.plot(np.array(p)[:, 0], np.array(p)[:, 1], "o")

plt.show()

tri = []

for fig in t.simplices.tolist():
    current = []
    for plot in fig:
        # x, y = p[plot]
        current.append(plot)
    tri.append(current)
    print(*current)

q = int(input())
i = 0

while True:
    question = "? "
    for num in tri[i]:
        question += str(num + 1) + " "

    print(question)

    answer = input()

    if answer == "Yes":
        find = "! "
        for num in tri[i]:
            find += str(num + 1) + " "

        print(find)

        q -= 1
    else:
        i += 1

    if q == 0:
        break
