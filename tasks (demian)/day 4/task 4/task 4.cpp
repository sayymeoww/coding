ifstream f("7.txt");

int n, m, count;
f >> n >> m;

int car = 0, x = 0;
vector<int> weights;
for (int i = 0; i < n; i++) {
    int w;
    f >> w;

    if (w >= 210 && w <= 220) {
        x += w;
        count++;
    } else {
        weights.push_back(w);
    }
}

int s = m - x;
sort(weights.begin(), weights.end());

int index = 0;
for (int i = 0; i < n; i++) {
    if (car + weights[i] <= s) {
        car += weights[i];
        index = i;
        count++;
    }
}

int acar = car;
car = car - weights[index];
for (int i = index + 1; i < n; i++) {
    if (car + weights[i] <= s) {
        car += weights[i];
    }
}

car = max(acar, car);

cout << car + x << " " << count << '\n';