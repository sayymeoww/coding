const int maxn = 1e6 + 1;

int n;
vector<int> t[maxn];

vector<int> dp1(maxn), dp2(maxn), cost(maxn);
void dfs(int v, int prev = -1) {
    dp1[v] = cost[v];
    dp2[v] = 0;

    for (auto &to : t[v]) {
        if (to == prev) continue;
        dfs(to, v);
        dp1[v] += dp2[to];
        dp2[v] += max(dp1[to], dp2[to]);
    }
}

cin >> n;

for (int i = 0; i < n; i++) {
    cin >> cost[i];
}

int from, to;
for (int i = 0; i < n - 1; i++) {
    cin >> from >> to;
    from--;
    to--;
    t[from].push_back(to);
    t[to].push_back(from);
}

dfs(0);

int answer = max(dp1[0], dp2[0]);
cout << answer << '\n';