struct rect {
    int x, y;
    rect(int x, int y) : x(x), y(y) {}
    rect() : x(0), y(0) {}
};

int ar(struct rect a) { return a.x * a.y; }

struct rect operator+(const struct rect a, const struct rect b) {
    return {min(a.x, b.x), min(a.y, b.y)};
}

vector<struct rect> r;
void build(int n) {
    int ansi, ansj;
    vector<struct rect> ans;

    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int t = ar(r[i] + r[j]);
                if (t > mx) {
                    mx = t;
                    ansi = i;
                    ansj = j;
                }
            }
        }
    }

    ans.push_back(r[ansi] + r[ansj]);
    for (int i = 0; i < n; i++) {
        if (i != ansi && i != ansj) ans.push_back(r[i]);
    }

    r = ans;
}

int n, k;
cin >> n >> k;

r.resize(n, {});
for (int i = 0; i < n; i++) cin >> r[i].x >> r[i].y;

if (k == 1) {
    int ans = 0;

    for (struct rect &el : r) {
        if (ar(el) > ans) ans = ar(el);
    }

    cout << ans << '\n';
} else if (k == 2) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int t = ar(r[i] + r[j]);
                if (t > ans) ans = t;
            }
        }
    }

    cout << ans << '\n';
} else {
    build(n);
    k -= 2;

    vector<bool> used((int)r.size(), false);

    while (k) {
        int mx = 0, ai;
        for (int i = 1; i < r.size(); i++) {
            if (!used[i]) {
                int t = ar(r[0] + r[i]);
                if (t > mx) {
                    mx = t;
                    ai = i;
                }
            }
        }
        r[0] = r[0] + r[ai];
        used[ai] = true;
        k--;
    }

    cout << ar(r[0]) << '\n';
}