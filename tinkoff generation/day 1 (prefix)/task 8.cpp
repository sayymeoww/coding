int n, m;
cin >> n >> m;

vector<vector<int>> v(n, vector<int>(m));
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cin >> v[i][j];
    }
}

int answer = 0;
vector<int> d(m, -1), d1(m), d2(m);
stack<int> s;

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (v[i][j] == 1) d[j] = i;
    }

    while (!s.empty()) s.pop();

    for (int j = 0; j < m; j++) {
        while (!s.empty() && d[s.top()] <= d[j]) s.pop();

        d1[j] = (s.empty() ? -1 : s.top());
        s.push(j);
    }

    while (!s.empty()) s.pop();
    for (int j = m - 1; j >= 0; j--) {
        while (!s.empty() && d[s.top()] <= d[j]) s.pop();

        d2[j] = (s.empty() ? m : s.top());

        s.push(j);
    }

    for (int j = 0; j < m; j++) {
        answer = max(answer, (i - d[j]) * (d2[j] - d1[j] - 1));
    }
}

cout << answer << '\n';