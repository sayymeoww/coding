ifstream f("11.txt");

int n, m, count, type, l, r;
f >> n >> m;

vector<int> a(n);
for (int i = 0; i < n; i++) f >> a[i];

vector<bool> v(n);
for (int i = 0; i < n; i++) v[i] = (a[i] % 2 == 1);

while (m--) {
    f >> type >> l >> r;
    l--;
    r--;

    if (type == 1) {
        for (int i = l; i <= r; i++)
            if (!(i & 1)) v[i] = !v[i];
    } else {
        count = 0;
        for (int i = l; i <= r; i++) count += ((v[i]) ? 1 : 0);

        cout << count << '\n';
    }
}