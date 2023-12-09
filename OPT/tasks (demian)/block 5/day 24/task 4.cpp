const int maxn = 3e5;

int n, m;
vector<int> arr(maxn), l(maxn, -1), r(maxn, -1), used(maxn, 0);
vector<int> ps, st, ans, _ans(maxn);

cin >> n >> m;
for (int i = 0; i < n; ++i) {
    cin >> arr[i];
}

for (int i = 0; i < n; ++i) {
    if (l[arr[i]] == -1) {
        l[arr[i]] = i;
    }
    r[arr[i]] = i;
}

ps.clear();

for (int i = 0; i < n; ++i) {
    if (l[arr[i]] == i) {
        ps.push_back(arr[i]);
    }
    if (r[arr[i]] == i) {
        ps.push_back(-arr[i]);
    }
}

for (int i = 0; i < (int)ps.size(); ++i) {
    if (ps[i] < 0) {
        ans.push_back(-ps[i]);
        st.pop_back();
    } else {
        st.push_back(ps[i]);
    }
}

reverse(ans.begin(), ans.end());
for (int i = 0; i < (int)ans.size(); i++) {
    for (int j = l[ans[i]]; j <= r[ans[i]]; j++) {
        _ans[j] = ans[i];
    }
}

if (_ans != arr) {
    cout << -1 << '\n';
} else {
    cout << (int)ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << " " << l[ans[i]] + 1 << " " << r[ans[i]] + 1 << '\n';
    }
}