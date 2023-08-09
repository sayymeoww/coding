class segtree {
    private:
        vector<int> arr;

    public:
        segtree(vector<int> a, int s) {
            int h = (int)ceil(log(s) / log(2));
            int maxsize = 2 * (int)pow(2, h) - 1;

            arr.resize(maxsize);
            construct(a, 0, s - 1, 0);
        }

        int getmid(int x, int y) { return x + (y - x) / 2; }

        int construct(vector<int> a, int x, int y, int si) {
            if (x == y) {
                arr[si] = a[x];
                return a[x];
            }

            int mid = getmid(x, y);
            arr[si] = construct(a, x, mid, 2 * si + 1) +
                      construct(a, mid + 1, y, 2 * si + 2);

            return arr[si];
        }

        void updateval(int x, int y, int j, int val, int si) {
            if (j < x || j > y) {
                return;
            }

            arr[si] += val;
            if (y != x) {
                int mid = getmid(x, y);
                updateval(x, mid, j, val, 2 * si + 1);
                updateval(mid + 1, y, j, val, 2 * si + 2);
            }
        }

        void update(vector<int> a, int s, int j, int newval) {
            if (j < 0 || j > s - 1) {
                return;
            }

            int diff = newval - a[j];
            arr[j] = newval;

            updateval(0, s - 1, j, diff, 0);
        }

        int getsum(int x, int y, int i, int j, int si) {
            if (i <= x && j >= y) {
                return arr[si];
            }

            if (y < i || x > j) {
                return 0;
            }

            int mid = getmid(x, y);
            return getsum(x, mid, i, j, 2 * si + 1) +
                   getsum(mid + 1, y, i, j, 2 * si + 2);
        }
};

int n;
cin >> n;

vector<int> array(n);
for (int i = 0; i < n; i++) cin >> array[i];

segtree s(array, n);

int i, j;
cin >> i >> j;

cout << s.getsum(0, n - 1, i, j, 0) << '\n';