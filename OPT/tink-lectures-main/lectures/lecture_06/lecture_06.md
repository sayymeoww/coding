# Sparse tables
(опираюсь на [алгоритмику](https://algorithmica.org/ru/sparse-table))
Мы обсуждали префиксные суммы - но префиксные суммы не умеют считать, к примеру минимум на отрезке (при неизменном массиве). Вводим новую структуру данных - sparse table, которая будет строиться за $O(n \log n)$ и выполнять взятие минимума/максимума за $O(1)$ (тоже при неизменном отрезке).

Что такое sparse table - таблица $st$, размером $\log(n) \times n$, в $st_{i,j}$ лежит минимум на отрезке $[j, j + 2^i - 1]$
Как мы ее будем строить:
```cpp
int a[maxn], mn[logn][maxn];
// инициализация вектора, logn - максимально возможный логарифм от длины отрезка.
for (int i = 0; i < n; i++) {
  mn[0][i] = a[i];
} // или же
memcpy(mn[0], a, sizeof a);

for (int l = 0; l < logn - 1; l++)
    for (int i = 0; i + (2 << l) <= n; i++)
        mn[l+1][i] = min(mn[l][i], mn[l][i + (1 << l)]);
```

Теперь как брать минимум:
```cpp
int rmq(int l, int r) { // [l, r)
    int t = lg[r - l];
    return min(mn[t][l], mn[t][r - (1 << t)]);
}

```
нужно пояснить, что lg - массив предпосчитанных логарифмов

Можно брать любую операцию, которая ассоцитативна, коммутативна и идемпотентна (то есть min, max, gcd подойдут).

Можно построить двумерные спарсы (по аналогии с двумерными префиксными суммами), тогда надо будет брать минимум на подпрямоугольниках (таблица будет вида mn[l][i][j]).

# Сверху
(опираемся на [алгоритмику](https://ru.algorithmica.org/cs/segment-tree/))
Теперь мы приходим к задаче "взять минимум/максимум/сумму/любую операцию на отрезке, изменить в точке" или "взять значение в точке, сделать += на отрезке".
Объясняем то, как устроено ДО, почему оно дерево, объяснить можно сначала на примере с массивом размера $2^n$, про то, что отрезков суммарно логарифм, про то, что глубина логарифм и т.д.
```cpp
const int N = 1e5;  // limit for array size
int a[N];
int t[4 * N];
void build(int v, int tl, int tr) {
    if (tr - tl == 1) t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

void upd(int v, int tl, int tr, int pos, int val) {
    if (tr - tl == 1) t[v] = val;
    else {
        int tm = (tl + tr) / 2;
        if (pos < tm) upd(v * 2, tl, tm, pos, val);
        else upd(v * 2 + 1, tm, tr, pos, val);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if (r <= tl || tr <= l) return 2e9;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return min(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm, tr, l, r));
}
```
Рассказать про то, что можно не только минимум брать, что можно брать любую функцию, композиция которой легко считается.

Также нас может заинтересовать другая постановка задачи - сделать += на отрезке, взять значение в точке. Тогда взглянем на задачу немного по-другому:

```cpp
void upd(int v, int tl, int tr, int l, int r, int val) {
    if (tr < l || r < tl) return 2e9;
    if (l <= tl && tr <= r) t[v] += val;
    int tm = tl + tr >> 1; // (tl + tr >> 1) <==> (tl + tr) / 2
    upd(v << 1, tl, tm, l, r, val); // (v << 1) <==> v * 2 
    upd(v << 1 | 1, tm, tr, l, r, val); // (v << 1 | 1) <==> v * 2 + 1
}

int get(int v, int tl, int tr, int pos) {
    if (tr - tl == 1) return t[v];
    int tm = tl + tr >> 1;
    if (pos < tm) return t[v] + get(v << 1, tl, tm, pos);
    else return t[v] + get(v << 1 | 1, tm, tr, pos);
}
```
# Cнизу
Дерево отрезков снизу банально быстрее из-за отсутствия рекурсии и меньшего объема памяти. Но дерево отрезков снизу не умеет многое, что умеет ДО сверху, хотя оно достаточно простое в понимании (ориентируюсь на [эту](https://codeforces.com/blog/entry/18051) статью, код оттуда же)
```cpp
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
```

# Спуск по дереву

Пример задачи, для которой требуются спуски - поиск k-го нуля справа от l.

примерный код спусков:
```cpp
const int N = 2e5;
int t[N];

std::pair<int, int> find_k_th_zero(int v, int tl, int tr, int l, int k) {
    if (tr < l) {
        return {-1, 0};
    }
    if (t[v] < k && tl >= l) {
        return {-1, t[v]};
    }
    if (tr - tl == 1 && k == 1) {
        return {tl, 1};
    }
    int tm = (tl + tr) / 2;
    std::pair<int, int> res = {-1, -1};
    auto res = find_k_th_zero(2 * v, tl, tm, l, k);
    auto res2 = res;
    if (res.first == -1) {
        res2 = find_k_th_zero(2 * v + 1, tm, tr, l, k - res.second);
        res2.second += res2.first;
    }
    return res2;
}
```

# MST
Мерж сорт три - позволяет решать задачи вида (найдите количество чисел от a до b на отрезке [l, r]) без апдейтов
```cpp
const int N = 1e5;  // limit for array size
int a[N];
std::vector<int> t[4 * N];
void build(int v, int tl, int tr) {
    if (tr - tl == 1) t[v] = {a[tl]};
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm, tr);

        t[v].resize(tr - tl);
        std::merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v].begin());
    }
}

int get(int v, int tl, int tr, int l, int r, int a, int b) {
    if (r <= tl || tr <= l) return 0;
    if (l <= tl && tr <= r) {
        return std::upper_bound(t[v].begin(), t[v].end(), b) - std::lower_bound(t[v].begin(), t[v].end(), a);
    }
    int tm = (tl + tr) / 2;
    return get(v * 2, tl, tm, l, r) + get(v * 2 + 1, tm, tr, l, r);
}
```



