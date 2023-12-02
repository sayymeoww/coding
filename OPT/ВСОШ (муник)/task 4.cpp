#include <bits/stdc++.h>

#define int unsigned int
#define ll uint64_t

#define bin(x) 1 << x
#define log(x) 32 - __builtin_clz(x) - 1

#define all(x) x.begin() x.end()
#define sort(x) sort(x.begin(), x.end())

const int mod = 1e9 + 7;

using namespace std;

unordered_map<int, int> a;

int calc() {
    int ans = 0;
    for (auto &[key, value] : a) {
        ans |= value;
    }
    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.tie(nullptr);

    // start coding here

    int n;
    cin >> n;
    int s = 0, x, q, t, ind, v, cnt, z;

    for (int i = 0; i < n; i++) {
        cin >> x;
        s |= x;
        a[i] = x;
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> t;

        if (t == 1) {
            cin >> ind >> v;
            ind--;

            a[ind] = v;
            s = calc();
        } else {
            cin >> z;

            cnt = 0;
            for (int x = 0; x <= z; x++) {
                if ((s | x) <= z) cnt++;
            }

            cout << cnt << '\n';
        }
    }

    cout.flush();
    return 0;
}