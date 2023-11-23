const int MOD = 1e9 + 7;
vector<int> tree, cnt, dpCount, a, t;
int initialN;
int n;

void create(int v) {
    if (tree[2 * v + 1] > tree[2 * v + 2]) {
        tree[v] = tree[2 * v + 1];
        cnt[v] = cnt[2 * v + 1] % MOD;
    } else if (tree[2 * v + 2] > tree[2 * v + 1]) {
        tree[v] = tree[2 * v + 2];
        cnt[v] = cnt[2 * v + 2] % MOD;
    } else {
        tree[v] = tree[2 * v + 1];
        if (tree[v] != 0) {
            cnt[v] = (cnt[2 * v + 1] + cnt[2 * v + 2]) % MOD;
        } else {
            cnt[v] = cnt[2 * v + 1] % MOD;
        }
    }
}

void update(int v, int l, int r, int i, int value, int newCount, int type) {
    if (l + 1 == r) {
        if (type == 0 || value > tree[v])
            cnt[v] = newCount % MOD;
        else
            cnt[v] = (cnt[v] + newCount) % MOD;
        tree[v] = value;
        return;
    }

    int m = l + (r - l) / 2;

    if (i < m)
        update(2 * v + 1, l, m, i, value, newCount, type);
    else
        update(2 * v + 2, m, r, i, value, newCount, type);

    create(v);
}

vector<int> get(int v, int l, int r, int ql, int qr) {
    if (qr <= l || ql >= r) return {0, 1};
    if (ql <= l && r <= qr) return {tree[v], cnt[v] % MOD};

    int m = (l + r) / 2;
    vector<int> maxLeftChild = get(2 * v + 1, l, m, ql, qr);
    vector<int> maxRightChild = get(2 * v + 2, m, r, ql, qr);

    if (maxLeftChild[0] > maxRightChild[0])
        return maxLeftChild;
    else if (maxRightChild[0] > maxLeftChild[0])
        return maxRightChild;
    else if (maxLeftChild[0] != 0)
        return {maxLeftChild[0], (maxLeftChild[1] + maxRightChild[1]) % MOD};
    else
        return {maxLeftChild[0], max(maxLeftChild[1], maxRightChild[1]) % MOD};
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = 0;
        cnt[v] = 1;
        return;
    }

    int m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);

    create(v);
}

void coordComp() {
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());

    unordered_map<int, int> map;
    for (int i = 0; i < initialN; i++) map[b[i]] = i;
    for (int i = 0; i < initialN; i++) a[i] = map[a[i]];
}

int to2k(int x) {
    int a = 1;
    int pow = 0;
    while (true) {
        if (a >= x) return pow;
        a *= 2;
        pow++;
    }
}

cin >> initialN;
a.resize(initialN);
for (int i = 0; i < initialN; i++) cin >> a[i];

n = pow(2, to2k(initialN));
tree.resize(2 * n - 1);
cnt.resize(2 * n - 1);
dpCount.resize(initialN);
t.resize(initialN);

coordComp();
for (int i = 0; i < initialN; i++) t[a[i]] = 0;

build(0, 0, n);
unordered_set<int> S;
for (int i = 0; i < initialN; i++) {
    vector<int> max_count = get(0, 0, n, 0, a[i]);
    int type = (S.count(a[i])) ? 1 : 0;
    update(0, 0, n, a[i], max_count[0] + 1, max_count[1], type);
    if (type == 0 || (t[a[i]] < max_count[0] + 1))
        dpCount[a[i]] = max_count[1] % MOD;
    else
        dpCount[a[i]] = (dpCount[a[i]] + max_count[1]) % MOD;
    t[a[i]] = max_count[0] + 1;
    S.insert(a[i]);
}

S.clear();
int maxValue = 0, ans = 0;
for (int i = 0; i < initialN; i++) maxValue = max(maxValue, t[a[i]]);
for (int i = 0; i < initialN; i++) {
    if (t[a[i]] == maxValue && !S.count(a[i])) {
        ans = (ans + dpCount[a[i]]) % MOD;
        S.insert(a[i]);
    }
}

cout << ans << '\n';
