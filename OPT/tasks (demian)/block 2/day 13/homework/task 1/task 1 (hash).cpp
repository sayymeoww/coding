int code(pair<int, int> coords) {
    return coords.first * coords.first + coords.second;
}

pair<int, int> decode(int hash) {
    int temp = (int)sqrt(hash);
    return {temp, hash - temp * temp};
}

int left(int hash) {
    int temp = (int)sqrt(hash);
    return hash + 2 * temp + 1;
}

int right(int hash) {
    int temp = (int)sqrt(hash);
    return hash + 2 * temp + 2;
}

set<pair<int, int>> generate(int n, vector<int> changes) {
    vector<bool> path(n, true);
    set<pair<int, int>> answer;

    for (int i = 0; i < n; i++) {
        int h = code({i, i});
        answer.insert({h, right(h)});
    }

    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        x = 0;
        y = 0;

        path[changes[i] - 1] = false;

        for (bool rot : path) {
            int h = code({x, y});
            if (rot) {
                answer.insert({h, right(h)});
                y++;
            } else {
                answer.insert({h, left(h)});
            }
            x++;
        }
    }

    return answer;
}

set<int> path(map<int, set<int>> tree, int current, set<int> answer) {
    answer.insert(current);
    if (current == 0) return answer;
    for (auto [node, value] : tree)
        if (tree[node].count(current)) return path(tree, node, answer);
    return answer;
}

int algo(set<int> first, set<int> second) {
    if (first.size() > second.size()) return algo(second, first);

    vector<int> f;
    for (auto el : first) f.push_back(el);
    sort(f.begin(), f.end());

    int l = 0;
    int r = first.size() - 1;

    int el = f[r];

    if (second.count(el)) return el;

    while (r - l != 1) {
        int m = (r + l) / 2;
        if (second.count(f[m]))
            l = m;
        else
            r = m;
    }

    return f[l];
}

int n;
cin >> n;

vector<int> rotations(n);
for (int i = 0; i < n; i++) cin >> rotations[i];

set<pair<int, int>> edges = generate(n, rotations);

map<int, set<int>> tree;
for (int i = 0; i <= n * (n + 1); i++) {
    tree[i] = {};
    if (edges.count({i, left(i)})) tree[i].insert(left(i));
    if (edges.count({i, right(i)})) tree[i].insert(right(i));
}

int t;
cin >> t;
while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    set<int> first = path(tree, code({a, b}), {0});
    set<int> second = path(tree, code({c, d}), {0});

    pair<int, int> answer = decode(algo(first, second));

    cout << answer.first << " " << answer.second << '\n';
}