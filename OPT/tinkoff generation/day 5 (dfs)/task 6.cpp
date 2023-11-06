const int maxn = 101;

vector<int> g[maxn];
vector<int> used(maxn);

int n, m, c;

void dfs(int v) {
    used[v] = 1;
    c++;

    for (auto &u : g[v]) {
        if (!used[u]) dfs(u);
    }
}

cin >> n >> m;

int u, v;
for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
}

bool flag = false;

for (int i = 1; i <= n; i++) {
    used.assign(n, 0);
    c = 0;

    dfs(i);

    if (m == n - 1 && c == n) {
        cout << "YES" << '\n';
        return 0;
    }
}

cout << "NO" << '\n';