const int mod = 1e9 + 7;

int n;
cin >> n;

vector<char> pass(n), p(n);

string s;
cin >> s;

for (int i = 0; i < n; i++) pass[i] = s[i];

p = pass;
sort(p.begin(), p.end());

int count = 0;
while (p != pass) {
    count = (count + 1) % mod;
    next_permutation(p.begin(), p.end());
}

cout << (count + 1) % mod << '\n';