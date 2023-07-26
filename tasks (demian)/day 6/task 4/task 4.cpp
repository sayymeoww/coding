int n;
cin >> n;

int d = 1;
for (int i = sqrt(n); i >= 2; i++)
{
    if (n % i == 0)
    {
        d = i;
        break;
    }
}

int a = d;
int b = n / d;

cout << ceil(0.5 * sqrt(a * a + b * b)) << '\n';