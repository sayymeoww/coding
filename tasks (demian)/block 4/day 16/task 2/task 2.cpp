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

int max(int a, int b) {
    if (a > b) return a;
    return b;
}
vector<int> dp(200000);
vector<vector<bool>> use(200000, vector<bool>(200000));
int n;
vector<int> v(200000);

int get(int m, int l, int r) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            use[i][j] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = i; j <= n; j++) {
            if (v[j] >= m) count++;

            int size = j - i + 1;
            int mid = size / 2;
            int need = size - mid;

            if (size % 2 == 0) need++;
            if (count >= need) use[i][j] = true;
        }
    }

    dp[l - 1] = 0;
    for (int i = l; i <= r; i++) {
        dp[i] = -inf;
        for (int j = l - 1; j < i; j++) {
            if (use[j + 1][i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return max(dp[r], 0);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> v[i];

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, el;
            cin >> i >> el;
            v[i] = el;
        } else {
            int m, l, r;
            cin >> m >> l >> r;
            cout << get(m, l, r) << '\n';
        }
    }

    return 0;
}