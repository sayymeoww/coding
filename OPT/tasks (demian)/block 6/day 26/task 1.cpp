const int maxn = 5e4 + 1;

int n;
char ans[maxn], t[4 * maxn];
int used[maxn] = {0};

void build(int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) return (void)(t[v] = used[tl]);

    int l = (v << 1), r = (v << 1) + 1, tm = (tl + tr) >> 1;
    build(l, tl, tm);
    build(r, tm + 1, tr);

    t[v] = t[l] + t[r];
}

int getsum(int ql, int qr, int v = 1, int tl = 0, int tr = n - 1) {
    if (ql > qr) return 0;
    if (ql == tl && tr == qr) return t[v];
    // if (ql <= tl && tr <= qr) return t[v];

    int l = (v << 1), r = (v << 1) + 1, tm = (tl + tr) >> 1;
    return getsum(ql, qr, l, tl, tm) + getsum(ql, qr, r, tm + 1, tr);
}

void update(int pos, int x, int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) return (void)(t[v] = x);

    int l = (v << 1), r = (v << 1) + 1, tm = (tl + tr) >> 1;
    if (pos <= tm)
        update(pos, x, l, tl, tm);
    else
        update(pos, x, r, tm + 1, tr);

    t[v] = t[l] + t[r];
}

int get(int pos, int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) return t[v];

    int l = (v << 1), r = (v << 1) + 1, tm = (tl + tr) >> 1;

    if (pos <= tm) return get(pos, v, tl, tm);
    return get(pos, v, tm + 1, tr);
}

void solve(int l, int r) {
    if (l >= r) return;
    if (getsum(0, n - 1) == n) return;

    cout << "? " << l + 1 << " " << r + 1 << '\n';

    string req;
    cin >> req;

    if (req == "Yes") {
        update(l, 1);
        update(r, 1);

        ans[l] = '(';
        ans[r] = ')';

        used[l] = 1;
        used[r] = 1;
    }

    solve(l, r - 1);
    solve(l + 1, r - 1);
    solve(r + 1, n - 1);
}

cin >> n;
build();
fill(ans, ans + maxn, '.');

if (n % 2) {
    cout << -1 << '\n';
    return 0;
}

solve(0, n - 1);

cout << "! ";
for (int i = 0; i < n; i++) cout << ans[i];
cout << '\n';

for (int i = 0; i < n; i++) cout << used[i] << " ";
cout << '\n';