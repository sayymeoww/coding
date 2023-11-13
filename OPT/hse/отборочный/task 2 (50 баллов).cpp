const int maxn = 2e5;

vector<int> a;
vector<vector<int>> mn;

void init(int n) {
    a.resize(n);
    int asize = n;
    for (int i = 0; i < n; i++) cin >> a[i];

    while ((1 << (log(a.size()))) != a.size()) {
        a.push_back(0);
        asize++;
    }

    mn.resize((log(asize)) + 1, vector<int>(maxn));

    for (int i = 0; i < asize; i++) mn[0][i] = a[i];
    for (int l = 0; l < (log(asize)); l++)
        for (int i = 0; i + (2 << l) <= asize; i++)
            mn[l + 1][i] = max(mn[l][i], mn[l][i + (1 << l)]);
}

int rmq(int l, int r) {
    int t = log(r - l);
    return max(mn[t][l], mn[t][r - (1 << t)]);
}

int n;
cin >> n;

init(n);

cout << *min_element(a.begin(), a.begin() + n) << " ";
for (int k = 2; k <= n; k++) {
    int temp = inf;
    for (int i = 1; i <= n - k + 1; i++)
        temp = min(temp, rmq(i - 1, i + k - 1));
    cout << temp << " ";
}
cout << '\n';