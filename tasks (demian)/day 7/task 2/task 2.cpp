int a, t, x = 0, count;

int n, q;
cin >> n >> q;

set<int> coins;
for (int i = 0; i < n; i++) {
    cin >> a;
    coins.insert(a);
}

count = n;
for (auto coin : coins) x ^= coin;

while (q--) {
    cin >> t;
    if (t == 1) {
        cin >> a;
        x ^= a;
        count--;
    } else if (t == 2) {
        cin >> a;
        x ^= a;
        count++;
    } else {
        if (x == 0) {
            cout << count << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}