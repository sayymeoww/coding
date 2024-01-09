const int maxn = 1e6 + 1;
int a[maxn], t[4 * maxn];

int n;

void build(int v, int tl, int tr) {
    if (tl == tr) return (void)(t[v] = a[tl]);

    int l = (v << 1), r = (v << 1), tm = (tl + tr) >> 1;
    build(l, tl, tm);
    build(r, tm + 1, tr);

    t[v] = max(t[l], t[r]);
}

void update(int v, int tl, int tr, int pos, int x) {
    if (tl == tr) return (void)(t[v] = x);

    int l = (v << 1), r = (v << 1), tm = (tl + tr) >> 1;
    if (pos <= tm)
        update(l, tl, tm, pos, x);
    else
        update(r, tm + 1, tr, pos, x);

    t[v] = max(t[l], t[r]);
}

int get(int v, int tl, int tr, int ql, int qr) {
    if (ql > qr) return -inf;
    if (ql == tl && tr == qr) return t[v];

    int l = (v << 1), r = (v << 1), tm = (tl + tr) >> 1;
    return max(get(l, tl, tm, ql, qr), get(r, tm + 1, tr, ql, qr));
}

int solve(int mx) {
    int ans = -1;
    for (int b = 0; b <= mx; b++) {
        int x = (a[0] ^ b);
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if ((a[i] ^ b) < x) {
                flag = false;
                break;
            } else
                x = (a[i] ^ b);
        }
        if (flag) return b;
    }
    return ans;
}

cin >> n;

for (int i = 0; i < n; i++) cin >> a[i];
build(1, 0, n - 1);

int mx = get(1, 0, n - 1, 0, n - 1);
cout << solve(mx) << '\n';

int q;
cin >> q;

int p, v;
while (q--) {
    cin >> p >> v;
    p--;
    mx = max(mx, v);
    a[p] = v;
    cout << solve(mx) << '\n';
}