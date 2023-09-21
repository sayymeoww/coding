#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numbers>
#include <queue>
#include <set>
#include <string>
#include <vector>

// ? other includes here

#define int long long
#define pi numbers::pi  // type : double
#define inf numeric_limits<int>::max()

#define debug(x) cout << (#x) << " -> " << x << '\n';

// ? other defines here

using namespace std;

class init {
    public:
        init() { cout << fixed << setprecision(10); }

        ~init() {
            cerr << "⌛ time: " << static_cast<double>(clock()) / CLOCKS_PER_SEC
                 << " s\n";
        }
} init;

void f(int& a, int b) {
    if (a < b) a = b;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        vector<int> m(5000), s(5000);
        vector<vector<int>> dp(1000000, vector<int>(1000000));

        sort(v.begin(), v.end(), greater<int>());

        for (int i = 0; i < n; i++) {
            s[i] = 0;
            m[i] = 0;
            for (int j = 0; j <= i; ++j) dp[i][j] = -1;
            dp[i][0] = i;

            int k = 1;
            for (int j = i - 1; j >= 0; --j) {
                while (s[j] <= m[j] && v[dp[j][s[j]]] - v[j] < v[j] - v[i])
                    ++s[j];
                f(dp[i][s[j]], j);
                f(m[i], s[j]);
            }

            for (int j = m[i] - 1; j >= 0; --j) {
                f(dp[i][j], dp[i][j + 1]);
            }
        }
    }

    return 0;
}