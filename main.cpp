#pragma region template
#pragma region includes
#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

// ? other includes

#pragma endregion includes

#pragma region defines
#define int long long
#define ll uint64_t
#define pi numbers::pi  // type : double
#define inf numeric_limits<int>::max()

#define debug(x) cout << (#x) << " -> " << x << '\n';

#define bin(x) 1 << x
#define log(x) 32 - __builtin_clz(x) - 1

#define all(x) begin(x), end(x)
#define print(x) \
    for (auto &el : x) cout << el << " "
#define sort(x) sort(x.begin(), x.end())

// ? other defines

#pragma endregion defines

const int mod = 1e9 + 7;
const int TIME = 1;  // in seconds
using namespace std;

#pragma region init
class init {
   public:
    init() { cout << fixed << setprecision(10); }

    ~init() {
        double PROGTIME = static_cast<double>(clock()) / CLOCKS_PER_SEC;
        cerr << fixed << setprecision(6)
             << "╭ · · · · ·  ╮╭ ⌛ time: " << PROGTIME << " s ";
        cerr << "[" << TIME << " s] ╮" << '\n';
    }
} init;
#pragma endregion init
#pragma endregion template

// * [˙·٠•●♥ Solution ♥●•٠·˙] * //

signed main() {
#pragma region ios
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr);
    cout.precision(20);

    // fstream cin("file/input.txt");
    // ofstream cout("file/output.txt");
#pragma endregion ios

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    int n, w;
    cin >> n >> w;

    bitset<6250000> b;
    b[0] = 1;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        b = b | (b << v[i]);
    }

    if (b[w] == 0) {
        cout << "NO" << '\n';
        return 0;
    }

    set<pair<int, int>, greater<pair<int, int>>> s;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        s.insert({v[i], i});
    }

    for (int i = 1; i <= n; i++) {
        for (auto &j : s) {
            if (w - j.first >= 0 && b[w - j.first]) {
                ans.push_back(j.second + 1);
                w -= j.first;
                s.erase(j);
                break;
            }
        }
    }

    sort(ans);

    cout << "YES" << '\n';
    cout << ans.size() << '\n';
    for (auto &el : ans) cout << el << " ";
    cout << '\n';

    cout.flush();
    return 0;
}