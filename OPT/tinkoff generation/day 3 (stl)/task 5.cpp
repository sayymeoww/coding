vector<pair<int, int>> prufer(const vector<int>& prufer_code) {
    int n = (int)prufer_code.size() + 2;
    vector<int> degree(n, 1);
    for (int i = 0; i < n - 2; ++i) ++degree[prufer_code[i]];

    set<int> leaves;
    for (int i = 0; i < n; ++i)
        if (degree[i] == 1) leaves.insert(i);

    vector<pair<int, int>> result;
    for (int i = 0; i < n - 2; ++i) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());

        int v = prufer_code[i];
        result.push_back({leaf, v});
        if (--degree[v] == 1) leaves.insert(v);
    }

    result.push_back({*leaves.begin(), *(--leaves.end())});

    return result;
}

int n;
cin >> n;

vector<int> code(n - 2);
for (int i = 0; i < n - 2; i++) {
    cin >> code[i];
    code[i]--;
}

vector<pair<int, int>> answer = prufer(code);
for (auto& el : answer) {
    cout << el.first + 1 << " " << el.second + 1 << '\n';
}