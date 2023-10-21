int board[10];

bool check(int i, int j, int k) {
    if (k == i) return true;
    return board[k] != j && (i - k) != (j - board[k]) &&
           (i - k) != (board[k] - j) && check(i, j, k + 1);
}

int put(int n, int i, int j) {
    if (i == n) return 1;
    if (j < n) {
        int r = 0;
        if (check(i, j, 0)) {
            board[i] = j;
            r = put(n, i + 1, 0);
        }
        return r + put(n, i, j + 1);
    }
    return 0;
}

int n;
cin >> n;

cout << put(n, 0, 0) << '\n';