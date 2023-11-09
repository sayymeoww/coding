int n, m, k, pos;
cin >> n >> m;

char c;
string s;
cin >> s;

vector<vector<pair<int, char>>> chars(n), poses(m);
vector<int> bad(n);

for (int i = 0; i < n; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) {
        cin >> pos >> c;
        pos--;

        chars[i].push_back({pos, c});
        poses[pos].push_back({i, c});

        if (c != s[pos]) bad[i]++;
    }
}

vector<bool> perf(n, false), poss(m, false);

vector<int> p;
set<pair<int, int>> q;

for (int i = 0; i < n; i++) q.insert({bad[i], i});

while (!q.empty()) {
    auto it = q.begin();
    int card = it->second;

    if (bad[card] != 0) break;

    q.erase(it);
    p.push_back(card);

    perf[card] = true;

    for (auto [pos, c] : chars[card])
        if (!poss[pos]) {
            poss[pos] = true;
            for (auto [badd, c2] : poses[pos]) {
                if (!perf[badd] && c2 != c) {
                    q.erase({bad[badd], badd});
                    bad[badd]--;
                    q.insert({bad[badd], badd});
                }
            }
        }
}

bool flag = true;
for (bool have : poss) flag &= have;

if (p.size() != n || !flag)
    cout << -1 << '\n';
else
    print(p);