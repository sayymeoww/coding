int n, maxn = 2 * 1e5 + 1;
vector<vector<int>> t;
vector<int> d1(maxn), d2(maxn);

void dfs(int cur, vector<int> &dist, int parent = -1, int timer = 0) {
    dist[cur] = timer;
    for (auto child : t[cur]) {
        if (child != parent) {
            dfs(child, dist, cur, timer + 1);
        }
    }
}

int n;
cin >> n;

t.resize(n);

for (int i = 1; i < n; i++) {
    int from, to;
    cin >> from >> to;

    t[from - 1].push_back(to - 1);
    t[to - 1].push_back(from - 1);
}

dfs(0, d1);

int x = 0, y = 0;

for (int i = 0; i < n; i++)
    if (d1[x] < d1[i]) x = i;
dfs(x, d1);

for (int i = 0; i < n; i++)
    if (d1[y] < d1[i]) y = i;

dfs(y, d2);

for (int i = 0; i < n; i++) cout << max(d1[i], d2[i]) << " ";
cout << '\n';
