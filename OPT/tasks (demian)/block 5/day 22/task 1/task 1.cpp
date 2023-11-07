const int maxn = 63000 + 1;

int n;
cin >> n;

vector<int> f(maxn, 0);
f[n - 1] = 1;

int dif = 1, ind;
for (int i = n; i < maxn; i++) {
    f[i] = dif;
    if (f[i] > 63000) {
        ind = i;
        break;
    }
    dif = dif - f[i - n] + f[i];
}

vector<int> ans(f[ind - 1] + 1, 0);

for (int i = 0; i < ind; i++) {
    ans[f[i]] = 1;
}

int a, b;
cin >> a >> b;
if (a > b) swap(a, b);

for (int i = a; i <= b; i++) cout << ans[i];
cout << '\n';