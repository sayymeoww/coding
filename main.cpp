#pragma region template
#pragma region pragmas
#pragma GCC optimize("Ofast")
#pragma GCC target( \
        "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma endregion pragmas

// ? other pragmas

#pragma region includes
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <compare>
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
#include <numbers>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
#pragma endregion includes

// ? other includes here

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
    for (auto &el : x) cout << el + 1 << " "
#define sort(x) sort(x.begin(), x.end())
#pragma endregion defines

// ? other defines here

using namespace std;

// ! declared program time
const double TIME = 1;  // in seconds

const int mod = 1e9 + 7;

#pragma region init
class init {
    public:
        init() { cout << fixed << setprecision(10); }

        ~init() {
            double PROGTIME = static_cast<double>(clock()) / CLOCKS_PER_SEC;
            cerr << "⌛ time: " << PROGTIME << " s ";
            if (PROGTIME * 0.9 > TIME)
                cerr << "[❌ TL ERROR]"
                     << "[" << TIME << " s]" << '\n';
            else
                cerr << "[✅ OK]"
                     << "[" << TIME << " s]" << '\n';
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

    fstream cin("file/input.txt");
    ofstream cout("file/output.txt");
#pragma endregion ios

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    int n, m, k, pos;
    cin >> n >> m;

    char c;
    string s;
    cin >> s;

    vector<vector<pair<int, char>>> chars(n), poses(m);
    vector<int> bad(n);

    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> pos >> c;
            pos--;

            chars[i].push_back({pos, c});
            poses[pos].push_back({i, c});

            if (c != s[pos]) bad[i]++;
        }
    }

    vector<bool> perf(n, false), poss(m, false);

    vector<int> p;
    set<pair<int, int>> q;

    for (int i = 0; i < n; i++) q.insert({bad[i], i});

    while (!q.empty()) {
        auto it = q.begin();
        int card = it->second;

        if (bad[card] != 0) break;

        q.erase(it);
        p.push_back(card);

        perf[card] = true;

        for (auto [pos, c] : chars[card])
            if (!poss[pos]) {
                poss[pos] = true;
                for (auto [badd, c2] : poses[pos]) {
                    if (!perf[badd] && c2 != c) {
                        q.erase({bad[badd], badd});
                        bad[badd]--;
                        q.insert({bad[badd], badd});
                    }
                }
            }
    }

    bool flag = true;
    for (bool have : poss) flag &= have;

    if (p.size() != n || !flag)
        cout << -1 << '\n';
    else
        print(p);

    return 0;
}
