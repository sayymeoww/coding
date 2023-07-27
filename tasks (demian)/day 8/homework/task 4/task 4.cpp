int n, m;
cin >> n >> m;

vector<tuple<int, int, int>> riders(n, {0, 0, 0});
for (int i = 0; i < n; i++)
    get<0>(riders[i]) = i + 1;

for (int i = 0; i < m; i++)
{
    int a;
    cin >> a;

    get<1>(riders[a - 1])++;
    get<2>(riders[a - 1]) = i;
}

auto lambda = [](tuple<int, int, int> a, tuple<int, int, int> b)
{
    return get<1>(a) > get<1>(b);
};
sort(riders.begin(), riders.end(), lambda);

vector<tuple<int, int, int>> answer;
for (int i = 0; i < n; i++)
    if (get<1>(riders[i]) == get<1>(riders[0]))
        answer.push_back(riders[i]);

auto lambda2 = [](tuple<int, int, int> a, tuple<int, int, int> b)
{
    return get<2>(a) < get<2>(b);
};
sort(answer.begin(), answer.end(), lambda2);

cout << get<0>(answer[0]) << '\n';