vector<int> n(4);
vector<vector<int>> v(4);

int el;
for (int i = 0; i < 4; i++) {
    cin >> n[i];
    for (int j = 0; j < n[i]; j++) {
        cin >> el;
        v[i].push_back(el);
    }
    sort(v[i].begin(), v[i].end());
}

int a = 0, b = 0, c = 0, d = 0;
int ma = a, mb = b, mc = c, md = d;

int mn = min({v[0][0], v[1][0], v[2][0], v[3][0]});
int mx = max({v[0][0], v[1][0], v[2][0], v[3][0]});

int diff = abs(mx - mn);

while (a < n[0] && b < n[1] && c < n[2] && d < n[3]) {
    mn = min({v[0][a], v[1][b], v[2][c], v[3][d]});
    mx = max({v[0][a], v[1][b], v[2][c], v[3][d]});

    int newd = abs(mx - mn);

    if (newd < diff) {
        diff = newd;
        ma = a;
        mb = b;
        mc = c;
        md = d;
    }

    if (newd < 1) break;

    while (a < (int)v[0].size() && mn == v[0][a]) a++;
    while (b < (int)v[1].size() && mn == v[1][b]) b++;
    while (c < (int)v[2].size() && mn == v[2][c]) c++;
    while (d < (int)v[3].size() && mn == v[3][d]) d++;
}

cout << v[0][ma] << " " << v[1][mb] << " " << v[2][mc] << " " << v[3][md]
     << '\n';
