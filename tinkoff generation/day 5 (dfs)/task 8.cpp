const int maxn = 2e5 + 1;
vector<int> g[maxn];
vector<int> deg(maxn);

pair<char, char> ic[maxn];
map<pair<char, char>, int> ci;

int n, m;
vector<int> euler(int s = 0) {
    vector<int> work(n), in(n), out(n), tour;
    for (int u = 0; u < n; u++) {
        for (auto &v : g[u]) {
            out[u]++;
            in[v]++;
        }
    }

    int a = 0, b = 0;
    for (int u = 0; u < n; u++) {
        if (in[u] == out[u] + 1) {
            b++;
            if (b == 2) return tour;
        } else if (out[u] == in[u] + 1) {
            a++;
            s = u;
            if (a == 2) return tour;
        } else if (out[u] != in[u] || in[u] == 0)
            return tour;
    }

    stack<int> dfs;
    dfs.push(s);
    while (!dfs.empty()) {
        int u = dfs.top();
        if (work[u] < (int)g[u].size()) {
            dfs.push(g[u][work[u]++]);
        } else {
            tour.push_back(u);
            dfs.pop();
        }
    }

    reverse(tour.begin(), tour.end());

    return tour;
}

cin >> m;
n = 0;

int u, v;
string s;
pair<char, char> a, b;
for (int i = 0; i < m; i++) {
    cin >> s;
    a = {s[0], s[1]};
    b = {s[1], s[2]};
    if (!ci.count(a)) {
        ic[n] = a;
        ci[a] = n++;
    }
    if (!ci.count(b)) {
        ic[n] = b;
        ci[b] = n++;
    }
    u = ci[a];
    v = ci[b];
    g[u].push_back(v);
    deg[v]++;
}

vector<int> ans = euler();
n = (int)ans.size();

if (m + 1 != n) {
    cout << "NO" << '\n';
} else {
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        cout << ic[ans[i]].first;
    }
    cout << ic[ans.back()].second << '\n';
}