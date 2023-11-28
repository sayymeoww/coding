int gcd_ext(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int d = gcd_ext(b, a % b, x, y);
    x -= (a / b) * y;
    swap(x, y);

    return d;
}

int a, b, c, x, y, d;
cin >> a >> b >> c;

d = gcd_ext(a, b, x, y);
if (c % d == 0) {
    long long t = c / d * x, t2 = b / d;
    if (t == 0) cout << 0 << " " << c / d * y;
    if (t > 0)
        cout << t + t2 * (-(t / t2)) << " " << c / d * y - a / d * (-(t / t2))
             << '\n';
    if (t < 0)
        cout << t + t2 * (-((t - t2 + 1) / t2)) << " "
             << c / d * y - a / d * ((-((t - t2 + 1) / t2))) << '\n';
} else
    cout << "Impossible" << '\n';
