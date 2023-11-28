const int maxn = 1e6 + 1;
using arr = vector<bool>;

void sieve(int l, int r) {
    arr is_prime(maxn, 1);
    is_prime[1] = 0;
    for (int i = 2; i < maxn; i++) {
        if (is_prime[i])
            for (int j = 2 * i; j < maxn; j += i) {
                is_prime[j] = 0;
            }
    }

    for (int i = l; i <= r; i++) {
        if (is_prime[i]) cout << i << " ";
    }
    cout << '\n';
}

int l, r;
cin >> l >> r;

sieve(l, r);