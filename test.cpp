int a, b, k, n;
cin >> a >> b >> k;
vb aa(a + b), bb(a + b);
n = a + b;
aa[0] = 1;
bb[0] = 1;
b--;
if (k) {
    if (k + 1 >= n || b == 0) {
        cout << "No" << endl;
        return 0;
    }
    aa[1] = 1;
    bb[k + 1] = 1;
    b--;
    for (int i = 2; i < n && b; i++)
        if (i != k + 1) {
            aa[i] = bb[i] = 1;
            b--;
        }
} else {
    for (int i = 1; i < n && b; i++) {
        aa[i] = bb[i] = 1;
        b--;
    }
}

if (b) {
    cout << "No" << endl;
    return 0;
}
cout << "Yes" << endl;
rep(i, n) cout << aa[i];
cout << endl;
rep(i, n) cout << bb[i];
cout << endl;