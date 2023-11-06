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

vector<char> ans(50001, '.');

bool request(int l, int r) {
    if (l > r) return true;

    cout << "? " << l + 1 << " " << r + 1 << '\n';

    string t;
    cin >> t;

    return t == "Yes";
}

void solve(int l, int r) {
    if (l > r) return;

    if (request(l + 1, r - 1)) {
        ::ans[l] = '(';
        ::ans[r] = ')';

        solve(l + 1, r - 1);

        return;
    }

    for (int i = r - 1; i >= l + 2; i -= 2) {
        if (request(i, r)) {
            ::ans[i] = '(';
            ::ans[r] = ')';

            solve(i + 1, r - 1);
            solve(l, i - 1);

            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    int n;
    cin >> n;

    solve(0, n - 1);

    cout << "! ";
    for (int i = 0; i < n; i++) cout << ::ans[i];
    cout << '\n';

    return 0;
}