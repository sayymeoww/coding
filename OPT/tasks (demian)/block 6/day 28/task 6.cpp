const int maxn = 1e5 + 1;
vector<int> g[maxn], m[maxn];
vector<pair<vector<int>, int>> t;

bool used[maxn];
void dfs(int s) {
    if (used[s]) return;
    used[s] = true;
    if (g[s].size() == 0)
        t.push_back({m[s], s});
    else {
        for (auto &el : g[s]) {
            if (!used[el]) dfs(el);
        }
    }
}

int find(vector<int> v, int k) {
    sort(v);
    for (auto &el : v) {
        if (el > k) return el;
    }
    return -1;
}

void show() {
    for (auto &[v, k] : t) {
        cout << "[";
        for (auto &el : v) cout << el << " ";
        cout << "]" << '\n';
    }
}

void solve() {
    vector<int> ans;
    int s = find(t[0].first, 0);
    ans.push_back(t[0].second + 1);
    for (int i = 1; i < t.size(); i++) {
        int q = find(t[i].first, s);
        int num = t[i].second;
        if (q == -1) {
            cout << "No" << '\n';
            return;
        } else {
            s = q;
            ans.push_back(num + 1);
        }
    }
    cout << "Yes" << '\n';
    for (auto &el : ans) {
        cout << el << " ";
    }
    cout << '\n';
}

int n;
cin >> n;

for (int i = 0; i < n; i++) {
    int p, k;
    cin >> p;
    if (p == 1) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int u;
            cin >> u;
            g[i].push_back(u - 1);
        }
    } else {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int M;
            cin >> M;
            m[i].push_back(M);
        }
    }
}

dfs(0);

solve();