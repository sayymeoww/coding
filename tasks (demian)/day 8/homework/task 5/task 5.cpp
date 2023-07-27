bool checkEdge(int i, int j, int n, int m)
{
    return (i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1);
}

struct edge
{
    int x, y;
    edge() : x(0), y(0) {}
    edge(int x, int y) : x(x), y(y) {}
};

class board
{
private:
    int n, m;

public:
    vector<vector<int>> edges;
    vector<vector<bool>> visited;

    void set(int n, int m)
    {
        this->n = n;
        this->m = m;
    }

    int getn()
    {
        return this->n;
    }

    int getm()
    {
        return this->m;
    }

    void init()
    {
        edges.resize(this->n, vector<int>(this->m, 0));
        visited.resize(this->n, vector<bool>(this->m, false));
    }

    void gen(vector<pair<int, int>> coords, int r)
    {
        if (r == 0)
        {
            for (auto coord : coords)
            {
                edges[coord.first][coord.second] = 1;
                visited[coord.first][coord.second] = true;
            }
        }
        else
        {
            for (auto coord : coords)
            {
                for (int i = coord.first - r; i <= coord.first + r; i++)
                {
                    for (int j = coord.second - r; j <= coord.second + r; j++)
                    {
                        if (checkEdge(i, j, this->n, this->m) && (i != coord.first - r && j != coord.second - r) &&
                            (i != coord.first - r && j != coord.second + r) &&
                            (i != coord.first + r && j != coord.second - r) &&
                            (i != coord.first + r && j != coord.second + r))
                        {
                            edges[i][j] = 1;
                            visited[i][j] = true;
                        }
                    }
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < this->m; j++)
            {
                cout << edges[i][j] << " ";
            }
            cout << '\n';
        }
    }

    void del()
    {
        edges.clear();
        visited.clear();
    }
};

bool solve(board b, int x, int y)
{
    if (y == b.getm() - 1 && b.edges[x][y] == 0)
        return true;
    b.visited[x][y] = true;

    vector<edge> Edges;
    edge cur(0, 0);

    if (checkEdge(x - 1, y, b.getn(), b.getm()))
    {
        if (!b.visited[x - 1][y] && b.edges[x - 1][y] == 0)
        {
            cur.x = x - 1;
            cur.y = y;
            Edges.push_back(cur);
        }
    }
    if (checkEdge(x + 1, y, b.getn(), b.getm()))
    {
        if (!b.visited[x + 1][y] && b.edges[x + 1][y] == 0)
        {
            cur.x = x + 1;
            cur.y = y;
            Edges.push_back(cur);
        }
    }
    if (checkEdge(x, y - 1, b.getn(), b.getm()))
    {
        if (!b.visited[x][y - 1] && b.edges[x][y - 1] == 0)
        {
            cur.x = x;
            cur.y = y - 1;
            Edges.push_back(cur);
        }
    }
    if (checkEdge(x, y + 1, b.getn(), b.getm()))
    {
        if (!b.visited[x][y + 1] && b.edges[x][y + 1] == 0)
        {
            cur.x = x;
            cur.y = y + 1;
            Edges.push_back(cur);
        }
    }

    if (Edges.size() == 0)
        return false;

    if (Edges.size() == 1)
        return solve(b, Edges[0].x, Edges[0].y);
    else if (Edges.size() == 2)
        return (solve(b, Edges[0].x, Edges[0].y) ||
                solve(b, Edges[1].x, Edges[1].y));
    else if (Edges.size() == 3)
        return (solve(b, Edges[0].x, Edges[0].y) ||
                solve(b, Edges[1].x, Edges[1].y) ||
                solve(b, Edges[2].x, Edges[2].y));
    else if (Edges.size() == 4)
        return (solve(b, Edges[0].x, Edges[0].y) ||
                solve(b, Edges[1].x, Edges[1].y) ||
                solve(b, Edges[2].x, Edges[2].y) ||
                solve(b, Edges[3].x, Edges[3].y));
}

bool path(board b)
{
    for (int i = 0; i < b.getn(); i++)
    {
        if (solve(b, i, 0))
            return true;
    }
    return false;
}

int n, m;
cin >> n >> m;

board b;
b.set(n, m);
b.init();

vector<pair<int, int>> coords;

int t;
cin >> t;
while (t--)
{
    int x, y;
    cin >> x >> y;
    coords.push_back({x - 1, y - 1});
}

for (int r = max(n / 2, m / 2); r >= 0; r--)
{
    board b;
    b.set(n, m);
    b.init();
    b.gen(coords, r);
    if (path(b))
    {
        cout << r + 1 << '\n';
        return 0;
    }
    b.del();
}
cout << -1 << '\n';