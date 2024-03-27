const int maxn = 1e5 + 1;

vector<set<int>> t(maxn), T(maxn);
vector<vector<int>> g(maxn, vector<int>(maxn));
vector<int> room(maxn);

int cnt = 0;
void dfs(int v) {
    cout << v << '\n';

    if (room[v] == 0) return;
    if (t[v].size() == 0) return;

    room[v]--;
    for (auto u : t[v]) {
        if (room[u] && g[u][v]) {
            cnt++;
            g[u][v]--;
            g[v][u]--;
            if (g[u][v] == 0) {
                t[u].erase(v);
            } else {
                dfs(u);
            }
        }
    }
    return;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--;
        v--;

        T[u].insert(v);
        T[v].insert(u);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cnt = 0;

        t = T;
        g.assign(n, vector<int>(n, 2));
        room.assign(n, k);

        dfs(i);

        cout << cnt * 10 << '\n';
    }
}

int t;
cin >> t;

while (t--) solve();