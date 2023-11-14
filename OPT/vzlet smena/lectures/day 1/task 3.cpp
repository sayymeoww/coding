bool check(string a, string b) {
    if (b == "bb") return true;
    if (b[0] == a[0]) return true;
    if (b[1] == a[1]) return true;
    return false;
}

string card;
cin >> card;

vector<int> answer;

for (int i = 0; i < 5; i++) {
    string f;
    cin >> f;
    if (check(card, f)) answer.push_back(i + 1);
}

if (answer.size() > 0) {
    cout << "YES" << '\n';
    for (auto &el : answer) cout << el << " ";
    cout << '\n';
} else {
    cout << "NO" << '\n';
}