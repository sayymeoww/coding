#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct segment {
    int xl, xr;
    int y;
    int type;

    segment(int xl, int xr, int y, int type)
        : xl(xl), xr(xr), y(y), type(type) {}

    bool operator<(segment s) const { return y < s.y; }
};

int main() {
    int k, n;
    cin >> k >> n;

    int size = 0;
    int curx = 0, cury = 0;

    set<pair<int, int>> coords;
    coords.insert({curx, cury});
    size++;

    while (n--) {
        char direction;
        int delta;

        cin >> direction >> delta;

        switch (direction) {
            case 'N':
                for (int i = 1; i <= delta; i++) {
                    cury++;
                    size++;
                    coords.insert({curx, cury});
                }
                break;
            case 'S':
                for (int i = 1; i <= delta; i++) {
                    cury--;
                    size++;
                    coords.insert({curx, cury});
                }
                break;
            case 'W':
                for (int i = 1; i <= delta; i++) {
                    curx--;
                    size++;
                    coords.insert({curx, cury});
                }
                break;
            case 'E':
                for (int i = 1; i <= delta; i++) {
                    curx++;
                    size++;
                    coords.insert({curx, cury});
                }
                break;
        }
    }

    vector<int> x;
    vector<struct segment> seg;

    for (auto coord : coords) {
        x.push_back(coord.first);
        x.push_back(coord.first + k);

        seg.push_back(segment{coord.first, coord.first + k, coord.second, 1});
        seg.push_back(
            segment{coord.first, coord.first + k, coord.second + k, -1});
    }

    sort(x.begin(), x.end());
    sort(seg.begin(), seg.end());

    int answer = 0;
    int len = x.size();

    for (int i = 0; i < len; i++) {
        int prevY = 0, cnt = 0;
        for (int j = 0; j < len; j++) {
            if (seg[j].xr <= x[i - 1] || seg[j].xl >= x[i]) continue;
            if (cnt == 0) prevY = seg[j].y;
            cnt += seg[j].type;
            if (cnt == 0) {
                answer += (seg[j].y - prevY) * (x[i] - x[i - 1]);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}