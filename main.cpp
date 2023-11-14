#pragma region template
#pragma region includes
#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <fstream>
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

using namespace std;
#pragma endregion template

// * [˙·٠•●♥ Solution ♥●•٠·˙] * //

using M = map<char, vector<int>>;

M convert(string s) {
    M answer;
    for (int i = 0; i < (int)s.size(); i++) {
        answer[s[i]].push_back(i);
    }
    return answer;
}

bool comp(M a, M b) {
    for (auto &[key, value] : a) {
        vector<int> v;
        set_intersection(a[key].begin(), a[key].end(), b[key].begin(),
                         b[key].end(), back_inserter(v));
        if (v.size() != 0) return true;
    }
    return false;
}

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

    int q;
    cin >> q;

    string s;
    cin >> s;

    M cur = convert(s);

    sort(s);
    while (next_permutation(s.begin(), s.end())) {
        if (!comp(convert(s), cur)) {
            cout << s << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}