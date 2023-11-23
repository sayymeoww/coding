const int maxn = 1e5 + 1;
const int lg = 18;

int a[maxn], sparse[maxn][lg], n;
void check(int &u, int &v) {
    if (u > v) swap(u, v);
}

void rmq() {
    for (int i = 1; i <= n; i++) sparse[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            if (a[sparse[i][j - 1]] < a[sparse[i + (1 << (j - 1))][j - 1]])
                sparse[i][j] = sparse[i][j - 1];
            else
                sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
}

int q(int i, int j) {
    int k = (int)(log(1.0 * j - i + 1) / log(2.0)), res = sparse[i][k];
    if (a[sparse[j - (1 << k) + 1][k]] < a[res])
        res = sparse[j - (1 << k) + 1][k];
    return res;
}

int m;
cin >> n >> m >> a[1];

int u, v;
cin >> u >> v;

for (int i = 2; i <= n; ++i) a[i] = (23 * a[i - 1] + 21563) % 16714589;

rmq();

int ans;
for (int i = 1; i <= m; i++) {
    int u1, v1;
    u1 = u, v1 = v;

    check(u1, v1);
    ans = a[q(u1, v1)];

    if (i < m) {
        u = ((17 * u + 751 + ans + 2 * i) % n) + 1;
        v = ((13 * v + 593 + ans + 5 * i) % n) + 1;
    }
}

cout << u << " " << v << " " << ans << '\n';