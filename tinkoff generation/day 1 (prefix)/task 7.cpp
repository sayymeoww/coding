int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void fill(int left, int right, int pos, vector<int> &a, vector<int> &gcd) {
    if (left == right) {
        gcd[pos] = a[left];
    } else {
        int lefte = (left + right) >> 1;
        int rightb = lefte + 1;

        fill(left, lefte, (pos << 1) + 1, a, gcd);
        fill(rightb, right, (pos << 1) + 2, a, gcd);

        gcd[pos] = ::gcd(gcd[(pos << 1) + 1], gcd[(pos << 1) + 2]);
    }
}

int get(int ql, int qr, int l, int r, int pos, vector<int> &gcd) {
    if (qr < l || ql > r) return 0;

    ql = max(ql, l);
    qr = min(qr, r);

    if (ql == l && qr == r) return gcd[pos];
    assert(l < r);

    int le = (l + r) >> 1;
    int rb = le + 1;

    return ::gcd(get(ql, qr, l, le, (pos << 1) + 1, gcd),
                 get(ql, qr, rb, r, (pos << 1) + 2, gcd));
}

int n, k;
cin >> n >> k;

vector<int> v(n + 1);
for (int i = 1; i <= n; i++) {
    cin >> v[i];
}

vector<int> g(4 * n, -1);
fill(1, n, 0, v, g);

int ans = 0;
for (int i = 1; i <= n - k + 1; i++) {
    ans = max(ans, get(i, i + k - 1, 1, n, 0, g));
}
cout << ans << '\n';