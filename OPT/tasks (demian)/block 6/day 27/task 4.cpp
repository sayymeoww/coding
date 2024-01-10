int n;
cin >> n;

string s;
cin >> s;

vector<int> zeros, cl0(n), ind0(n), cl1(n);

for (int i = 0; i < n; i++)
    if (s[i] == '0') zeros.push_back(i);
for (int i = 0; i < (int)zeros.size(); i++) ind0[zeros[i]] = i;

int p0 = n, p1 = n;
for (int i = n - 1; i >= 0; i--) {
    cl0[i] = p0;
    cl1[i] = p1;
    if (s[i] == '0')
        p0 = i;
    else
        p1 = i;
}

int A = 0, B = n - (int)zeros.size();
int ans = B;

for (int k = 1; k <= n; k++) {
    if (k >= zeros.size()) break;

    int p = zeros[k - 1];
    p = cl1[p];

    if (p == n) break;
    p = cl0[p];

    if (p == n || ind0[p] + k - 1 >= zeros.size()) break;
    p = zeros[ind0[p] + k - 1];

    int b = 1;
    while (p < n) {
        int L = k + b * (k + 1);

        if (ans < L) {
            ans = L;
            A = k, B = b;
        }

        p = cl1[p];

        if (p == n) break;
        p = cl0[p];

        if (p == n || ind0[p] + k - 1 >= zeros.size()) break;

        p = zeros[ind0[p] + k - 1];
        b++;
    }
}

cout << ans << '\n';
cout << string(A, '0');
for (int i = 0; i < B; i++) cout << '1' << string(A, '0');
cout << '\n';