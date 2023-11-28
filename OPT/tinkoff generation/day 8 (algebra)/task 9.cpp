const int maxn = 1e6 + 1;
int phi[maxn], result[maxn];

void totient() {
    phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!phi[i]) {
            phi[i] = i - 1;
            for (int j = i << 1; j < maxn; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
}

int solve(int n) {
    totient();

    for (int i = 1; i < maxn; i++)
        for (int j = 2; i * j < maxn; j++) result[i * j] += i * phi[j];
    for (int i = 2; i < maxn; i++) result[i] += result[i - 1];

    return result[n];
}

int n;
cin >> n;

cout << 2 * solve(n) + n * (n - 1) / 2 + n << '\n';