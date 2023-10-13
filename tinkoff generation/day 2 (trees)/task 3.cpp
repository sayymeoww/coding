const int maxn = 2 * 1e5 + 2;

int n;
vector<int> t[maxn];

vector<int> sz(maxn), dp(maxn);
void dfs1(int v, int prev = -1) {
    sz[v] = 1;
    dp[v] = 0;

    for (auto &u : t[v]) {
        if (u != prev) dfs1(u, v);
    }

    for (auto &u : t[v]) {
        if (u != prev) {
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];
        }
    }
}

vector<int> answer(maxn);
void dfs2(int v, int prev = -1) {
    for (auto &u : t[v]) {
        if (u != prev) {
            answer[u] = answer[v] + n - 2 * sz[u];
        }
    }

    for (auto &u : t[v]) {
        if (u != prev) {
            dfs2(u, v);
        }
    }
}

cin >> n;

int from, to;
for (int i = 0; i < n - 1; i++) {
    cin >> from >> to;
    from--;
    to--;

    t[from].push_back(to);
    t[to].push_back(from);
}

dfs1(0);

answer[0] = dp[0];
cout << answer[0] << " ";

dfs2(0);

for (int i = 1; i < n; i++) {
    cout << answer[i] << " ";
}
cout << '\n';