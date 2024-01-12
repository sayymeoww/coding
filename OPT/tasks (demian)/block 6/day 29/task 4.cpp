const int maxn = 1e5 + 1;
map<int, int> g[maxn];

vector<int> path;
vector<bool> used(maxn);

void update() {
    for (int i = (int)path.size() - 1; i >= 1; i--) {
        if (g[path[i]][path[i - 1]] == 1 && g[path[i - 1]][path[i]] == 1) {
            g[path[i]][path[i - 1]] = 0;
            g[path[i - 1]][path[i]] = 1;
            return;
        }
    }
}

void dfs(int v) {
    path.push_back(v);
    if (used[v]) {
        update();
        return;
    }
    used[v] = true;
    for (auto &[u, type] : g[v]) {
        if (type != 0) {
            dfs(u);
        }
    }
}

int n, m;
cin >> n >> m;

int a, b, d;
for (int i = 0; i < m; i++) {
    cin >> a >> b >> d;
    if (d == 1) {
        g[a][b] = 1;
        g[b][a] = 0;
    } else {
        g[a][b] = 1;
        g[b][a] = 1;
    }
}

for (int i = 1; i <= n; i++) {
    used.assign(maxn, false);
    path.clear();
    dfs(i);
}

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (g[i][j] != 0) cout << i << " " << j << '\n';
    }
}