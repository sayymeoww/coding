#include    <iostream>
#include    <cstdint>
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

using namespace std;

//Task 1
int m(int n) {
    vector<int> v = {1, n};
    for (int d{2}; d < n / 2; d++) {
        if (n % d == 0) {
            v.push_back(d);
            v.push_back(n / d);
        }
    }
    if ((int)v.size() < 7)
        return 0;
    sort(v.begin(), v.end());
    return v[5];
}
void taskA() {
    int k = 0, n = 300'000'001;
    while (k < 5) {
        if (m(n) > 0) {
            cout << n << " " << m(n) << '\n';
            k++;
        }
        n++;
    }
}

//Task 2
int M(int n) {
    int d = 2;
    while (d * d <= n) {
        if (n % d == 0)
            return (d + n / d);
        d++;
    }
    return 0;
}
void taskB() {
    int k = 0, n = 700'000;
    while (k < 5) {
        if (M(n) % 10 == 8) {
            cout << n << " " << M(n) << '\n';
            k++;
        }
        n++;
    }
}

//Task 3
void taskC() {
    int k = 0, n = 600'001;
    while (k < 5) {
        for (int i{2}; i <= n / 2; i++) {
            if (n % i == 0 && i % 10 == 7 && i != 7) {
                cout << n << " " << i << '\n';
                k++;
                break;
            }
        }
        n++;
    }
}

//Task 4
void taskD() {
    int a, b, t;
    cin >> a >> b >> t;

    int movie1 = (a - t % a) % a;
    int movie2 = (b - t % b) % b;
    cout << min(movie1, movie2) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //start coding here >.<
    cout << "Task 1" << '\n';
    taskA();
    cout << '\n';

    cout << "Task 2" << '\n';
    taskB();
    cout << '\n';

    cout << "Task 3" << '\n';
    taskC();
    cout << '\n';

    cout << "Task 4" << '\n';
    taskD();

    return 0;
}