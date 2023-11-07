const int maxn = 1e5 + 5;

int n, m, h, a, b, ordn, sccn;
vector<int> u(maxn), mrk(maxn), ord(maxn), scc(maxn), vis(maxn), sz(maxn);
vector<int> res;

vector<int> g[maxn], gt[maxn];

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u])
        if (!vis[v]) dfs(v);
    ord[ordn++] = u;
}

void dfst(int u) {
    vis[u] = 0;
    for (int v : gt[u])
        if (vis[v]) dfst(v);
    scc[u] = sccn;
    sz[scc[u]]++;
}

void dfsres(int u) {
    if (vis[u]) return;

    vis[u] = 1;
    res.push_back(u);

    for (int v : g[u]) dfs(v);
}

cin >> n >> m >> h;

for (int i = 1; i <= n; i++) cin >> u[i];
for (int i = 0; i < m; i++) {
    cin >> a >> b;

    if ((u[a] + 1) % h == u[b]) {
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    if ((u[b] + 1) % h == u[a]) {
        g[b].push_back(a);
        gt[a].push_back(b);
    }
}

sccn = ordn = 1;
for (int i = 1; i <= n; ++i)
    if (!vis[i]) dfs(i);
for (int i = n; i > 0; --i)
    if (vis[ord[i]]) dfst(ord[i]), sccn++;

for (int u = 1; u <= n; u++)
    for (int v : g[u])
        if (scc[u] != scc[v]) mrk[scc[u]] = 1;

sz[0] = inf;
int ans = 0;
for (int i = 1; i < sccn; i++)
    if (!mrk[i] && sz[ans] > sz[i]) ans = i;

cout << sz[ans] << '\n';
for (int i = 1; i <= n; i++)
    if (scc[i] == ans) cout << i << " ";
cout << '\n';
