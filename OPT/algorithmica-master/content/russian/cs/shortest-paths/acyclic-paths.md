---
title: Пути в ациклических графах
weight: 1
authors:
- Сергей Слотин
date: 2021-09-29
---

Кратчайшие пути очень просто искать, если в графе нет циклов.

В этом случае задачу нахождения кратчайших расстояний от заданной вершины до всех остальных можно решить в стиле динамического программирования — кратчайшее расстояние до вершины $v$ можно найти через перебор всех потенциальных последних рёбер на кратчайшем пути:

$$
d_v = \min_{(u, v) \in E} (d_u + w_{uv})
$$

Чтобы посчитать эту формулу, нужно уметь для заданной вершины $v$ быстро проходиться по всем обратным ребрам, а также найти такой порядок обхода, что при подсчете $d_v$ все нужные $d_u$ уже были подсчитаны.

### Реализация

Конкретно, транспонируем граф и переведем его в формат списков смежности — то есть для каждой вершины составим список ведущих в неё ребер с их весами:

```cpp
vector< pair<int, int> > t[N]; // откуда ведет ребро и его вес
```

Заведем массив $d$, в котором мы для каждой вершины будем хранить расстояние от изначальной вершины — для удобства будем считать, что у неё нулевой номер. Для всех ячеек кроме первой этот массив изначально будет заполнен «бесконечностью» — некоторым числом, которое заведомо больше, чем любое правильное расстояние.

```cpp
vector<int> d(n, inf);
d[0] = 0;
```

Теперь, проходясь по вершинам графа в порядке какой-нибудь [топологической сортировки](/cs/graph-traversals/topological-sorting) — которую можно найти как отдельным обходом, так и как-нибудь неявно — будем *релаксировать* (обновлять более оптимальным значением) расстояние до $v$, рассматривая его обратные ребра по формуле выше:

```cpp
for (int v = 1; u < n; u++)
    for (auto [u, w] : t[v])
        d[v] = min(d[v], d[u] + w);
```

Такой алгоритм очень простой и работает за $O(m)$.

К несчастью, в общем случае, когда в графе есть циклы, он не работает: хотя релаксация `d[v] = min(d[v], d[u] + w)` всегда корректная и ничего не ломает для любых $v$ и $y$, ключевым предположением является то, что у нас есть порядок обхода, в котором все нужные предыдущие расстояния уже посчитаны, а задача нахождения такого обхода в общем случае не легче самой задачи нахождения кратчайшего пути.

### Восстановление путей

Чтобы получать не только расстояния, но ещё и научиться восстанавливать сами пути, мы можем для каждой вершины помимо расстояния хранить, из какой вершины произошло последнее релаксирование:

```cpp
vector<int> p(n);

for (int v = 1; u < n; u++) {
    for (auto [u, w] : t[v]) {
        if (d[v] < d[u] + w) {
            d[v] = d[u] + w;
            p[v] = u;
        }
    }
}
```

Теперь для восстановления кратчайшего пути до $v$ нужно просто пройтись по предкам вершины $v$:

```cpp
while (v != 0) {
    cout << v << endl;
    v = p[v];
}
```

Также часто в задачах бывает полезно рассматривать «каркас» графа: прогнать какой-нибудь алгоритм нахождения кратчайших путей и оставить в графе только те ребра, которые лежат на каком-то пути — то есть для которых выполняется $d_v = d_u + w_{uv}$. Такой подграф будет ацикличным, и с ним легко работать, например, аналогичным образом насчитывая разные динамики.

**Упражнение.** Требуется за $O(m)$ найти *количество* кратчайший путей из $s$ в $t$ в ациклическом графе.
