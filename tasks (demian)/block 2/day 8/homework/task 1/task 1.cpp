int water(int n, vector<int> array) {
    // создаю вектор пар (элемент, его индекс в изначальном массиве)
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) pairs[i] = {array[i], i};

    // сортирую по убыванию
    auto lambda = [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    };
    sort(pairs.begin(), pairs.end(), lambda);

    // изначально оба указателя указывают
    // на индекс максимального элемента
    int l = pairs[0].second;
    int r = pairs[0].second;

    // cur - размер отдельной ямы с водой
    int cur, answer = 0;
    for (int i = 1; i < n; i++) {
        int el = pairs[i].first;
        int id = pairs[i].second;

        if (id > r) {
            cur = (id - r - 1) * el;
            r = id;
        } else if (id < l) {
            cur = (l - id - 1) * el;
            l = id;
        } else {
            cur = -el;
        }
        answer += cur;
    }

    return answer;
}

int n;
cin >> n;

vector<int> array(n);
for (int i = 0; i < n; i++) cin >> array[i];

cout << water(n, array) << '\n';