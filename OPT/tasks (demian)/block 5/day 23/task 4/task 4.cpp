const int maxn = 3e5;
vector<pair<int, int>> g[maxn];

vector<int> ans(maxn, inf);
vector<vector<int>> paths(maxn);

int minv(vector<int> v) {
    int ans = inf;
    for (auto &el : v) ans = min(ans, el);
    return ans;
}

int maxv(vector<int> v) {
    int ans = -inf;
    for (auto &el : v) ans = max(ans, el);
    return ans;
}

void dfs(int v, int target, int iter) {
    if (v == target) {
        ans[target] =
            min(ans[target], minv(paths[target]) + maxv(paths[target]));
        return;
    }

    iter++;
    if (iter > 10) return;

    for (auto &[to, w] : g[v]) {
        paths[target].push_back(w);
        dfs(to, target, iter);
        paths[target].erase(paths[target].begin() + (int)paths[target].size() -
                            1);
    }
}

int n, m;
cin >> n >> m;

set<int> vertex;

for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    vertex.insert(u);
    vertex.insert(v);

    g[u].push_back({v, w});
    g[v].push_back({u, w});
}

vertex.erase(vertex.find(1));

for (auto &el : vertex) dfs(1, el, 0);
for (auto &el : vertex) cout << ans[el] << '\n';
