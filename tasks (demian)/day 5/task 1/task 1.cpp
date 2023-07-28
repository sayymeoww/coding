struct time {
    int in, out;
};

bool inter(struct time a, struct time b) {
    return (a.in <= b.in && b.in <= a.out) ||
           (a.in <= b.out && b.out <= a.out) ||
           (b.in <= a.in && a.in <= b.out) || (b.in <= a.out && a.out <= b.out);
}

int answer = 0;

void solve(vector<struct time> times) {
    if ((int)times.size() < 1) {
        cout << answer << '\n';
        return;
    }

    int count = 0;

    auto lambda = [](struct time a, struct time b) { return a.out < b.out; };
    sort(times.begin(), times.end(), lambda);

    struct time pivot = times[0];
    times.erase(times.begin());

    vector<struct time> newtimes;

    for (auto t : times) {
        if (!inter(t, pivot)) {
            newtimes.push_back(t);
            count++;
        }
    }

    int temp = (int)times.size() - count + 1;
    ::answer = max(::answer, temp);

    solve(newtimes);
}

ifstream f("5.txt");

int n, answer = 0, temp;
f >> n;

vector<struct time> times(n);

for (int i = 0; i < n; i++) {
    f >> times[i].in >> times[i].out;
}

solve(times);