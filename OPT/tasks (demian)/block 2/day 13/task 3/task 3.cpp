int n;
cin >> n;

vector<int> numbers(n);
for (int i = 0; i < n; i++) {
    cin >> numbers[i];
    numbers[i]--;
}

vector<int> temp(n), a(n, 0), b(n, 0);
for (int i = 0; i < n; i++) temp[numbers[i]] = i;

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (j < i && numbers[j] < numbers[i]) a[i]++;
        if (i < j && numbers[i] < numbers[j]) b[i]++;
    }
}

int answer = 0;
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        int current = j - i;

        int first = temp[i];
        int second = temp[j];

        if (first > second) swap(first, second);

        current = max({current, second - a[first], n - b[second] - first - 1});

        answer += current;
    }
}

cout << answer << '\n';