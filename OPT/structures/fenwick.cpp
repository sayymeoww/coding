const int maxn = ...;

int a[maxn];  // массив
int t[maxn];  // дерево

// возвращает сумму на префиксе
int sum(int r) {
    int res = 0;
    for (int i = r; i > 0; i -= i & -i) res += t[i];
    return res;
}

int sum(int l, int r) {
    if (l) return sum(r) - sum(l - 1);
    return sum(r);
}

// обновляет нужные t
void add(int k, int x) {
    for (int i = k; i <= n; i += i & -i) t[i] += x;
}

// где то в main...

int n;
cin >> n;

for (int i = 0; i < n; i++) cin >> a[i];
for (int i = 0; i < n; i++) add(i, a[i]);