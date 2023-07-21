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

// mind -> maxd = n / mind
// maxd x (n / maxd)
// r = (1 / 2) * d = ceil(1 / 2 * sqrt(maxd^2 + (n / maxd)^2))

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    int n;
    cin >> n;

    int d = 1;
    for (int i = sqrt(n); i >= 2; i++) {
        if (n % i == 0) {
            d = i;
            break;
        }
    }

    int a = d;
    int b = n / d;

    cout << ceil(0.5 * sqrt(a * a + b * b)) << '\n';

    return 0;
}