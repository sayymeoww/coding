const int maxn = 51 * 51 * 6;
vector<int> g[maxn];
vector<bool> visited(maxn);

bool flag = false;
int p;

void dfs(int v, int target, int prev, vector<int> picked) {
    if (v == target) {
        flag = true;
        p = prev;
        return;
    }
    visited[v] = true;
    for (auto &u : g[v]) {
        if (!visited[u]) {
            dfs(u, target, v);
        }
    }
}

vector<int> fixiki, crabs;

void remove(int u, int v) {
    auto i1 = find(g[u].begin(), g[u].end(), v);
    if (i1 != g[u].end()) g[u].erase(i1);

    auto i2 = find(g[v].begin(), g[v].end(), u);
    if (i2 != g[v].end()) g[v].erase(i2);
}

void solve() {
    for (auto &u : fixiki) {
        for (auto &w : crabs) {
            flag = false;
            while (!flag) {
                visited.assign(maxn, false);
                dfs(u, w, 0);
                remove(w, p);
                cout << w << " " << p << '\n';
            }
        }
    }
}

int n = 1;

g[1].push_back(2);
g[1].push_back(4);

g[2].push_back(1);
g[2].push_back(3);

g[3].push_back(2);
g[3].push_back(6);

g[4].push_back(1);
g[4].push_back(5);

g[5].push_back(4);
g[5].push_back(6);

g[6].push_back(3);
g[6].push_back(5);

int m;
cin >> m;

int c;
while (m--) {
    cin >> c;
    crabs.push_back(c);
}

int k;
cin >> k;

int f;
while (k--) {
    cin >> f;
    fixiki.push_back(f);
}

solve();