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

bool f(bool x, bool y) { return !x || y; }

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    ifstream in("16.txt");

    int n;
    in >> n;
    vector<bool> bits(n);

    for (int i = 0; i < n; i++) {
        int a;
        in >> a;
        bits[i] = (a == 1);
    }

    int co = 0, cz = 0;
    vector<bool> prefix(n);
    prefix[0] = bits[0];
    if (prefix[0])
        co++;
    else
        cz++;

    for (int i = 1; i < n; i++) {
        prefix[i] = f(prefix[i - 1], bits[i]);
        if (prefix[i])
            co++;
        else
            cz++;
    }

    int a;
    in >> a;

    bool r = (a == 1);
    if (prefix[n - 1] == r) {
        cout << 0 << '\n';
        return 0;
    }
    if (r && co == 0) {
        cout << -1 << '\n';
        return 0;
    }
    if (!r && cz == 0) {
        cout << -1 << '\n';
        return 0;
    }

    // [l, r] = pref[l] -> pref[r]

    bool flag1 = false;

    int left = n - 2;
    int right = n - 1;

    bool temp = f(prefix[left - 1], f(prefix[left], prefix[right]));
    while (temp != r) {
        if (left == 0) {
            flag1 = true;
            break;
        }
        left--;
        temp = f(prefix[left - 1], f(prefix[left], prefix[right]));
    }
    if (flag1) {
        left = n - 3;
        right = n - 2;

        bool temp = f(prefix[left - 1], f(prefix[left], prefix[right]));
        while (temp != r) {
            if (left == 0) {
                cout << -1 << '\n';
                return 0;
            }
            left--;
            temp = f(prefix[left - 1], f(prefix[left], prefix[right]));
        }

        cout << left + 1 << " " << right + 1 << '\n';
    } else {
        cout << left + 1 << " " << right + 1 << '\n';
    }

    return 0;
}