class event {
    public:
        int x, type, index;
};

int n, m;
cin >> n >> m;

vector<event> ox;
for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;

    if (l > r) swap(l, r);

    event plus = {l, +1};
    event minus = {r, -1};

    ox.push_back(plus);
    ox.push_back(minus);
}

vector<int> answer(m);
for (int i = 0; i < m; i++) {
    int x;
    cin >> x;

    event point = {x, 0, i};
    ox.push_back(point);
}

auto lambda = [](event l, event r) {
    return l.x < r.x || l.x == r.x && l.type > r.type;
};
sort(ox.begin(), ox.end(), lambda);

int count = 0;
for (auto &el : ox) {
    if (el.type == +1) count++;
    if (el.type == -1) count--;
    if (el.type == 0) answer[el.index] = count;
}

for (auto &el : answer) cout << el << ' ';
cout << '\n';
