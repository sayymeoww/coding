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
    ifstream f("7 (1).txt");

    int n, size = 10'000'000;
    f >> n;

    vector<int> arr(size, 0);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        f >> x >> y;

        int k = ceil(1.0 * y / 36);

        arr[x] = k;
        sum += (x - 1) * k;
    }

    vector<int> u = {0, 0}, v = {0, 0};

    for (int i = 1; i < size; i++)
        u[1] += arr[i];

    for (int i = 2; i < size; i++) {
        u.push_back(u[i - 1] - arr[i - 1]);
        v.push_back(v[i - 1] + arr[i - 1]);
    }

    int m = sum;
    for (int i = 2; i < size; i++) {
        sum += (v[i] - u[i]);
        m = min(m, sum);
    }

    cout << m << '\n';

    return 0;
}