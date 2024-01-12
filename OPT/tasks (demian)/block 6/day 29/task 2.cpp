int n;
cin >> n;

vector<vector<int>> times(n, vector<int>(3));

for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    times[i][0] = a;
    times[i][1] = b;
    times[i][2] = i;
}

auto lambda = [](vector<int> u, vector<int> v) { return u[0] < v[0]; };
sort(times.begin(), times.end(), lambda);

int maxday = 0;
for (int i = 0; i < n; i++) {
    if (maxday >= times[i][1]) {
        times[i][0] = -1;
        times[i][1] = -1;
    } else if (maxday < times[i][0])
        maxday = times[i][1];
    else if (maxday >= times[i][0]) {
        times[i][0] = maxday + 1;
        maxday = times[i][1];
    }
}

auto order = [](vector<int> u, vector<int> v) { return u[2] < v[2]; };
sort(times.begin(), times.end(), order);

for (auto el : times) {
    cout << el[0] << " " << el[1] << '\n';
}