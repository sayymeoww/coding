/*
    Системный администратор раз в неделю создаёт архив
    пользовательских файлов. Однако объём диска, куда он
    помещает архив, может быть меньше, чем суммарный объём
    архивируемых файлов.

    Известно, какой объём занимает файл каждого пользователя.

    По заданной информации об объёме файлов пользователей
    и свободном объёме на архивном диске определите максимальное
    число пользователей, чьи файлы можно сохранить в архиве,
    а также максимальный размер имеющегося файла, который может
    быть сохранён в архиве, при условии, что сохранены файлы
    максимально возможного числа пользователей.
*/

int s, n;
ifstream f("task 1.txt");

f >> s >> n;
vector<int> a(n);

for (int i = 0; i < n; i++)
{
    f >> a[i];
}

sort(a.begin(), a.end());

int bag = 0;
int maxind = 0;
int ppl = 0;

for (int i = 0; i < n; i++)
{
    if (bag + a[i] <= s)
    {
        bag += a[i];
        ppl++;
        maxind = i;
    }
}

int max = a[maxind];
bag -= max;
for (int i = maxind + 1; i < n; i++)
{
    if (bag + a[i] <= s)
    {
        max = a[i];
    }
}

cout << ppl << " " << max << '\n';