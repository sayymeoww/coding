const int maxn = 1001;

int m, n, k;
vector<vector<double>> v(maxn, vector<double>(maxn, 0));

struct rect {
        int r, c, h, w, p;
};
vector<struct rect> R;

cin >> m >> n >> k;

R.resize(k);

for (int i = 0; i < k; i++)
    cin >> R[i].r >> R[i].c >> R[i].h >> R[i].w >> R[i].p;

auto comp = [](struct rect a, struct rect b) -> bool {
    return a.p * b.h * b.w < b.p * a.h * a.w;
};
sort(R.begin(), R.end(), comp);

for (struct rect &r : R) {
    double cost = r.p * 1.0 / (r.h * r.w);
    for (int x = r.r; x < r.r + r.h; x++)
        for (int y = r.c; y < r.c + r.w; y++) v[x][y] = cost;
}

double ans = 0;
for (int x = 0; x < m; x++)
    for (int y = 0; y < n; y++) ans += v[x][y];

cout << fixed << setprecision(10) << ans << '\n';