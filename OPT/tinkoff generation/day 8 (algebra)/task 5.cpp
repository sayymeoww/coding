pair<int, bool> fac(int n) {
    for (int i = 2, lim = pow(n, 1.0 / 3) + 0.5; i <= lim; i++)
        if (!(n % (i * i)))
            return {i, true};
        else if (!(n % i))
            return {i, false};

    if (int s = sqrt(n) + 0.5; s * s == n) return {s, true};

    return {1, true};
}

int c, ans = 1;
cin >> c;

while (c != 0) {
    auto [p, t] = fac(c);
    if (t) {
        c /= (p * p);
        ans *= p;
    } else
        c /= p;
    if (p == 1) break;
}

cout << ans / 2 + 1 << '\n';