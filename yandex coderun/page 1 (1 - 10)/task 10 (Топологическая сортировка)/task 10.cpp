const int maxn = 1e5 + 1;

int n, m;
vector<int> used(maxn);
vector<int> g[maxn];
vector<int> t;

bool flag = false;

void dfs(int v) {
    used[v] = 1;

    for (auto &u : g[v]) {
        if (used[u] == 1) flag = true;
        if (used[u] == 0) dfs(u);
    }
    used[v] = 2;

    t.push_back(v);
}

void topsort() {
    for (int v = 1; v <= n; v++) {
        if (used[v] == 0) dfs(v);
    }
    reverse(t.begin(), t.end());
}

cin >> n >> m;

int u, v;
while (m--) {
    cin >> u >> v;
    g[u].push_back(v);
}

topsort();

if (flag)
    cout << -1 << '\n';
else {
    for (auto &el : t) cout << el << " ";
    cout << '\n';
}