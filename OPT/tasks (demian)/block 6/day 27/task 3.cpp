int query(int x) {
    int ans[2] = {0, 0};

    for (int i = 0; i < 3; i++) {
        cout << "? " << x << '\n';

        string buf;
        cin >> buf;

        if (buf == "Yes") {
            ans[1]++;
        } else if (buf == "No") {
            ans[0]++;
        } else {
            assert(0);
        }
        for (int i = 0; i < 2; i++) {
            if (ans[i] >= 2) {
                return i;
            }
        }
    }
    assert(0);
}

int n;
cin >> n;

while (true) {
    int l = 1;
    int r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (query(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << "! " << l << '\n';

    string buf;
    cin >> buf;

    if (buf == "Done") {
        break;
    }
}