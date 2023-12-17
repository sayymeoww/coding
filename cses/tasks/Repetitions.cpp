string s;
getline(cin, s);

int mx = 1, t = 1, n = (int)s.length();
for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
        t++;
    } else {
        mx = max(mx, t);
        t = 1;
    }
}

mx = max(mx, t);

cout << mx << '\n';