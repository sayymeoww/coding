int t, x, y;

cin >> t;
while (t--) {
    cin >> x >> y;
    if (x < y) {
        if (y % 2 == 1) {
            cout << y * y - x + 1 << '\n';
        } else {
            cout << (y - 1) * (y - 1) + 1 + x - 1 << '\n';
        }
    } else {
        if (x % 2 == 0) {
            cout << x * x - y + 1 << '\n';
        } else {
            cout << (x - 1) * (x - 1) + 1 + y - 1 << '\n';
        }
    }
}