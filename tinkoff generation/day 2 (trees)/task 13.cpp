const int maxn = 2 * 1e5 + 1;
vector<int> g[maxn];
int cnt[maxn];
int cn = 0;

void findcnt(int v, int p = -1) {
    cnt[v] = 1;
    for (int i : g[v]) {
        if (p == i) continue;
        findcnt(i, v);
        cnt[v] += cnt[i];
    }
}

int find(int v, int p = -1) {
    for (int i : g[v]) {
        if (p == i) continue;
        if (cnt[i] > cn / 2) return find(i, v);
    }
    return v;
}

int solve(int root) {
    findcnt(root);
    cn = cnt[root];
    int centroid = find(root);
    return centroid;
}

int n;
cin >> n;

for (int i = 1; i < n; i++) {
    int u, v;
    cin >> v >> u;
    g[v].push_back(u);
    g[u].push_back(v);
}

cout << solve(1) << '\n';