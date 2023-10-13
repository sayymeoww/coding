const int maxn = 5 * 1e5 + 1;

int n;
vector<vector<pair<int, ll>>> g;

vector<ll> bfs(int s) {
    queue<int> q;
    q.push(s);

    vector<bool> used(n, 0);
    vector<ll> d(n, 0);

    int v;
    used[s] = 1;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto& [to, w] : g[v]) {
            if (!used[to]) {
                used[to] = 1;
                q.push(to);
                d[to] = d[v] + w;
            }
        }
    }

    return d;

    d.clear();
    used.clear();
}

int st, en;
ll diameter() {
    int v = 0, u = 0, w = 0;
    vector<ll> d = bfs(v);

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

vector<int> P(int s, int t) {
    vector<int> dist(n, n), p(n, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& [to, w] : g[v]) {
            if (dist[to] > dist[v] + 1) {
                p[to] = v;
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    if (dist[t] == n) {
        return {};
    }

    vector<int> path;
    while (t != -1) {
        path.push_back(t);
        t = p[t];
    }

    reverse(path.begin(), path.end());

    return path;
}

cin >> n;
g.resize(n);

int from, to;
ll w;
for (int i = 0; i < n - 1; i++) {
    cin >> from >> to;
    cin >> w;
    g[from].push_back({to, w});
    g[to].push_back({from, w});
}

cout << diameter() << " ";

vector<int> path = P(st, en);
cout << (int)path.size() << '\n';
for (auto& el : path) {
    cout << el << " ";
}
cout << '\n';

path.clear();