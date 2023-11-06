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

// ? other defines here

using namespace std;

struct init {
    init() { cout << fixed << setprecision(10); }

    ~init() {
        cerr << "⌛ time: "
             << 1000 * static_cast<double>(clock()) / CLOCKS_PER_SEC << " ms\n";
    }
} init;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    ifstream f("23.txt");
    ofstream o("out.txt");

    int t;
    f >> t;

    vector<int> a(3);
    f >> a[0] >> a[1] >> a[2];
    int sum = a[0] + a[1] + a[2];
    int m = sum / 3;
    if (sum % 3 != 0)
        o << "No" << '\n';
    else {
        if (t == 0) {
            o << (abs(a[0] - m) + abs(a[1] - m) + abs(a[2] - m)) / 2 << '\n';
        } else {
            o << "Yes" << '\n';
            o << (abs(a[0] - m) + abs(a[1] - m) + abs(a[2] - m)) / 2 << '\n';
            sort(a.begin(), a.end());
            while (a[0] < a[2]) {
                o << a[0] << " " << a[2] << '\n';
                a[0]++;
                a[2]--;
                if (!(a[0] < a[1] && a[1] < a[2])) sort(a.begin(), a.end());
            }
        }
    }
    o.close();

    return 0;
}