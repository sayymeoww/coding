using cow = pair<int, int>;

int f(int n, vector<cow> v, int s) {
    vector<int> u(s, 0);
    int cnt = 0;

    int x = 0, y = 0, temp;
    while (y < n) {
        temp = v[y].second;

        if (!u[temp]) cnt++;
        u[temp]++;

        if (cnt >= s) break;

        y++;
    }

    while (x < y) {
        temp = v[x].second;

        if (u[temp] <= 1) break;
        u[temp]--;

        x++;
    }

    return abs(v[y].first - v[x].first);
}

vector<pair<int, int>> u;
set<int> b;
map<int, int> inds;
int m;

void compress(int n, vector<cow> v) {
    for (int i = 0; i < n; i++) {
        if (b.count(v[i].second) == 0) {
            inds[v[i].second] = (int)b.size();
            b.insert(v[i].second);
        }
        u.push_back({v[i].first, inds[v[i].second]});
    }

    m = (int)b.size();
}

int n;
cin >> n;

vector<pair<int, int>> v(n);
for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

compress(n, v);
sort(u.begin(), u.end());

int l = f(n, u, m);
reverse(u.begin(), u.end());
int r = f(n, u, m);

cout << min(l, r) << '\n';