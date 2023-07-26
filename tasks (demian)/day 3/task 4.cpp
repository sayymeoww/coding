/*
    На ускорителе для большого числа частиц производятся замеры
    скорости каждой из них. Скорость частицы  — это целое число
    (положительное, отрицательное или 0).

    Частиц, скорость которых измерена, может быть очень много, но
    не может быть меньше трёх. Скорости всех частиц различны.
    При обработке результатов в каждой серии эксперимента отбирается
    основное множество скоростей. Это такое непустое множество
    скоростей частиц (в него могут войти как скорость одной частицы,
    так и скорости всех частиц серии), для которого произведение
    скоростей является максимальным среди всех возможных множеств.

    При нахождении произведения знак числа учитывается. Если есть
    несколько таких множеств, то основным считается то, которое
    содержит наибольшее количество элементов.
*/

int n;
cin >> n;

vector<pair<int, int>> speeds(n);
for (int i{0}; i < n; i++)
{
    int speed;
    cin >> speed;
    speeds[i] = {speed, i + 1};
}

sort(speeds.begin(), speeds.end(), [](pair<int, int> a, pair<int, int> b)
     { return a.first > b.first; });

int cz = 0;
vector<int> otr, pol, zeros;

for (int i{0}; i < n; i++)
{
    int pos1 = -inf, pos2 = -inf;
    if (speeds[i].first < 0)
    {
        if (i % 2 == 0)
            pos1 = speeds[i].second;
        else if (i % 2 == 1)
        {
            pos2 = speeds[i].second;
            otr.push_back(pos1);
            otr.push_back(pos2);
            else if (speeds[i + 1].first >= 0)
                otr.push_back(speeds[i].second);
        }
        else if (speeds[i].first == 0)
        {
            cz++;
            zeros.push_back(speeds[i].second)
        }
        else
            pol.push_back(speeds[i].second);
    }

    if (o == speeds[0].first && cz == n - 1)
    {
        for (auto el : zeros)
            cout << el << " ";
        cout << '\n';
    }
    else if (o == speeds[0].first)
    {
        for (auto el : pol)
            cout << el << " ";
        cout << '\n';
    }
    else
    {
        vector<int> answer;

        for (auto el : otr)
            answer.push_back(el);
        for (auto el : pol)
            answer.push_back(el);

        sort(answer.begin(), answer.end());

        for (auto el : answer)
            cout << el << " ";

        cout << '\n';
    }