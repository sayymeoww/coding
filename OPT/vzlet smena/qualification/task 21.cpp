int maxn = 102;
vector<int> f(maxn);

int n;
cin >> n;

f[1] = 1;
f[2] = 2;
for (int i = 3; i < maxn; i++) f[i] = f[i - 1] + f[i - 2];

cout << f[n + 1] << '\n';