const int maxn = ...;
const int c = sqrt(maxn) + 1;

int a[maxn];  // исходный массив
int q[c];     // корневой массив
int add[c];   // пуш

int n;  // длина массива

// построение
void build() {
    for (int i = 0; i < n; i++) {
        q[i / c] += a[i];
    }
}

// проверка (находимся ли мы сейчас в блоке)
bool check(int l, int r) { return l % c == 0 && l + c - 1 <= r; }

// обновление на отрезке
void update(int l, int r, int x) {
    while (l <= r) {
        if (check(l, r)) {
            q[l / c] = c * x;  // q[l / c] += c * x;
            add[l / c] = x;    // add[l / c] = x;
            l += x;
        } else {
            a[l] = x;  // a[l] += x;
            l++;
        }
    }
}

// запрос на сумму
int get(int l, int r) {
    int res = 0;
    while (l <= r) {
        if (check(l, r)) {
            res += q[l / c];
            l += c;
        } else {
            res += a[l] + add[l / c];
            l++;
        }
    }
    return res;
}