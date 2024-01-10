const int maxn = 1e4 + 1;
int t[maxn][maxn] = {0};

int n, m, q;
void update() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t[i][j]++;
        }
    }
}

void clearline(int line) {
    for (int j = 0; j < m; j++) {
        t[line][j] = 0;
    }
}

void clearrow(int row) {
    for (int i = 0; i < n; i++) {
        t[i][row] = 0;
    }
}

vector<pair<int, int>> dir = {
        {-1, 0},
        {+1, 0},
        {0, -1},
        {0, +1}
};

int bfs(int r1, int c1, int r2, int c2, int k) {
    queue<pair<int, int>> qu;
    qu.push({r1, c1});

    map<pair<int, int>, int> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[{i, j}] = -1;
        }
    }
    d[{r1, c1}] = 0;

    while (!qu.empty()) {
        pair<int, int> v = qu.front();
        qu.pop();

        if (t[v.first][v.second] <= k) {
            for (auto [dx, dy] : dir) {
                pair<int, int> u = {v.first + dx, v.second + dy};
                if (t[u.first][u.second] <= k) {
                    if (d[u] == -1) {
                        qu.push(u);
                        d[u] = d[v] + 1;
                    }
                }
            }
        }
    }

    return d[{r2, c2}];
}

cin >> n >> m >> q;
while (q--) {
    update();

    int req;
    cin >> req;

    if (req == 1) {
        int line;
        cin >> line;
        clearline(line - 1);
    } else if (req == 2) {
        int row;
        cin >> row;
        clearrow(row - 1);
    } else {
        int r1, c1, r2, c2, k;
        cin >> r1 >> c1 >> r2 >> c2 >> k;

        cout << bfs(r1 - 1, c1 - 1, r2 - 1, c2 - 1, k) << '\n';
    }
}