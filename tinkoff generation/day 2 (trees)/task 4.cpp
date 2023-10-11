int n;
map<int, vector<pair<int, uint64_t>>> t;
vector<bool> visited;
vector<uint64_t> xors;

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = 1;
    for (auto [next, w] : t[cur]) {
        xors[next] = xors[cur] ^ w;
    }
    for (auto [next, w] : t[cur]) {
        dfs(next);
    }
}

cin >> n;
visited.resize(n + 1, 0);
xors.resize(n + 1, 0);

int from, to;
uint64_t w;
for (int i = 0; i < n - 1; i++) {
    cin >> from >> to >> w;
    t[from].push_back({to, w});
    t[to].push_back({from, w});
}

dfs(1);

t.clear();
visited.clear();

int q;
cin >> q;
while (q--) {
    cin >> from >> to;
    cout << (xors[from] ^ xors[to]) << '\n';
}