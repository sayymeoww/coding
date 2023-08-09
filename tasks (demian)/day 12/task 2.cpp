int n;
cin >> n;

vector<int> orders(n);
for (int i = 0; i < n; i++) {
    cin >> orders[i];
}

int house = 0;
int summary = 0;

for (int target = 0; target < n; target++) {
    int current = 0;
    for (int i = 0; i < n; i++) {
        int diff = orders[i] - abs(target - i);
        current += (diff >= 0 ? diff : 0);
    }
    if (current > summary) {
        summary = current;
        house = target;
    }
}

cout << summary << ' ' << house + 1 << '\n';