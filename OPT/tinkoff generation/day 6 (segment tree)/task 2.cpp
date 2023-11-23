vector<int> tree;
vector<string> a;
int countZero = 0, n, p, k;
bool flag = true;
string result;

void update(int v, int l, int r, int i, int value) {
    if (l + 1 == r) {
        tree[v] = (value == 0) ? 1 : 0;
        return;
    }

    int m = l + (r - l) / 2;

    if (i < m)
        update(2 * v + 1, l, m, i, value);
    else
        update(2 * v + 2, m, r, i, value);

    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

void getAnswer(int v, int l, int r) {
    if (l + 1 == r) {
        k--;
        result += to_string(l + 1) + " ";
        return;
    }

    int m = l + (r - l) / 2;

    if (tree[2 * v + 1] >= k)
        getAnswer(2 * v + 1, l, m);
    else {
        k -= tree[2 * v + 1];
        getAnswer(2 * v + 2, m, r);
    }
}

void get(int v, int l, int r, int ql, int qr) {
    if (!flag) return;
    if (qr <= l || r <= ql) return;

    if (ql <= l && r <= qr) {
        if (countZero + tree[v] >= k) {
            k -= countZero;
            flag = false;
            getAnswer(v, l, r);
        } else {
            countZero += tree[v];
        }
        return;
    }

    int m = l + (r - l) / 2;

    get(2 * v + 1, l, m, ql, qr);
    get(2 * v + 2, m, r, ql, qr);
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        if (l < a.size())
            tree[v] = (stoi(a[l]) == 0) ? 1 : 0;
        else
            tree[v] = 0;
        return;
    }

    int m = l + (r - l) / 2;

    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);

    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

bool is2k(int x) {
    int a = 1;
    p = 0;
    while (true) {
        if (a == x) return true;
        if (a > x) return false;
        a *= 2;
        p++;
    }
}

cin >> n;
a.resize(n);
for (int i = 0; i < n; i++) cin >> a[i];
if (!is2k(n)) n = pow(2, p);

tree.resize(2 * n - 1);
build(0, 0, n);

int countRequests;
cin >> countRequests;
for (int i = 0; i < countRequests; i++) {
    string type;
    cin >> type;
    if (type == "u") {
        int index, value;
        cin >> index >> value;
        update(0, 0, n, index - 1, value);
    } else {
        int ql, qr;
        cin >> ql >> qr >> k;
        get(0, 0, n, ql - 1, qr);
        countZero = 0;
        flag = true;
        if (k != 0) {
            result += "-1 ";
        }
    }
}

result = result.substr(0, result.length() - 1);
cout << result << '\n';