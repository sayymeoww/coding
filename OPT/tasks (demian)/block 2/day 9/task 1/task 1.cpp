ifstream f("21.txt");

int n, m;
f >> n >> m;

vector<pair<int, int>> people;
vector<int> answer, kingdoms;

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        int a;
        f >> a;
        people.push_back({a, i});
    }
}

auto lambda = [](pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
};
sort(people.begin(), people.end(), lambda);

int index = (int)people.size() / 2;
int mediana = people[index].first;

answer.push_back(mediana);
kingdoms.push_back(people[index].second);

int l = index - 1, r = index + 1;
while ((int)answer.size() < n) {
    int left = people[l].second;
    int right = people[r].second;

    if (left == right) {
        if (find(kingdoms.begin(), kingdoms.end(), left) == kingdoms.end()) {
            if (find(kingdoms.begin(), kingdoms.end(), right) ==
                kingdoms.end()) {
                if (abs(mediana - people[l].first) <
                    abs(mediana - people[r].first)) {
                    answer.push_back(people[l].first);
                    kingdoms.push_back(left);
                    l--;
                } else {
                    answer.push_back(people[r].first);
                    kingdoms.push_back(right);
                    r++;
                }
            } else {
                answer.push_back(people[l].first);
                kingdoms.push_back(left);
                l--;
                r++;
            }
        } else {
            cout << "левый рассмотрен" << '\n';
            if (find(kingdoms.begin(), kingdoms.end(), right) ==
                kingdoms.end()) {
                answer.push_back(people[r].first);
                kingdoms.push_back(right);
                l--;
                r++;
            } else {
                r++;
                l--;
            }
        }
    } else {
        if (find(kingdoms.begin(), kingdoms.end(), left) == kingdoms.end()) {
            if (find(kingdoms.begin(), kingdoms.end(), right) ==
                kingdoms.end()) {
                answer.push_back(people[l].first);
                kingdoms.push_back(left);
                r++;
                answer.push_back(people[r].first);
                kingdoms.push_back(right);
                l--;
            } else {
                answer.push_back(people[l].first);
                kingdoms.push_back(left);
                l--;
            }
        } else {
            if (find(kingdoms.begin(), kingdoms.end(), right) ==
                kingdoms.end()) {
                answer.push_back(people[r].first);
                kingdoms.push_back(right);
            }
            r++;
            l--;
        }
    }
}

for (auto e : answer) cout << e << " ";
cout << '\n';