int ha, ma;
cin >> ha >> ma;

int hb, mb;
cin >> hb >> mb;

int a, b;
cin >> a >> b;
int total = (ha + hb - a + b) * 60 + ma + mb;

int days = total / (1440);

cout << (total / 60) % 24 << " " << total - (total / 60) * 60 << " " << days << '\n';