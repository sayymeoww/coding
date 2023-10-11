const int maxn = 5 * 1e5 + 1;

int n;
vector<vector<int>> g;

vector<int> bfs(int s) {
    queue<int> q;
    q.push(s);

    vector<bool> used(n, 0);
    vector<int> d(n, 0);

    int v;
    used[s] = 1;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto &to : g[v]) {
            if (!used[to]) {
                used[to] = 1;
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
    }

    return d;

    d.clear();
    used.clear();
}

int st, en;
int diameter() {
    int v = 0, u = 0, w = 0;
    vector<int> d = bfs(v);

    for (int i = 0; i < n; i++)
        if (d[i] > d[u]) u = i;

    d = bfs(u);
    for (int i = 0; i < n; i++)
        if (d[i] > d[w]) w = i;

    st = u;
    en = w;

    return d[w];

    d.clear();
}

cin >> n;
g.resize(n);

int from, to;
for (int i = 0; i < n - 1; i++) {
    cin >> from >> to;
    g[from - 1].push_back(to - 1);
    g[to - 1].push_back(from - 1);
}

int d = diameter();

vector<int> a = bfs(st);
vector<int> b = bfs(en);

int delta = 0, ver = 0;
for (int i = 0; i < n; i++) {
    if (a[i] != 0 && b[i] != 0) {
        if (a[i] + b[i] > delta) {
            ver = i + 1;
            delta = a[i] + b[i];
        }
    }
}

cout << d + delta << '\n';
