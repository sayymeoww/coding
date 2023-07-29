struct graph {
    int n;
    vector<vector<int>> g;

    graph(int n = 1) : n(n) { g.clear(); }

    void add(int from, int to) { g[from].push_back(to); }

    void dfs(vector<bool> &visited, int start) {
        if (visited[start]) return;
        visited[start] = true;

        // обработать вершину

        for (auto edge : g[start]) {
            dfs(visited, edge);
        }
    }
};

vector<bool> visited;
graph *g;

int n, m;
cin >> n >> m;

visited.assign(n, false);
g = new graph(n);

for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    g->add(from, to);
}

int start;
cin >> start;

g.dfs(visited, start);

// Асимптотика - O(n + m)