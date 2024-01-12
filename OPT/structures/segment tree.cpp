const int maxn = ...;

int a[maxn];      // массив
int t[4 * maxn];  // дерево

void build(int v, int tl, int tr) {
    if (tl == tr) return (void)(t[v] = a[tl]);

    int l = (v << 1);
    int r = (v << 1) + 1;
    int tm = (tl + tr) >> 1;

    build(l, tl, tm);
    build(r, tm + 1, tr);

    t[v] = t[l] + t[r];
}

void update(int v, int tl, int tr, int pos, int x) {
    if (tl == tr) return (void)(t[v] = x);

    int l = (v << 1);
    int r = (v << 1) + 1;
    int tm = (tl + tr) >> 1;

    if (pos <= tm)
        update(l, tl, tm, pos, x);
    else
        update(r, tm + 1, tm, pos, x);
}

int get(int v, int tl, int tr, int ql, int qr) {
    if (ql > qr) return 0;
    if (ql == tl && tr == qr) return t[v];

    int l = (v << 1);
    int r = (v << 1) + 1;
    int tm = (tl + tr) >> 1;

    return get(l, tl, tm, ql, min(tm, qr)) +
           get(r, tm + 1, tr, max(tm + 1, ql), qr);
}