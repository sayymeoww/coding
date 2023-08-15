int s, n, k, a, b;
cin >> s >> n >> k >> a >> b;

int x, y;
x = n;
s -= x * a;

if (s / b > k)
    y = k;
else
    y = s / b;

s -= y * b;

x += s / a;

cout << x << " " << y << '\n';
