int n, p;
vector<vector<int>> order, pos;
vector<int> cur;
vector<bool> c, m;

void dfs() {
    bool flag = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || pos[j][cur[i]] >= pos[j][cur[j]]) continue;

            int was = cur[j];
            cur[j] = cur[i];

            dfs();

            cur[j] = was;
            flag = true;
        }
    }

    if (!flag) {
        vector<bool> used(n, false);

        for (int i = 0; i < n; i++) {
            m[cur[i]] = true;
            used[cur[i]] = true;
        }

        for (int i = 0; i < n; i++)
            if (!used[i]) c[i] = false;
    }
}

cin >> n;

order.resize(n, vector<int>(n));
pos.resize(n, vector<int>(n));
cur.resize(n);
c.assign(n, true);
m.assign(n, false);

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cin >> order[i][j];
        order[i][j]--;

        pos[i][order[i][j]] = j;
    }
}

for (int i = 0; i < n; i++) cur[i] = i;

dfs();

cin >> p;
vector<int> ans;
for (int i = 0; i < n; i++) {
    if ((p == 1 && c[i]) || (p == 2 && m[i])) ans.push_back(i);
}

cout << (int)ans.size() << '\n';
for (auto &el : ans) cout << el + 1 << " ";
cout << '\n';