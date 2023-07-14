ifstream f("fuck.txt");

int n;
f >> n;

vector<vector<int>> v(10000, vector<int>(10000));

for (int i = 0; i < n; i++) {
    int x, y;
    f >> x >> y;
    v[x - 1][y - 1] = 1;
}

int len = 0, maxlen = 0, row = 0;
bool flag = false;
for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < 10000; j++) {
        if (v[i][j] == 1) {
            if (!flag) {
                flag = !flag;
                len++;
            } else {
                if (len > maxlen) {
                    maxlen = len;
                    row = i + 1;
                }
                len = 0;
            }
        } else {
            if (flag) {
                flag = !flag;
                len++;
            } else {
                if (len - 1 > maxlen) {
                    maxlen = len - 1;
                    row = i + 1;
                }
                len = 0;
            }
        }
    }
}

cout << maxlen << " " << row << '\n';