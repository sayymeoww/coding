class edge {
    public:
        vector<int> to;
};

const int maxn = 1e4;
vector<edge> g(maxn);

vector<int> operator+(vector<int> a, vector<int> b) {
    vector<int> c;
    for (auto el : a) c.push_back(el);
    for (auto el : b) c.push_back(el);
    return c;
}

int n;

void fit(int ind, vector<int> &v) {
    vector<int> w;
    for (auto &el : v)
        if (el != ind) w.push_back(el);
    v = w;
}

vector<edge> G;
void dfs(int u, int v, int current, int size, bool &flag) {
    if (u == current || v == current) {
        flag = (size > 0);
        return;
    }
    if ((int)g[current].to.size() == 0) return;
    for (auto &el : G[current].to) {
        dfs(u, v, el, size + 1, flag);
    }
}

void solve(int u, int v) {
    G = g;
    vector<int> temp = G[u].to + G[v].to;

    G[u].to = temp;
    fit(u, G[u].to);

    G[v].to = temp;
    fit(v, G[v].to);

    bool flag = false;
    for (auto &el : G[u].to) {
        dfs(u, v, el, 0, flag);
        if (flag) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
    return;
}

cin >> n;
for (int i = 0; i < n; i++) {
    int cnt;
    cin >> cnt;
    while (cnt--) {
        int e;
        cin >> e;
        g[i].to.push_back(e);
    }
}

int q;
cin >> q;

while (q--) {
    int u, v;
    cin >> u >> v;
    solve(u, v);
}
