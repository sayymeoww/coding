ifstream f("8.txt");

int k, n;
f >> k >> n;

vector<pair<int, int>> times(n);
for (int i = 0; i < n; i++) {
    int in, out;
    f >> in >> out;
    times[i].first  = in;
    times[i].second = out;
}

auto lambda = [](pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
};
sort(times.begin(), times.end(), lambda);

vector<int> bag(k, 0);
int count = 0, cell = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
        if (times[i].first - bag[j] >= 1) {
            count++;
            bag[j] = times[i].second;
            cell = j + 1;
            break;
        }
    }
}

cout << count << " " << cell << '\n';