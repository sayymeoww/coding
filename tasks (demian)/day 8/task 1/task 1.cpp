int t;
cin >> t;

while (t--) {
    int n, d;
    cin >> n >> d;

    int size = n / 2;
    int left = 1, right = n;

    while (left < right) {
        int middle = (left + right) / 2;
        if ((size + middle - 1) / middle <= d)
            right = middle;
        else
            left = middle + 1;
    }

    cout << left << '\n';
}