int n;
cin >> n;

string s;
vector<int> v(n);
for (int i = 0; i < n; i++) {
    cin >> s;
    int sum = 0;
    for (char c : s) {
        switch (c) {
            case 'a':
                sum += 1;
                break;
            case 'b':
                sum += 5;
                break;
            case 'c':
                sum += 10;
                break;
            case 'd':
                sum += 50;
                break;
            case 'e':
                sum += 100;
                break;
            case 'f':
                sum += 200;
                break;
            case 'g':
                sum += 500;
                break;
            case 'h':
                sum += 1000;
                break;
            case 'i':
                sum += 2500;
                break;
            case 'A':
                sum += 500;
                break;
            case 'B':
                sum += 1000;
                break;
            case 'C':
                sum += 5000;
                break;
            case 'D':
                sum += 10000;
                break;
            case 'E':
                sum += 20000;
                break;
            case 'F':
                sum += 50000;
                break;
            case 'G':
                sum += 100000;
                break;
            case 'H':
                sum += 200000;
                break;
            case 'I':
                sum += 500000;
                break;
        }
        v[i] = sum;
    }
}

int mx = -inf, mn = inf;
int a, b;
for (int i = 0; i < n; i++) {
    if (v[i] > mx) {
        mx = v[i];
        a = i;
    }
    if (v[i] < mn) {
        mn = v[i];
        b = i;
    }
}

cout << min(a + 1, b + 1) << " " << max(a + 1, b + 1) << '\n';
