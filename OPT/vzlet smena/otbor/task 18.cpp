int n;
cin >> n;

vector<int> v(n);
for (int i = 0; i < n; i++) cin >> v[i];

int x;
cin >> x;

int dif = inf, ind;
for (int i = 0; i < n; i++) {
    if (abs(x - v[i]) < dif) {
        dif = abs(x - v[i]);
        ind = i;
    }
}

cout << v[ind] << '\n';