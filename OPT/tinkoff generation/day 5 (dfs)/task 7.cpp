const int maxn = 1e3 + 1;
vector<vector<int>> graph(maxn, vector<int>(maxn)), g(maxn, vector<int>(maxn));
vector<int> used(maxn, 0);

int n;
void dfs(int v, int type) {
    used[v] = 1;
    for (int i = 0; i < n; i++) {
        if ((type ? g[i][v] : g[v][i]) && !used[i]) dfs(i, type);
    }
}

int check(void) {
    for (int i = 0; i < n; i++)
        if (!used[i]) return 0;
    return 1;
}

cin >> n;

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cin >> graph[i][j];
    }
}

int l = 0, r = 1e9, m;
while (l < r) {
    m = (l + r) / 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) g[i][j] = (graph[i][j] <= m);

    used.assign(maxn, 0);
    dfs(0, 0);
    bool flag = false;

    if (check()) {
        used.assign(maxn, 0);
        dfs(0, 1);
        if (!check()) flag = true;
    } else
        flag = true;

    if (!flag)
        r = m;
    else
        l = m + 1;
}

cout << l << '\n';