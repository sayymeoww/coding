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

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int a = max(v[0], v[1]), b = min(v[0], v[1]);

    for (int i = 1; i < n; i++) {
        if (v[i] >= b) {
            cout << b << " ";
            a = b;
            b = v[i];
        } else {
            cout << a << " ";
            if (v[i] > a) {
                a = v[i];
            }
        }
    }
    cout << '\n';

    return 0;
}