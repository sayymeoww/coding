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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    const int size = 200000;
    vector<vector<bool>> visited(size, vector<bool>(size));
    vector<vector<int>> d(size, vector<int>(size));

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int l, r, p;
        cin >> l >> r >> p;

        for (int j = l - 1; j < r - 1; j++) visited[p - 1][j] = true;
    }

    for (int i = 0; i < k; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (visited[i][j])
                d[i][j] = 0;
            else
                d[i][j] = d[i][j + 1] + 1;
        }
    }

    int q, s, t;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> s >> t;

        int p = s - 1;
        int ans = 0;

        while (p < t - 1) {
            int best = -1;
            for (int j = 0; j < k; j++)
                if (best < d[j][p]) best = d[j][p];
            if (best == 0) break;
            ans++;
            p += best;
        }

        if (p >= t - 1)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}