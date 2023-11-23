int n, w;
cin >> n >> w;

vector<int> v(n);
for (int i = 0; i < n; i++) cin >> v[i];

bitset<6250000> b;
b[0] = 1;
for (int i = 0; i < n; i++) b |= b << v[i];

cout << (b[w] ? "YES" : "NO") << '\n';
