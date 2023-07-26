/*
    На вход программы поступает последовательность из n целых положительных чисел.
    Рассматриваются все пары элементов последовательности ai и aj, такие что i < j
    и ai > aj (первый элемент пары больше второго; i и j  — порядковые номера чисел
    в последовательности входных данных).

    Среди пар, удовлетворяющих этому условию, необходимо найти и напечатать пару с
    максимальной суммой элементов, которая делится на m  =  120.

    Если среди найденных пар максимальную сумму имеют несколько, то можно напечатать
    любую из них.
*/

ifstream f("89.txt");

int n, x, a = 0, b = 0, ost = 0;
f >> n;

vector<int> p(n, 0);

for (int i = 0; i < n; i++)
{
    f >> x;
    ost = x % 120;

    if (x > p[ost])
        p[ost] = x;

    if (x < p[(120 - ost) % 120] && p[(120 - ost) % 120] + x > a + b)
    {
        a = p[(120 - ost) % 120];
        b = x;
    }
}

cout << a << " " << b << '\n';