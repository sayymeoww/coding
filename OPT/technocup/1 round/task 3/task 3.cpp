const int maxn = 1e5;
vector<int> g[maxn];

vector<int> d(maxn, -1);

void bfs(int s) {
    queue<int> q;
    q.push(s);

    d[s] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (d[u] == -1) {
                q.push(u);
                d[u] = (d[v] + 1) % 2;
            }
        }
    }
}

int n, m;
cin >> n >> m;

int a, b;
while (m--) {
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
}

int s;
cin >> s;

s--;

bfs(s);

int ans = 0;
for (int i = 0; i < n; i++) {
    if (d[i] == 1) ans++;
}

cout << ans << '\n';
