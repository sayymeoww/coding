#include    <iostream>
#include    <iomanip>
#include    <cstdint>
#include    <fstream>
#include    <limits>
#include    <numbers>
#include    <cassert>

#include    <map>
#include    <set>
#include    <queue>
#include    <deque>
#include    <vector>
#include    <string>
#include    <cstring>

#include    <cmath>
#include    <bitset>
#include    <algorithm>

// ? other includes here

#define     int     long long
#define     pi      numbers::pi //type : double
#define     inf     numeric_limits<int>::max()

// ? other defines here

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    int t;
    cin >> t;

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    if (t == 2) {
        cout << min({a, b, c}) << '\n';
    } else {
        int answer = a + b + c - 2 * n;
        cout << ((answer < 0) ? 0 : answer) << '\n';
    }

    return 0;
}