const int maxk = 26;
const int maxn = 5e5;

int a[maxk][maxk];

int k, n;
cin >> k >> n;

for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
        cin >> a[i][j];
    }
}

string s;
cin >> s;

int cnt;
string p = s;
do {
    cnt = 0;
    if (s.length() == 1) break;
    for (int i = 1; i < (int)s.length(); i++) {
        if (a[s[i - 1] - 'a'][s[i] - 'a']) {
            cnt++;
            p = min(p, get(s, i));
        }
    }
    s = p;
} while (cnt != 0);

cout << s << '\n';