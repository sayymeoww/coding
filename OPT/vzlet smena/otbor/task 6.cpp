string res, s;

int n;
cin >> n;

int _n = n;
for (int i = 0; i < pow(2, _n); i++) {
    int k = i;
    s = "";
    for (int j = 0; j < n; j++) {
        if (k % 2 == 0)
            s = s + '0';
        else
            s = s + '1';
        k /= 2;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}