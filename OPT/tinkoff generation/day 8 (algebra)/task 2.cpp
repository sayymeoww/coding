int n;
cin >> n;

int i = 2, k = 0;

if (n % i == 1) {
    int j = 3;
    while (j * j <= n) {
        if (!(n % j)) {
            k = 1;
            i = j;
            break;
        }
        j += 2;
    }
} else {
    k = 1;
}

if (k) {
    cout << (i - 1) * (n / i) << " " << n / i << '\n';
} else {
    cout << 1 << " " << n - 1 << '\n';
}