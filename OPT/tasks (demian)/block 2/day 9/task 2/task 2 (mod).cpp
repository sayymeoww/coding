using vect = vector<vector<int>>;

struct tree {
    vect a, b;

    void create();

    int get(int i, int tl, int tr, int l, int r, int f);
    void add(int i, int tl, int tr, int f);
    void update(int i, int tl, int tr, int l, int r, int f);

    void set(int n);
};

void tree::create() {
    this->a.resize(2, vector<int>(3 * 1e6));
    this->b.resize(2, vector<int>(3 * 1e6));
}

void tree::add(int i, int tl, int tr, int level) {
    if (this->b[level][i]) {
        this->a[level][i] = (tr - tl) - this->a[level][i];
        if (tl != tr - 1) {
            this->b[level][2 * i + 1] =
                (this->b[level][i] + this->b[level][2 * i + 1]) % 2;
            this->b[level][2 * i + 2] =
                (this->b[level][i] + this->b[level][2 * i + 2]) % 2;
        }
        this->b[level][i] = 0;
    }
}

void tree::update(int i, int tl, int tr, int l, int r, int level) {
    add(i, tl, tr, level);

    if (tl >= r || tr <= l) return;
    if (l <= tl && tr <= r) {
        this->b[level][i] = 1 - this->b[level][i];
        add(i, tl, tr, level);
        return;
    }

    int tm = (tl + tr) / 2;

    update(2 * i + 1, tl, tm, l, r, level);
    update(2 * i + 2, tm, tr, l, r, level);

    this->a[level][i] = this->a[level][2 * i + 1] + this->a[level][2 * i + 2];
}

int tree::get(int i, int tl, int tr, int l, int r, int level) {
    add(i, tl, tr, level);

    if (tl >= r || tr <= l) return 0;
    if (l <= tl && tr <= r) return this->a[level][i];

    int tm = (tl + tr) / 2;

    return get(2 * i + 1, tl, tm, l, r, level) +
           get(2 * i + 2, tm, tr, l, r, level);
}

void tree::set(int n) {
    int el;
    for (int i = 0; i < n; i++) {
        cin >> el;
        if (el) update(0, 0, n, i / 2, i / 2 + 1, i % 2);
    }
}

int n, el;
cin >> n;

int t;
cin >> t;

tree T;
T.create();
T.set(n);

while (t--) {
    int type, l, r;
    cin >> type >> l >> r;
    l--;

    if (type == 1) {
        if (l % 2 == 0)
            T.update(0, 0, n, (l + 1) / 2, (r - 1) / 2 + 1, 0);
        else
            T.update(0, 0, n, l / 2, r / 2, 1);
    } else {
        if (l % 2 == 0)
            cout << T.get(0, 0, n, (l + 1) / 2, (r - 1) / 2 + 1, 0) +
                        T.get(0, 0, n, (l + 1) / 2, r / 2, 1)
                 << '\n';
        else
            cout << T.get(0, 0, n, l / 2 + 1, (r - 1) / 2 + 1, 0) +
                        T.get(0, 0, n, l / 2, r / 2, 1)
                 << '\n';
    }
}