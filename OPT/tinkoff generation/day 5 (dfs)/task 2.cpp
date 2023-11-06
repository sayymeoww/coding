const int maxn = 1e5 + 1;

vector<int> g[maxn];
vector<int> component(maxn);

void dfs(int v, int num) {
    component[v] = num;
    for (auto &u : g[v]) {
        if (!component[u]) dfs(u, num);
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
    if (!component[v]) dfs(v, ++num);
    maxnum = max(num, maxnum);
}

vector<vector<int>> answer(maxn);
for (int i = 1; i <= n; i++) {
    answer[component[i]].push_back(i);
}

cout << maxnum << '\n';
for (int i = 1; i <= maxnum; i++) {
    cout << (int)answer[i].size() << '\n';
    for (auto &v : answer[i]) cout << v << " ";
    cout << '\n';
}