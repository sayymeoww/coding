#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

// ? other includes here

#define int long long
#define ll uint64_t
#define inf numeric_limits<int>::max()

#define debug(x) cout << (#x) << " -> " << x << '\n';

// ? other defines here

using namespace std;

// ! declared program time
const double TIME = 1;  // in seconds

const int mod = 1e9 + 7;

class init {
    public:
        init() { cout << fixed << setprecision(10); }

        ~init() {
            double PROGTIME = static_cast<double>(clock()) / CLOCKS_PER_SEC;
            cerr << "⌛ time: " << PROGTIME << " s ";
            if (PROGTIME > TIME)
                cerr << "[❌ TL ERROR]"
                     << "[" << TIME << " s]" << '\n';
            else
                cerr << "[✅ OK]"
                     << "[" << TIME << " s]" << '\n';
        }
} init;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr);
    cout.precision(20);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    return 0;
}
