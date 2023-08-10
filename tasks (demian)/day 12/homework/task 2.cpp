class tram {
    public:
        int m, profit;
        multiset<int> sit;
        multiset<int, greater<int>> stand;

        tram(int m) : m(m), profit(0) {}

        void add(int a, int b) {
            sit.insert(a - b);
            profit += a;

            if (sit.size() > m || *sit.begin() < 0) {
                profit -= move(sit, stand);
            }
        }

        void del(int a, int b) {
            int p = a - b;
            if (sit.count(p)) {
                sit.erase(sit.find(p));
                profit -= a;
                if (stand.size() && *stand.begin() > 0) {
                    profit += move(stand, sit);
                }
            } else {
                stand.erase(stand.find(p));
                profit -= b;
            }
        }

        int get() const { return profit; }

    private:
        template <class u, class v>
        int move(u &from, v &to) {
            int value = *from.begin();
            from.erase(from.begin());
            to.insert(value);
            return value;
        }
};

int n, m, p;
cin >> n >> m >> p;

multiset<pair<int, pair<int, int>>> in, out;
for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    in.insert({c, {a, b}});
    out.insert({d, {a, b}});
}

tram t(m);
int r = 0;
for (int i = 1; i < p; i++) {
    while (in.size() && in.begin()->first == i) {
        auto p = in.begin()->second;
        t.add(p.first, p.second);
        in.erase(in.begin());
    }
    while (out.size() && out.begin()->first == i) {
        auto p = out.begin()->second;
        t.del(p.first, p.second);
        out.erase(out.begin());
    }
    r += t.get();
}

cout << r << '\n';