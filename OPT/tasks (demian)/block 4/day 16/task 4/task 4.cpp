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

    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> v[i];

    int mn = 0, mx = 0;
    for (int i = 0; i < n - 1; i++)
        if (mx + 1 <= v[i]) mx++;
    mx = min(mx, k - 1) + 1;

    for (int i = 0; i < k - 1; i++)
        if (i + 1 > v[mn]) mn++;
    mn = k - mn;

    cout << mn << '\n';
    cout << mx << '\n';

    return 0;
}