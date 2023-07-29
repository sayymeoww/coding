struct edge {
    int from, to, weight;
    edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

struct graph {
    int n;
    vector<edge> g;

    graph(int n = 1) : n(n) { g.clear(); }

    void add(int from, int to, int weight) {
        g.push_back(edge(from, to, weight));
    }

    void algo(int start, vector<int> &d) {
        d.assign(n + 1, inf);
        d[start] = 0;

        for (int stage = 0; stage < n; stage++) {
            for (int i = 0; i < g.size(); i++) {
                edge e = g[i];
                if (d[e.from] < inf)
                    if (d[e.to] > d[e.from] + e.weight)
                        d[e.to] = d[e.from] + e.weight;
            }
        }
    }
};

vector<int> distances;
graph *g;

// ввод графа
int n, m;  // n - вершины, m - ребра
cin >> n >> m;

g = new graph(n);
for (int i = 0; i < m; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    g->add(from, to, weight);
}

int start;
cin >> start;

g->algo(start, distances);

for (int i = 1; i <= n; i++) {
    cout << distances[i] << " ";
}
cout << '\n';