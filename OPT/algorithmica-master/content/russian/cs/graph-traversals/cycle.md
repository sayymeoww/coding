---
title: Нахождение цикла
authors:
- Сергей Слотин
weight: 4
---

Напомним, что циклом в графе $G$ называется ненулевой путь, ведущий из вершины $v$ в саму себя. Граф называют ацикличным, если в нем нет циклов.

Для нахождения цикла, рассмотрим такой альтернативные способ делать обход в глубину:

```cpp
void dfs(int v, int p = -1) {
    for (int u : g[v])
        if (u != p)
            dfs(u, v);
}
```

Здесь мы вместо массива `used` передаем в рекурсию параметр $p$, равный номеру вершины, откуда мы пришли, или $-1$, если мы начали обход в этой вершине.

Этот способ корректен только для деревьев — проверка `u != p` гарантирует, что мы не пойдем обратно по ребру, однако если в графе есть цикл, то мы в какой то момент вызовем `dfs` второй раз с одними и теми же параметрами и попадем в бесконечный цикл.

Если мы можем определять, попали ли мы в бесконечный цикл, то это ровно то, что нам нужно. Модифицируем `dfs` так, чтобы мы могли определять момент, когда мы входим в цикл. Для этого просто вернем массив `used` обратно, но будем использовать его для проверки, были ли мы когда-то в вершине, которую мы собираемся посетить — это будет означать, что цикл существует.

```cpp
const int maxn = 1e5;
bool used[maxn];

void dfs(int v, int p = -1) {
    if (used[v]) {
        cout << "Graph has a cycle" << endl;
        exit(0);
    }
    used[v] = true;
    for (int u : g[v])
        if (u != p)
            dfs(u, v);
}
```

Если нужно восстанавливать сам цикл, то можно вместо завершения программы возвращаться из рекурсии несколько раз и выписывать вершины, пока не дойдем до той, в которой нашелся цикл.

```cpp
// возвращает -1, если цикл не нашелся, и вершину начала цикла в противном случае
int dfs(int v, int p = -1) {
    if (used[v]) {
        cout << "Graph has a cycle, namely:" << endl;
        return v;
    }
    used[v] = true;
    for (int u : g[v]) {
        if (u != p) {
            int k = dfs(u, v);
            if (k != -1) {
                cout << v << endl;
                if (k == v)
                    exit(0);
                return k;
            }
        }
    }
    return -1;
}
```

Как и со всеми обходами, если в графе больше одной компоненты связности, или если граф ориентированный, то `dfs` нужно запускать несколько раз от вершин разных компонент.

```cpp
for (int v = 0; v < n; v++)
    if (!used[v])
        dfs(v);
```