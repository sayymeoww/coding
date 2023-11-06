bool check(vector<int> a, int p, int k, int index) {
    vector<bool> white((int)a.size(), false);
    white[index] = true;
    bool flag = true;

    int steps = 1, n = (int)a.size();
    if (steps == k && flag && white[p - 1]) return true;

    int l = index - 1, r = index + 1;

    while (true) {
        if (l == -1 && r == n) break;

        if (!white[p - 1])
            flag = true;
        else
            flag = false;

        if (l == -1) {
            white[r] = true;
            r++;
        } else if (r == n) {
            white[l] = true;
            l--;
        } else {
            if (a[l] < a[r]) {
                white[l] = true;
                l--;
            } else {
                white[r] = true;
                r++;
            }
        }

        steps++;
        if (steps == k)
            if (flag && white[p - 1])
                return true;
            else
                return false;
        else if (steps > k)
            return false;
    }

    return false;
}

int solve(vector<int> a, int p, int k) {
    int answer = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (check(a, p, k, i)) answer++;
    }
    return answer;
}

int n, q;
cin >> n >> q;

vector<int> a(n);
for (int i = 0; i < n; i++) {
    cin >> a[i];
}

while (q--) {
    int p, k;
    cin >> p >> k;
    cout << solve(a, p, k) << '\n';
}