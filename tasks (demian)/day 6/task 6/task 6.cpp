string s;
cin >> s;

int n = (int)s.length(), c;
reverse(s.begin(), s.end());

// вектор дпшки dp[2][10][10][n]
// изначально заполненная нулями
bignum dp;
dp.resize(2, vector<vector<vector<int>>>(10, vector<vector<int>>(10, vector<int>(n, 0))));

// инициализация единичками
for (int a = 0; a < 10; a++)
    for (int b = 0; b < 10; b++)
    {
        c = (a + b) / 10;
        if ((a + b) % 10 == s[0] - '0')
            dp[c][a][b][0] = 1;
    }

// заполняем дпшку
for (int k = 1; k < n; k++)
    for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
            for (int m = 0; m <= 1; m++)
            {
                c = (a + b + m) / 10;
                if ((a + b + m) % 10 == s[k] - '0')
                    for (int i = 0; i < 10; i++)
                        for (int j = 0; j < 10; j++)
                        {
                            if (a != i && b != j)
                            {
                                dp[c][a][b][k] += dp[m][i][j][k - 1];
                            }
                        }
            }

int answer = 0;

// делаем ответ по последним числам
for (int a = 1; a < 10; a++)
    for (int b = 1; b < 10; b++)
    {
        answer += dp[0][a][b][n - 1];
    }

cout << answer << '\n';