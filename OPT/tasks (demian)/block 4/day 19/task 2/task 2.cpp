int n, m, r;
string answer;

int f(string s, string temp) {
    int ans = 0;
    bool flag = false;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (flag) {
            if (s[i] != temp[i]) {
                cur++;
            } else {
                ans = max(ans, cur);
                cur = 0;
                flag = false;
            }
        } else {
            if (s[i] != temp[i]) {
                cur = 1;
                flag = true;
            }
        }
    }
    ans = max(ans, cur);
    return ans;
}

cin >> n >> m >> r;
cin >> answer;

int x, maxx;
string temp;
for (int i = 0; i < m; i++) {
    cin >> temp;
    x = f(answer, temp);
    cout << x << '\n';
    maxx = max(maxx, x);
}

if (maxx >= r)
    cout << "YES" << '\n';
else
    cout << "NO" << '\n';