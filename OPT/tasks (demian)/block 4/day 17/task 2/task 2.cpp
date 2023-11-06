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

    string s;
    cin >> s;

    set<string> res;

    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            int t = 0;
            for (int k = i + 1; k < j + 1; k++) {
                t += (int)(s[k - 1] != s[k]);
            }
            if (t <= 1) {
                res.insert(s.substr(i, j + 2 - i));
            }
        }
    }

    cout << (int)res.size() << '\n';

    return 0;
}