const int maxn = 2 * 1e5 + 1;
int n;

vector<int> g[maxn];
vector<int> mt(maxn);
vector<bool> used(maxn);

bool dfs(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int u : g[v]) {
        if (mt[u] == -1 || dfs(mt[u])) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

cin >> n;
int v, u;
for (int i = 1; i < n; i++) {
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
}

int cnt = 0;

mt.assign(maxn, -1);

for (int i = 0; i < n; i++) {
    used.assign(maxn, 0);
    if (dfs(i)) cnt++;
}

cout << cnt / 2 << '\n';