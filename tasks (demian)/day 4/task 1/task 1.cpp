int s, n;
    ifstream f("28141.txt");

    f >> s >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        f >> a[i];
    }

    sort(a.begin(), a.end());

    int bag = 0;
    int maxind = 0;
    int ppl = 0;

    for (int i = 0; i < n; i++) {
        if (bag + a[i] <= s) {
            bag += a[i];
            ppl++;
            maxind = i;
        }
    }

    int max = a[maxind];
    bag -= max;
    for (int i = maxind + 1; i < n; i++) {
        if (bag + a[i] <= s) {
            max = a[i];
        }
    }

    cout << ppl << " " << max << '\n';