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

class fenvik {
    public:
        int n;
        vector<int> tree;

        fenvik(int n) : n(n), tree(vector<int>(n)) {}

        void add(int i, int x) {
            if (i < 0) return;
            while (i < n) {
                tree[i] += x;
                i |= i + 1;
            }
        }

        int pref(int i) {
            int result = 0;
            while (i >= 0) {
                result += tree[i];
                i = (i & (i + 1)) - 1;
            }
            return result;
        }

        int sum(int l, int r) { return pref(r) - pref(l - 1); }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    int n, q, count = 0;
    cin >> n >> q;

    vector<int> open(n, -1), close(n, -1), que(q), pref(q), left(n), right(n);

    for (int i = 0; i < q; i++) {
        string command;
        int x;

        cin >> command >> x;
        x--;
        que[i] = x;

        if (command == "add") {
            open[x] = i;
            count++;
        } else {
            close[x] = i;
        }
    }

    fenvik t = fenvik(q), red = fenvik(q);

    for (int i = 0; i < q; i++) {
        int x = que[i];

        if (open[x] == i && close[x] != -1) right[x] += pref[i];
        if (close[x] == i) {
            right[x] += t.sum(0, open[x] - 1);
            left[x] += red.pref(open[x]);
        }

        pref[i + 1] = pref[i];
        if (open[x] == i && close[x] == -1) pref[i + 1]++;
        if (close[x] == i) {
            t.add(open[x], -1);
            red.add(i + 1, -1);
            red.add(open[x], 1);
        }
        if (close[x] != -1 && open[x] == i) t.add(i, 1);
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (close[i] != -1) {
            answer += min(left[i], right[i]) * 2 + 1;
        }
    }
    answer += count;

    cout << answer << '\n';

    return 0;
}