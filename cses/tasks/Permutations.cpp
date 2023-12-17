int n;
cin >> n;

if (n == 1) cout << 1 << '\n';
if (n > 1 && n < 4) cout << "NO SOLUTION" << '\n';
if (n == 4) cout << "2 4 1 3" << '\n';

for (int i = 1; i <= n; i += 2) cout << i << " ";
for (int i = 2; i <= n; i += 2) cout << i << " ";
cout << '\n';