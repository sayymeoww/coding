int n;
vector<int> v;
const int k = 25000;

int f(vector<int> &p) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        int d = 1;
        for (int j = 0; j < i; j++)
            if (abs(i - j) == abs(p[i] - p[j])) d = 0;
        s += d;
    }
    return s;
}

double rnd() { return double(rand()) / RAND_MAX; }

cin >> n;
v.resize(n);

random_device rd;
mt19937 g(rd());

iota(v.begin(), v.end(), 0);
shuffle(v.begin(), v.end(), g);

int ans = f(v);

double t = 1;
for (int i = 0; i < k && ans < n; i++) {
    t *= 0.888888;
    vector<int> u = v;
    swap(u[rand() % n], u[rand() % n]);
    int val = f(u);
    if (val > ans || rnd() < exp((val - ans) / t)) {
        v = u;
        ans = val;
    }
}

for (int x : v) cout << x + 1 << " ";
cout << '\n';