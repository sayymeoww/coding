map<char, ll> m;
string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void fill() {
    for (int i = 0; i < (int)a.length(); i++) {
        ll t = pow(10, i / 2);
        m[a[i]] = ((i % 2 == 1) ? 5 * t : t);
    }
    m['?'] = 0;
}

ll process(string s) {
    ll ans = 0;
    for (int i = 0; i < s.length(); i++) {
        char p = s[i];
        ll t = m[p];
        for (int j = i + 1; j < s.length(); j++) {
            if (m[s[j]] > m[p]) {
                t = -t;
                break;
            }
        }
        ans += t;
    }
    return ans;
}

int t;
cin >> t;

fill();

vector<int> ind;
while (t--) {
    string s, t, change;
    int mx, cur;

    cin >> s;

    ind.clear();
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '?') ind.push_back(i);
    }

    reverse(ind.begin(), ind.end());

    if (ind.size() != 0) {
        for (auto &i : ind) {
            mx = -inf;
            for (int j = 1; j < a.size(); j++) {
                t = s;
                t[i] = a[j];
                cur = process(t);
                if (process(t) > mx) {
                    mx = cur;
                    change = t;
                }
            }
            s = change;
        }
        cout << mx << '\n';
        cout << s << '\n';
    } else {
        cout << process(s) << '\n';
        cout << s << '\n';
    }
}