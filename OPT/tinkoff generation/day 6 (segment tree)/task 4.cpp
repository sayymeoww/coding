vector<int> vertex, tree, ind;
vector<string> a;
int n, q;

void update(int v, int l, int r, int i, int value) {
    if (l + 1 == r) {
        tree[v] = value;
        return;
    }

    int m = l + (r - l) / 2;
    if (i < m)
        update(2 * v + 1, l, m, i, value);
    else
        update(2 * v + 2, m, r, i, value);

    if (tree[2 * v + 1] >= tree[2 * v + 2]) {
        tree[v] = tree[2 * v + 1];
        ind[v] = ind[2 * v + 1];
    } else {
        tree[v] = tree[2 * v + 2];
        ind[v] = ind[2 * v + 2];
    }
}

void get(int v, int l, int r, int ql, int qr, int x) {
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr) {
        if (tree[v] >= x) {
            vertex.push_back(v);
            vertex.push_back(l);
            vertex.push_back(r);
        }
        return;
    }

    int m = l + (r - l) / 2;

    get(2 * v + 1, l, m, ql, qr, x);
    get(2 * v + 2, m, r, ql, qr, x);
}

int get(int v, int l, int r, int x) {
    if (l + 1 == r) return ind[v];
    if (tree[2 * v + 1] >= x) return get(2 * v + 1, l, l + (r - l) / 2, x);
    return get(2 * v + 2, l + (r - l) / 2, r, x);
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = (l < a.size() ? stoi(a[l]) : INT_MIN);
        ind[v] = (l < a.size() ? l : INT_MAX);
        return;
    }

    int m = l + (r - l) / 2;

    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);

    if (tree[2 * v + 1] >= tree[2 * v + 2]) {
        tree[v] = tree[2 * v + 1];
        ind[v] = ind[2 * v + 1];
    } else {
        tree[v] = tree[2 * v + 2];
        ind[v] = ind[2 * v + 2];
    }
}

bool is2k(int x) {
    int a = 1;
    q = 0;
    while (true) {
        if (a == x) return true;
        if (a > x) return false;
        a *= 2;
        q++;
    }
}

int m;
cin >> n >> m;

a.resize(n);
for (int i = 0; i < n; i++) cin >> a[i];
if (!is2k(n)) n = pow(2, q);

tree.resize(2 * n - 1);
ind.resize(2 * n - 1);
build(0, 0, n);

for (int i = 0; i < m; i++) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type == 0) {
        update(0, 0, n, x - 1, y);
    } else {
        get(0, 0, n, x - 1, n, y);
        if (vertex.empty()) {
            cout << -1 << '\n';
        } else {
            cout << get(vertex[0], vertex[1], vertex[2], y) + 1 << '\n';
            vertex.clear();
        }
    }
}