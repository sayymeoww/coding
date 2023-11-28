#define int long
const int maxn = 1e8;

vector<int> ans(maxn / 100 + 1, 0);

vector<int> p;
vector<bool> d(maxn + 1, false);
vector<int> phi(maxn + 1);

int n;
cin >> n;

if (n == 1) {
    cout << 1 << '\n';
    return 0;
}

phi[1] = 1;
for (int i = 2; i <= n; i++) {
    if (!d[i]) {
        p.push_back(i);
        phi[i] = i - 1;
    }
    for (int j = 0; j < (int)p.size() && i * p[j] <= n; j++) {
        d[i * p[j]] = true;
        if (i % p[j] == 0) {
            phi[i * p[j]] = phi[i] * p[j];
            break;
        } else {
            phi[i * p[j]] = phi[i] * phi[p[j]];
        }
    }
}

int temp = 1;
for (int i = 2; i <= n; i++) {
    temp += phi[i];
    if (i % 100 == 0) {
        cout << temp << " ";
        temp = 0;
    }
}

if (n % 100 != 0) {
    cout << temp;
}
cout << '\n';