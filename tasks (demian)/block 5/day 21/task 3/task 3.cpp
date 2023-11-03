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

// ? other pragmas

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

// ? other includes here

#define int long long
#define ll uint64_t
#define pi numbers::pi  // type : double
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

vector<pair<int, int>> convert(vector<int> a, int n, int m) {
    int t = 1, i = 0;
    vector<pair<int, int>> answer;
    vector<int> b = a;

    while (true) {
        if (i == n) return answer;
        if (b[i] == 0) {
            i++;
            t++;
            continue;
        }
        if (b[i] >= m) {
            answer.push_back({t, m});
            b[i] -= m;
        }
        if (b[i] < 0) {
            i++;
            t++;
            continue;
        }
        if (b[i] > 0 && b[i] < m) {
            answer.push_back({t, b[i]});
            i++;
            t++;
            continue;
        }
    }
}

vector<pair<int, int>> chapter(int pages, int m, int x) {
    vector<pair<int, int>> answer;
    while (true) {
        if (pages > 0 && pages < m) {
            answer.push_back({x, pages});
            return answer;
        }
        if (pages == 0) return answer;
        if (pages >= m) {
            answer.push_back({x, m});
            pages -= m;
        }
    }
}

vector<pair<int, int>> uni(vector<pair<int, int>> book, int m, int x) {
    vector<pair<int, int>> answer;
    int index;
    for (auto &el : book) {
        if (el.first < x) {
            answer.push_back(el);
        } else {
            break;
        }
    }
    for (int i = 0; i < (int)book.size(); i++) {
        if (book[i].first < x) {
            answer.push_back(book[i]);
        } else {
            index = i;
            break;
        }
    }
    int add = 0;
    for (int i = index; i < (int)book.size(); i++) {
        if (book[i].first == x || book[i].first == x + 1) {
            add += book[i].second;
        } else {
            index = i;
            break;
        }
    }

    vector<pair<int, int>> toadd = chapter(add, m, x);
    for (auto &el : toadd) {
        answer.push_back(el);
    }

    for (int i = index; i < (int)book.size(); i++) {
        book[i].first--;
        answer.push_back(book[i]);
    }

    return answer;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr);
    cout.precision(20);

    fstream cin("input.txt");
    ofstream cout("output.txt");

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> book;  // глава / кол-во строк
    book = convert(a, n, m);

    int q;
    cin >> q;
    while (q--) {
        string word;
        cin >> word;
        if (word == "size") {
            cout << (int)book.size() << '\n';
        } else if (word == "union") {
            int x;
            cin >> x;
            book = uni(book, m, x);
        } else if (word == "split") {
            int x, y;
            cin >> x >> y;
            // сделать
        } else if (word == "resize") {
            int x, y;
            cin >> x >> y;
            // сделать
        } else if (word == "chapter") {
            int x;
            cin >> x;
            cout << book[x].first << '\n';
        }
    }

    return 0;
}
