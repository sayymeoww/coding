int n;
cin >> n;

vector<int> v(n);

for (int i = 0; i < n; i++) {
    cin >> v[i];
}

int answer = v[0], ansl = 0, ansr = 0, sum = 0, minus_pos = -1;

for (int r = 0; r < n; r++) {
    sum += v[r];

    if (sum > answer) {
        answer = sum;
        ansl = minus_pos + 1;
        ansr = r;
    }

    if (sum < 0) {
        sum = 0;
        minus_pos = r;
    }
}

cout << ansl + 1 << " " << ansr + 1 << " " << answer << '\n';