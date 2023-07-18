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

//other includes here

#define     int     long long
#define     pi      numbers::pi //type : double
#define     inf     numeric_limits<int>::max()

//other defines here

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // start coding here
    // (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

    ifstream f("67.txt");

    int n;
    f >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        f >> v[i];
        v[i] *= 3;
    }

    int s = 0, left = 0, right = 0;

    for (int i = 0; i < n / 2; i++) {
        left += v[n - i];
        right += v[i];

        s += (v[i] + v[n - i]) * i;
    }

    s += v[n / 2] * n / 2;
    vector<int> sums(n);
    sums[0] = s;

    for (int i = 1; i < n; i++) {
        sums[i] = sums[i - 1] + left - right + v[i - 1] - v[(n / 2 + i - 1) % n];
        right += (v[(n / 2 + i - 1) % n] - v[i]);
        left += (v[i - 1] - v[(n / 2 + i) % n]);
    }

    int answer = 0;
    for (auto el : sums) {
        answer = max(answer, el);
    }

    cout << answer << '\n';

    return 0;
}