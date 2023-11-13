
int a, b, c, d;
cin >> a >> b >> c >> d;

for (int i = a; i <= b; i++) {
    if (i % d == c) cout << i << " ";
}
cout << '\n';