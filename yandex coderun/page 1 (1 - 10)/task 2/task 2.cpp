#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <compare>
#include <cstdint>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numbers>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

// ? other includes here

#define int long long
#define ll uint64_t
#define pi numbers::pi  // type : double
#define inf numeric_limits<int>::max()

#define debug(x) cout << (#x) << " -> " << x << '\n';

// ? other defines here

using namespace std;

// ! declared program time
const double TIME = 1;  // in seconds

const int mod = 1e9 + 7;

class init {
    public:
        init() { cout << fixed << setprecision(10); }

        ~init() {
            double PROGTIME = static_cast<double>(clock()) / CLOCKS_PER_SEC;
            cerr << "⌛ time: " << PROGTIME << " s ";
            if (PROGTIME > TIME)
                cerr << "[❌ TL ERROR]"
                     << "[" << TIME << " s]" << '\n';
            else
                cerr << "[✅ OK]"
                     << "[" << TIME << " s]" << '\n';
        }
} init;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr);
    cout.precision(20);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = g[0][0];

    for (int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + g[i][0];
    for (int i = 1; i < m; i++) dp[0][i] = dp[0][i - 1] + g[0][i];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i - 1][j] + g[i][j], dp[i][j - 1] + g[i][j]);
        }
    }

    cout << dp[n - 1][m - 1] << '\n';

    return 0;
}
