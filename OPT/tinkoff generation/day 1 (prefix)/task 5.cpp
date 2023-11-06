int a, b, cur = 0, maxn = (1 << 24);
int nextRand() {
    cur = cur * a + b;
    return (cur >> 8);
}

int m, q;
cin >> m >> q >> a >> b;

vector<int> v(maxn, 0);
for (int i = 0; i < m; i++) {
    int add = nextRand(), l = nextRand(), r = nextRand();
    if (l > r) swap(l, r);

    v[l] += add;
    if (r + 1 < maxn) v[r + 1] -= add;
}

vector<int> pref(maxn, 0);
int current = v[0];
pref[0] = current;

for (int i = 1; i < maxn; i++) {
    current += v[i];
    pref[i] = pref[i - 1] + current;
}

int answer = 0;
for (int i = 0; i < q; i++) {
    int l = nextRand(), r = nextRand();

    if (l > r) swap(l, r);
    if (l != 0)
        answer += pref[r] - pref[l - 1];
    else
        answer += pref[r];
}

cout << answer << '\n';