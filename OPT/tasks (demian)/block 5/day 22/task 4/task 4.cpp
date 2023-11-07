int f(vector<int> a) {
    int d[300001];

    int n = (int)a.size();
    for (int i = 0; i < n; ++i) {
        d[i] = 1;
        for (int j = 0; j < i; ++j)
            if (a[j] < a[i]) d[i] = max(d[i], 1 + d[j]);
    }

    int ans = d[0];
    for (int i = 0; i < n; ++i) ans = max(ans, d[i]);

    return ans;
}

vector<int> g(vector<int> v, int k) {
    vector<int> ans;
    for (int i = 0; i < k; i++)
        for (auto &el : v) ans.push_back(el);
    return ans;
}

int n;
cin >> n;

vector<int> a(n);
for (int i = 0; i < n; i++) cin >> a[i];

int k = 1;
vector<int> A = a;
reverse(a.begin(), a.end());
for (auto &el : a) A.push_back(el);

while (!(f(g(A, k)) == n)) k++;

cout << k << '\n';
