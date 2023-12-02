#include <bits/stdc++.h>

#define int long long
#define ll uint64_t

#define bin(x) 1 << x
#define log(x) 32 - __builtin_clz(x) - 1

#define all(x) x.begin() x.end()
#define sort(x) sort(x.begin(), x.end())

const int mod = 1e9 + 7;

using namespace std;

const int maxn = 2e5;
vector<int> g[maxn];
map<int, int> ver;
vector<int> ans;

int n, m, k;

void check(int v) {
    int cnt = 0;
    for (auto &u : g[v]) {
        if (ver[u] == 1) cnt++;
    }
    if (cnt >= k) ver[v] = 1;
}

vector<int> used(maxn);
void dfs(int u, int p) {
    if ((used[u] == 1 || used[u] == 2) && p == 0) return;
    used[u] = 1;
    for (auto &el : g[u]) {
        if (used[el] == 0) {
            ans.push_back(el);
            dfs(el, 0);
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr);

    // start coding here

    cin >> n >> m >> k;

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (k == 1) {
        int c, u;
        cin >> c;
        vector<int> pick;
        for (int i = 0; i < c; i++) {
            cin >> u;
            used[u] = 2;
            ans.push_back(u);
            pick.push_back(u);
        }
        for (auto &u : pick) {
            dfs(u, 1);
        }
        cout << (int)ans.size() << '\n';
        for (auto &el : ans) {
            cout << el << " ";
        }
        cout << '\n';
        return 0;
    }

    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        cin >> u;
        ver[u] = 1;
    }

    while (true) {
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (ver[i] == 0) {
                check(i);
                if (ver[i] == 1) flag = true;
            }
        }
        if (!flag) break;
    }

    for (int i = 1; i <= n; i++) {
        if (ver[i] == 1) {
            ans.push_back(i);
        }
    }

    cout << (int)ans.size() << '\n';
    for (auto &el : ans) {
        cout << el << " ";
    }
    cout << '\n';

    cout.flush();
    return 0;
}