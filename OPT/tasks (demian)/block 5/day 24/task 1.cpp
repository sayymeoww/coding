string s = "";

string get(string &s, int from, int len) {
    string ans = "";
    int cnt = 0;
    for (int i = from; cnt < len; i++, cnt++) {
        ans += s[i];
    }
    return ans;
}

void process(int p, int l) {
    string t = "";
    int cnt = 0;
    for (int i = p - 1; cnt < l; i++, cnt++) {
        t += s[i % s.size()];
    }
    s += t;
}

int m, n;
cin >> m >> n;

string p;
cin >> p;

while (n--) {
    int c;
    cin >> c;

    if (c == 1) {
        string t;
        cin >> t;
        s += t;
    } else {
        int pos, len;
        cin >> pos >> len;
        process(pos, len);
    }
}

int ans = 0, P = 0;
while ((P = s.find(p, P)) != s.npos) {
    ++ans;
    ++P;
}

cout << ans << '\n';