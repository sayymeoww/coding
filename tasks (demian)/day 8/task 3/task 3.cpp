vector<int> z_function(string s) {
    int n = (int)s.length();
    vector<int> z(n);

    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

ifstream f("test.txt");

int t;
f >> t;

vector<string> v;

while (t--) {
    string s;
    f >> s;
    v.push_back(s);
}

int length = (int)v.size();
for (int i = 0; i < length; i++) {
    int m = -inf;
    int index;
    for (int j = 0; j < length; j++) {
        if (i != j) {
            string a = v[i];
            string b = v[j];

            int pref = z_function(a + b)[(int)a.length()];

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());

            int suf = z_function(a + b)[(int)a.length()];

            int close = pref + suf;
            if (close > m) {
                index = j + 1;
                m = close;
            }
        }
    }

    cout << index << " ";
}
cout << '\n';