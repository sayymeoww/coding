ifstream f("3.txt");

int n, max = 0;
double sum = 0;

vector<int> v;
f >> n;

for (int i = 0; i < n; i++) {
    int cost;
    f >> cost;

    if (cost <= 100) {
        sum += cost;
    } else {
        v.push_back(cost);
    
}

sort(v.begin(), v.end());
int length = (int)v.size();
for (int i = 0; i < length; i++) {
    if (i < length / 2) {
        sum += v[i] * 0.7;
        max = v[i];
    } else {
        sum += v[i];
    }
}

cout << ceil(sum) << " " << max << '\n';