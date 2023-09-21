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

class r {
    public:
        int x, y;
};

r operator+(r a, r b) { return {a.x + b.x, a.y + b.y}; }
r operator-(r a, r b) { return {a.x - b.x, a.y - b.y}; }
int operator^(r a, r b) { return a.x * b.y - b.x * a.y; }

vector<r> graham(vector<r> points) {
    r p0 = points[0];
    for (r p : points)
        if (p.x < p0.x || (p.x == p0.x && p.y < p0.y)) p0 = p;

    sort(points.begin(), points.end(),
         [&](r a, r b) { return ((a - p0) ^ (b - p0)) > 0; });

    vector<r> hull;
    for (r p : points) {
        while (hull.size() >= 2) {
            r new_vector = p - hull.back();
            r last_vector = hull.back() - hull[hull.size() - 2];
            if ((new_vector ^ last_vector) > 0)
                hull.pop_back();
            else
                break;
        }
        hull.push_back(p);
    }
    return hull;
}

inline int area(r a, r b, r c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1(int a, int b, int c, int d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}

bool intersect(r a, r b, r c, r d) {
    return intersect_1(a.x, b.x, c.x, d.x) && intersect_1(a.y, b.y, c.y, d.y) &&
           area(a, b, c) * area(a, b, d) <= 0 &&
           area(c, d, a) * area(c, d, b) <= 0;
}

bool check(vector<r> a, vector<r> b) {
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)b.size(); j++) {
            if (intersect(a[i], a[(i + 1) % (int)a.size()], b[j],
                          b[(j + 1) % (int)b.size()])) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    vector<r> a, b;
    while (n--) {
        int x, y, type;
        cin >> x >> y >> type;

        r point;
        point.x = x;
        point.y = y;

        if (type == 0) {
            a.push_back(point);
        } else {
            b.push_back(point);
        }
    }

    if (check(a, b))
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}