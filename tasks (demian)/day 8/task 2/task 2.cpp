int t;
cin >> t;

while (t--) {
    int k;
    cin >> k;

    int MAX = -inf, MIN = inf;
    // a b -> b ( a + 1 ) + a (b + 1) = 2 ab + a + b = k -> k - a = 2ab + b -> b
    // = (k - a) / (2a + 1) k = 1e9 -> 2ab + a + b -> 2a ^ 2 + 2a = 1e9 -> a ~
    // 1e5

    for (int a = 1; a <= 100000; a++) {
        int b = (k - a) / (2 * a + 1);
        if (2 * a * b + a + b == k && b > 0) {
            MIN = min(MIN, a * b);
            MAX = max(MAX, a * b);
        }
    }

    if (MAX == -inf) {
        cout << -1 << '\n';
    } else {
        cout << MIN << " " << MAX << '\n';
    }
}