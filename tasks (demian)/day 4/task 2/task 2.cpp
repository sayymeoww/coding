int n, size = 1e5;
ifstream f("1.txt");
f >> n;

vector<vector<int>> hall(size);
vector<int> mins(size, inf);
// k : (a, b, c, d) -> a и d заняты, k - max, b - min

int ansx, ansy;
for (int i = 0; i < n; i++) {
    int row, place;
    f >> row >> place;
    if ((int) hall[row].size() == 0) {
        hall[row].push_back(place);
    } else {
        for (auto p : hall[row]) {
            if (place - p == 3) {
                if (p + 1 < mins[row]) {
                    mins[row] = p + 1;
                    if (row > ansx) {
                        ansx = row;
                        ansy = p;
                    }
                }
            } else if (p - place == 3) {
                if (place + 1 < mins[row]) {
                    mins[row] = place + 1;
                    if (row > ansx) {
                        ansx = row;
                        ansy = place;
                    }
                }
            }
        }
    }
}

cout << ansx << " " << ansy << '\n';