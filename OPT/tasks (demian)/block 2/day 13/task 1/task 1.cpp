int n;
cin >> n;

map<int, int> tower;

for (int i = 0; i < n; i++) {
    int h, w;
    cin >> h >> w;
    tower[h] = max(tower[h], w);
}

int answer = 0;
for (auto [h, w] : tower) {
    answer += w;
}

cout << answer << '\n';