int d, m, w;
int i, j, k;

cin >> d >> m >> w;
cin >> i >> j >> k;

cout << char('a' + ((k - 1) * m * d + (j - 1) * d + i - 1) % w) << '\n';