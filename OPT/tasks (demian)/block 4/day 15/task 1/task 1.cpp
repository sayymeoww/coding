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

    ifstream fin("14.txt");

    int t;
    fin >> t;

    int n;
    vector<int> a, b;

    while (t--) {
        fin >> n;
        a.resize(n);
        b.resize(n);

        for (int i = 0; i < n; i++) fin >> a[i];
        for (int i = 0; i < n; i++) fin >> b[i];

        vector<int> v(n);

        int minb = 0;
        for (int i = 0; i < n; i++) {
            if (b[minb] > b[i]) minb = i;
        }

        v[minb] = b[minb];

        for (int i = minb + 1; i < n; i++) {
            if (v[i - 1] < a[i])
                v[i] = a[i];
            else if (v[i - 1] > b[i])
                v[i] = b[i];
            else if (v[i - 1] >= a[i] && v[i - 1] <= b[i])
                v[i] = v[i - 1];
        }

        for (int i = minb - 1; i >= 0; i--) {
            if (v[i + 1] < a[i])
                v[i] = a[i];
            else if (v[i + 1] > b[i])
                v[i] = b[i];
            else if (v[i + 1] >= a[i] && v[i + 1] <= b[i])
                v[i] = v[i + 1];
        }

        int answer = 0;
        for (int i = 1; i < n; i++) {
            answer += abs(v[i] - v[i - 1]);
        }
        cout << answer << '\n';

        for (auto el : v) {
            cout << el << " ";
        }
        cout << '\n';
    }

    return 0;
}