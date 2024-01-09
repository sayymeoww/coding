const int maxn = 1e6 + 1;
set<pair<int, int>> g[maxn];

int n, p;
void bfs(int s) {
    vector<int> d(maxn, -1), p(maxn), qual(maxn);
    d[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto [w, u] : g[v]) {
            if (d[u] == -1) {
                d[u] = d[v] + w;
                p[u] = v;
                qual[u] = max(qual[u], qual[v] + w * w);
                q.push(u);
            }
        }
    }

    cout << d[n - 1] << " " << qual[n - 1] << '\n';
    // int v = n - 1;
    // while (v != s) {
    //     cout << v + 1 << " ";
    //     v = p[v];
    // }
    // cout << s + 1 << '\n';
}

cin >> n >> p;

int s, v, t, _v, _t;
while (p--) {
    cin >> s;
    cin >> v >> t;
    v--;
    s--;
    while (s--) {
        cin >> _v >> _t;
        _v--;
        g[v].insert({t, _v});
        v = _v;
        t = _t;
    }
    cin >> _v;
    _v--;
    g[v].insert({t, _v});
}

bfs(0);