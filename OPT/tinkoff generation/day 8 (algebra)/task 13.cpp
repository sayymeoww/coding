#define int long

int m;
cin >> m;

vector<int> r(m / 2 + 1);

r[1] = 1;

if (m == 1) {
    cout << r[1] << '\n';
    return 0;
}

int temp = r[1];
for (int i = 2; i < m; ++i) {
    if (i > m / 2) {
        int t = (m - (m / i) * r[m % i] % m) % m;
        temp = (temp + t) % m;
    } else {
        r[i] = (m - (m / i) * r[m % i] % m) % m;
        temp = (temp + r[i]) % m;
    }
    if (i % 100 == 0) {
        cout << temp << " ";
        temp = 0;
    }
}

if ((m - 1) % 100 != 0) cout << temp;
cout << '\n';
