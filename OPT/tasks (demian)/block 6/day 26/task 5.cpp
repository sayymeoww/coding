set<int> merge(set<int> a, set<int> b) {
    set<int> c;
    for (auto &el : a) c.insert(el);
    for (auto &el : b) c.insert(el);
    return c;
}

const int maxn = 50;
int a[maxn], x[maxn], b[maxn], y[maxn];
set<int> ta[4 * maxn], tb[4 * maxn];

void builda(int v, int tl, int tr) {
    if (tl == tr) return (void)(ta[v] = {a[tl]});

    int l = (v << 1), r = (v << 1) + 1, tm = (tl + tr) >> 1;
    builda(l, tl, tm);
    builda(r, tm + 1, tr);

    ta[v] = merge(ta[l], ta[r]);
}

void buildb(int v, int tl, int tr) {
    if (tl == tr) return (void)(tb[v] = {b[tl]});

    int l = (v << 1), r = (v << 1) + 1, tm = (tl + tr) >> 1;
    buildb(l, tl, tm);
    buildb(r, tm + 1, tr);

    tb[v] = merge(tb[l], tb[r]);
}

set<int> geta(int v, int tl, int tr, int ql, int qr) {
    if (ql > qr) return {};
    if (ql == tl && tr == qr) return ta[v];

    int l = (v << 1), r = (v << 1) + 1, tm = (tl + tr) >> 1;

    return merge(geta(l, tl, tm, ql, min(qr, tm)),
                 geta(r, tm + 1, tr, max(ql, tm + 1), qr));
}

set<int> getb(int v, int tl, int tr, int ql, int qr) {
    if (ql > qr) return {};
    if (ql == tl && tr == qr) return tb[v];

    int l = (v << 1), r = (v << 1) + 1, tm = (tl + tr) >> 1;

    return merge(getb(l, tl, tm, ql, min(qr, tm)),
                 getb(r, tm + 1, tr, max(ql, tm + 1), qr));
}

bool check(set<int> a, set<int> b) {
    set<int> ans;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                     inserter(ans, ans.begin()));
    return (int)ans.size() == 0;
}

int px[maxn + 1], py[maxn + 1];

void buildpref() {
    px[0] = 0;
    for (int i = 0; i < maxn; i++) {
        px[i + 1] = px[i] + x[i];
    }

    py[0] = 0;
    for (int i = 0; i < maxn; i++) {
        py[i + 1] = py[i] + y[i];
    }
}

int sumx(int l, int r) { return px[r + 1] - px[l]; }
int sumy(int l, int r) { return py[r + 1] - py[l]; }

int n, m;
cin >> n >> m;

for (int i = 0; i < n; i++) cin >> a[i];
for (int i = 0; i < n; i++) cin >> x[i];

for (int i = 0; i < m; i++) cin >> b[i];
for (int i = 0; i < m; i++) cin >> y[i];

builda(1, 0, n - 1);
buildb(1, 0, m - 1);

buildpref();

int ans = -inf;
int ala, ara, alb, arb;

for (int lx = 0; lx < n; lx++) {
    for (int rx = lx; rx < n; rx++) {
        for (int ly = 0; ly < m; ly++) {
            for (int ry = ly; ry < m; ry++) {
                if (check(geta(1, 0, n - 1, lx, rx),
                          getb(1, 0, m - 1, ly, ry))) {
                    if (sumx(lx, rx) + sumy(ly, ry) > ans) {
                        ala = lx + 1;
                        ara = rx + 1;
                        alb = ly + 1;
                        arb = ry + 1;
                        ans = sumx(lx, rx) + sumy(ly, ry);
                    }
                }
            }
        }
    }
}

cout << ans << '\n';
cout << ala << " " << ara << '\n';
cout << alb << " " << arb << '\n';

if (sumx(0, n - 1) > ans) {
    ala = 1;
    ara = n;
    alb = 0;
    arb = 0;
    ans = sumx(0, n - 1);
}
if (sumy(0, m - 1) > ans) {
    ala = 0;
    ara = 0;
    alb = 1;
    arb = m;
    ans = sumy(0, m - 1);
}

cout << ans << '\n';
cout << ala << " " << ara << '\n';
cout << alb << " " << arb << '\n';