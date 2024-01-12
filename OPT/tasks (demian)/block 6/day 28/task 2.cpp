int get(int l, int p, int pos, int q) {
    int res = 0;
    for (int i = 0; i < l; i++) {
        if (i == pos)
            res = res * 10 + q;
        else
            res = res * 10 + p;
    }
    return res;
}

int n, mood;
cin >> n >> mood;

if (mood == 0) {
    int ans, delta = inf;
    for (int d = 0; d <= 9; d++) {
        for (int l = 1; l <= 18; l++) {
            int t = get(l, d, 0, d);
            if (t >= n && t - n < delta) {
                ans = t;
                delta = t - n;
            }
        }
    }
    cout << ans << '\n';
} else {
    int ans, delta = inf;
    for (int p = 0; p <= 9; p++) {
        for (int q = 0; q <= 9; q++) {
            for (int l = 1; l <= 18; l++) {
                for (int pos = 0; pos < l; pos++) {
                    int t = get(l, p, pos, q);
                    if (t >= n && t - n < delta) {
                        ans = t;
                        delta = t - n;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}