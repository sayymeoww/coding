int t = 0;
const int maxn = 1e5 + 1;
vector<vector<int>> g(maxn);
vector<bool> visited(maxn, false);
vector<int> tin(maxn), tout(maxn);

void dfs(int start) {
    visited[start] = true;
    tin[start] = t++;
    for (int u : g[start])
        if (!visited[u]) dfs(u);
    tout[start] = t;
}

// u является предком вершины v
bool check(int u, int v) { return tin[v] >= tin[u] && tin[v] < tout[u]; }

int n, q;
cin >> n >> q;

int head, s, h;
for (int i = 0; i < n; i++) {
    cin >> s >> h;
    if (h == 0) {
        head = s - 1;
    } else {
        s--;
        h--;

        g[h].push_back(s);
    }
}

dfs(head);
for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    vector<int> members(k);

    for (int j = 0; j < k; j++) {
        cin >> members[j];
        members[j]--;
    }

    vector<int> answer(n, 0);
    for (int j = 0; j < n; j++) {
        bool flag = false;
        for (auto &el : members) {
            if (el == j) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            bool flag2 = false;
            for (auto &el : members) {
                if (check(j, el)) {
                    flag2 = true;
                    break;
                }
            }
            if (!flag2) answer[j] = 1;
        }
    }

    for (int j = 0; j < n; j++) {
        if (answer[j] == 0) {
            cout << j + 1 << " ";
        }
    }
    cout << '\n';
}