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

using namespace std;

const int logn = 18;

int n;
vector<int> t;

void update(int p, int x) {
    for (; p <= n + 2; p += p & -p) t[p] += x;
}

int sum(int p) {
    int answer = 0;
    for (; p > 0; p -= p & -p) answer += t[p];
    return answer;
}

int sum(int l, int r) { return sum(r) - sum(l); }

int lower_bound(int x) {
    int k = 0;
    for (int i = logn; i >= 0; --i) {
        if (k + (1 << i) <= n + 2 && t[k + (1 << i)] < x) {
            k += (1 << i);
            x -= t[k];
        }
    }
    return k;
}

void build(int N) {
    t.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        update(i, 1);
    }
}

signed main() {
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    build(n + 2);

    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        while (cur < n) {
            int sj = sum(0, a[cur].second + 2);
            update(a[cur].second + 2, -1);
            int p1 = lower_bound(sj - 1), p2 = lower_bound(sj);

            if (p2 - p1 > i) {
                update(a[cur].second + 2, 1);
                cout << a[cur].first << " ";

                break;
            } else {
                ++cur;
            }
        }
    }
    cout << '\n';

    return 0;
}