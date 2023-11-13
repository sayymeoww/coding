#pragma region template
#pragma region includes
#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

// ? other includes

#pragma endregion includes

#pragma region defines
#define int long long
#define ll uint64_t
#define pi numbers::pi  // type : double
#define inf numeric_limits<int>::max()

#define debug(x) cout << (#x) << " -> " << x << '\n';

#define bin(x) 1 << x
#define log(x) 32 - __builtin_clz(x) - 1

#define all(x) begin(x), end(x)
#define print(x) \
    for (auto &el : x) cout << el << " "
#define sort(x) sort(x.begin(), x.end())

// ? other defines

#pragma endregion defines

const int mod = 1e9 + 7;

using namespace std;
#pragma endregion template

// * [˙·٠•●♥ Solution ♥●•٠·˙] * //

const int maxn = 2e5;

vector<map<int, int>> g(maxn);

int answer;
void dfs(int from, int to, int w) {
    for (auto &v : g[to]) {
        if (v.first != from) {
            if (v.second ^ w) {
                answer++;
                dfs(to, v.first, v.second ^ w);
            }
        }
    }
}

signed main() {
#pragma region ios
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr);
    cout.precision(20);

    // fstream cin("file/input.txt");
    // ofstream cout("file/output.txt");
#pragma endregion ios

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    int n;
    cin >> n;

    int u, v, w;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        g[u][v] = w;
        g[v][u] = w;
    }

    for (int i = 0; i < n; i++) {
        answer = 0;
        for (auto &v : g[i]) {
            if (v.second != 0) {
                dfs(i, v.first, v.second);
                answer++;
            }
        }
        cout << answer + 1 << ' ';
    }
    cout << '\n';

    return 0;
}