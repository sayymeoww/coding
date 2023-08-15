// max size and path
const int _size = 3e5 + 1;
vector<int> path(_size);

// graph
graph Graph[_size];
pair<int, int> Distances[_size];

void dijkstra(int start) {
    // initialize start distances
    for (int i = 0; i < _size; i++) Distances[i] = {inf, 0};
    Distances[start] = {0, 1};

    // queue of edges
    queue q;
    q.push({{0, -1}, start});

    while (!q.empty()) {
        pair<int, int> d = q.top().first;
        int v = q.top().second;
        q.pop();

        if (!(Distances[v].first < d.first ||
              Distances[v].second + d.second > 0)) {
            for (auto edge : Graph[v]) {
                // (v -(weight)- u)
                int u = edge.first, weight = edge.second;

                bool f1 = Distances[u].first > Distances[v].first + weight,
                     f2 = Distances[u].first == Distances[v].first + weight,
                     f3 = Distances[v].second + 1 > Distances[u].second;

                if (f1 || (f2 && f3)) {
                    Distances[u] = {Distances[v].first + weight,
                                    Distances[v].second + 1};

                    // linking edge
                    path[u] = v;

                    q.push({{Distances[u].first, -Distances[u].second}, u});
                }
            }
        }
    }
}

int n, m;
cin >> n >> m;

int start, finish;
cin >> start >> finish;

for (int i = 0; i < m; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;

    Graph[from].push_back({to, weight});
}

dijkstra(start);

cout << Distances[finish].first << '\n';  // summary weight
cout << Distances[finish].second - 2
     << '\n';  // number of edges (except start & finish)

vector<int> answer;
int edge = path[finish];

// from end to start
while (edge != start) {
    answer.push_back(edge);
    edge = path[edge];
}

reverse(answer.begin(), answer.end());

for (auto edge : answer) {
    cout << edge << " ";
}
cout << '\n';