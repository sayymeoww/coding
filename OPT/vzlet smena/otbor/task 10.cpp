vector<int> g[maxn];
vector<int> comp(maxn);

void dfs(int v, int num) {
    comp[v] = num;
    for (auto &u : g[v]) {
        if (!comp[u]) dfs(u, num);
    }
}

int n, m;
cin >> n >> m;

int u, v;
while (m--) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
}

int num = 0, maxnum = -inf;
for (int v = 1; v <= n; v++) {
    if (!comp[v]) dfs(v, ++num);
    maxnum = max(num, maxnum);
}

cout << maxnum << '\n';
for (int i = 1; i <= n; i++) cout << comp[i] << " ";
cout << '\n';