const int maxn = 40000000;

vector<int> lp(maxn + 1, 0);
vector<int> pr;

for (int i = 2; i <= maxn; i++) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= maxn;
         j++) {
        lp[i * pr[j]] = pr[j];
    }
}

int a, b;
cin >> a >> b;

int ans = 0;
for (int i = 0; i < (int)pr.size(); i++) {
    if (a <= pr[i] && pr[i] <= b) {
        if (i == 0) {
            if (abs(pr[i + 1] - pr[i]) == 2) {
                ans++;
            }
        } else if (i == pr.size() - 1) {
            if (abs(pr[i] - pr[i - 1]) == 2) {
                ans++;
            }
        } else {
            if (abs(pr[i + 1] - pr[i]) == 2 && abs(pr[i] - pr[i - 1]) == 2) {
                ans++;
            } else {
                if (abs(pr[i + 1] - pr[i]) == 2 ||
                    abs(pr[i] - pr[i - 1]) == 2) {
                    ans++;
                }
            }
        }
    }
}

cout << ans << '\n';