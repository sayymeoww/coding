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

const int maxn = 2e5;

vector<int> a;
vector<vector<int>> mn;

void init(int n) {
    a.resize(n);
    int asize = n;
    for (int i = 0; i < n; i++) cin >> a[i];

    while ((1 << (log(a.size()))) != a.size()) {
        a.push_back(0);
        asize++;
    }

    mn.resize((log(asize)) + 1, vector<int>(maxn));

    for (int i = 0; i < asize; i++) mn[0][i] = a[i];
    for (int l = 0; l < (log(asize)); l++)
        for (int i = 0; i + (2 << l) <= asize; i++)
            mn[l + 1][i] = max(mn[l][i], mn[l][i + (1 << l)]);
}

int rmq(int l, int r) {
    int t = log(r - l);
    return max(mn[t][l], mn[t][r - (1 << t)]);
}

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

    int n;
    cin >> n;

    init(n);

    cout << *min_element(a.begin(), a.begin() + n) << " ";
    for (int k = 2; k <= n; k++) {
        int temp = inf;
        for (int i = 1; i <= n - k + 1; i++)
            temp = min(temp, rmq(i - 1, i + k - 1));
        cout << temp << " ";
    }
    cout << '\n';

    return 0;
}