const int maxn = 1e4 + 1;
const int bitlen = 200;

int n, m, k, tlen;
int dist[maxn][bitlen], sum[maxn][maxn];
int from[maxn], len[maxn], x[maxn], y[maxn], tdist[maxn];
bool used[maxn];

bool isless(int a, int b) {
    for (int i = 0; i < min(len[a], len[b]); i++)
        if (dist[a][len[a] - 1 - i] != dist[b][len[b] - 1 - i])
            return (dist[a][len[a] - 1 - i] < dist[b][len[b] - 1 - i]);

    return (len[a] < len[b]);
}

bool check(int a, int b, int d) {
    for (int i = 0; i < min(len[a], len[b]) && dist[a][len[a] - 1 - i] > d; i++)
        if (dist[a][len[a] - 1 - i] != dist[b][len[b] - 1 - i])
            return (dist[a][len[a] - 1 - i] > dist[b][len[b] - 1 - i]);

    return true;
}

bool update(int a, int b, int d) {
    if (check(a, b, d)) return false;
    len[k] = 0;

    for (int i = 0; i < len[b]; i++) {
        if (dist[b][i] < d) {
            dist[k][len[k]] = dist[b][i];
            len[k]++;
        } else if (dist[b][i] == d) {
            d++;
        } else {
            dist[k][len[k]] = d;
            len[k]++;
            d = maxn + 1;
            dist[k][len[k]] = dist[b][i];
            len[k]++;
        }
    }

    if (d != maxn + 1) {
        dist[k][len[k]] = d;
        len[k]++;
    }

    if (isless(k, a)) {
        len[a] = len[k];
        for (int i = 0; i < len[a]; i++) dist[a][i] = dist[k][i];
        return true;
    }

    return false;
}

cin >> n >> m >> k;

for (int i = 0; i < k; i++) {
    cin >> x[i] >> y[i];
    sum[x[i]][y[i]] += 1;
}

for (int i = 1; i < k; i++) {
    dist[i][0] = max(x[i] - 1, y[i] - 1);
    len[i] = 1;
}

from[0] = -1;
while (!used[k - 1]) {
    int b = -1;

    for (int i = 0; i < k; i++) {
        if (!used[i] && (b == -1 || isless(i, b))) {
            b = i;
        }
    }

    used[b] = true;

    if (b == k - 1) break;

    for (int i = 0; i < k; i++) {
        if (!used[i]) {
            if (update(i, b, max(abs(x[i] - x[b]), abs(y[i] - y[b])))) {
                from[i] = b;
            }
        }
    }
}

vector<int> path;
int cur = k - 1;
while (cur != -1) {
    path.push_back(cur);
    cur = from[cur];
}

reverse(path.begin(), path.end());
cout << (int)path.size() << '\n';
for (int i = 0; i < (int)path.size(); i++) cout << path[i] + 1 << " ";
cout << '\n';