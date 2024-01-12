const int maxn = 1000;

const char* dirs = "NSWE";
const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};

int n, m, g, it, res, state[maxn][maxn], best[maxn][maxn];
char a[maxn][maxn];
bool finale[maxn][maxn];

void move(int& ci, int& cj) {
    int dir = strchr(dirs, toupper(a[ci][cj])) - dirs;
    ci += di[dir], cj += dj[dir];
}

cin >> n >> m >> g;
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];

for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        if (!isupper(a[i][j])) continue;

        int ci = i, cj = j, len = 0;

        it++;
        while (state[ci][cj] != it) {
            state[ci][cj] = it;
            len++;
            move(ci, cj);
        }

        it++;
        while (state[ci][cj] != it) {
            state[ci][cj] = it;
            if (!finale[ci][cj]) {
                res++;
                finale[ci][cj] = true;
                best[i][j] = len;
                break;
            }
            len++;
            move(ci, cj);
        }
    }

cout << res << '\n';
if (g) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (best[i][j] > 0) {
                cout << i + 1 << " " << j + 1 << " "
                     << 2 * n * m + 1 - best[i][j] << '\n';
            }
        }
    }
}