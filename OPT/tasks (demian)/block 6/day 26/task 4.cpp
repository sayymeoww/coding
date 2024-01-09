vector<pair<int, char>> f(string s) {
    vector<pair<int, char>> v;

    for (char c : s) {
        if (!v.empty() && v.back().second == c) {
            ++v.back().first;
        } else {
            v.push_back({1, c});
        }
    }
    return v;
}

void go_stack(vector<pair<int, char>> &st) {
    char c = st.back().second;
    while (st.size() >= 2 && st.back().first > st[st.size() - 2].first) {
        int val = st.back().first;
        st.pop_back();
        val += st.back().first;
        st.pop_back();
        if (st.empty()) {
            st.push_back({val, c});
        } else {
            st.back().first += val;
        }
    }
}

void solve() {
    string s, t;
    cin >> s >> t;

    auto v = f(s);

    vector<pair<int, char>> st;
    for (auto j : v) {
        if (j.second == '+') {
            if (st.empty() || st.back().second != j.second) {
                st.push_back(j);
            } else {
                st.back().first += j.first;
            }
            go_stack(st);
        } else {
            if (st.empty() || st.back().first <= j.first) {
                st.push_back(j);
            } else {
                st.back().first += j.first;
                go_stack(st);
            }
        }
    }

    if (st.size() > 1 || st[0].second != '+') {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
    return;
}

int t;
cin >> t;
while (t--) {
    solve();
}