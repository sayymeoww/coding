struct edge {
    int to, w;
};

void solve() {
    int n, m, q, p;
    cin >> n >> m >> q >> p;

    vector<vector<edge>> g(n);
    for (int i = 0; i != m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;
        g[u].push_back({v, w});
    }

    vector<vector<int>> segms(n);
    segms[0] = {0};

    for (int v = 1; v != n; v++) {
        vector<int> lst;

        for (auto u: g[v])
            for (auto val: segms[u.to])
                lst.push_back(val + u.w);

        sort(lst);
        lst.resize(unique(all(lst)) - lst.begin());
        reverse(all(lst));

        for (auto elem: lst) {
            while (segms[v].size() >= 2 && p * elem > (p - 1) * segms[v][(int)segms[v].size() - 2])
                segms[v].pop_back();
            segms[v].push_back(elem);
        }
    }

    for (; q != 0; q--) {
        int v, w;
        cin >> v >> w;
        v--;

        bool ok = false;
        for (auto len: segms[v])
            if (w <= len && len * (p - 1) <= w * p) {
                ok = true;
                break;
            }

        cout << (ok ? '1' : '0');
    }

    cout << '\n';
}

int t;
cin >> t;

while (t-->0) solve();