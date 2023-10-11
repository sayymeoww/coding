const int maxn = 2 * 1e5 + 10;

int n;
vector<vector<int>> t;
vector<unordered_set<int>> color;
vector<bool> used;
vector<int> res;

void dfs(int cur) {
    for (int i : t[cur]) {
        if (!used[i]) {
            used[i] = 1;
            dfs(i);
            if (color[cur].size() < color[i].size()) swap(color[cur], color[i]);
            for (auto j : color[i]) color[cur].insert(j);
            color[i].clear();
        }
    }

    res[cur] = color[cur].size();
}

cin >> n;
t.resize(n);
color.resize(n);
used.resize(n, 0);
res.resize(n);

for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    color[i].insert(c);
}

int from, to;
for (int i = 0; i < n - 1; i++) {
    cin >> from >> to;
    t[from - 1].push_back(to - 1);
    t[to - 1].push_back(from - 1);
}

used[0] = 1;
dfs(0);

for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
}
cout << '\n';