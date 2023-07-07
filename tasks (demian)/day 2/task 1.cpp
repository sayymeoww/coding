/*
    Найдите все натуральные числа N, принадлежащие отрезку [400 000 000; 600 000 000], 
    которые можно представить в виде N  =  2^m · 3^n, где m  — чётное число, n  — нечётное число. 
    В ответе запишите все найденные числа в порядке возрастания.
*/

//[400`000`000 ... 600`000`000]
//2^m * 3^n (m - четное, n - нечетное)
vector<int> twos, threes;
int two = 1, three = 3;
twos.push_back(two);
threes.push_back(three);

for (int i{0}; i <= 18; i++) {
    two *= 4;
    three *= 9;

    twos.push_back(two);
    threes.push_back(three);
}

vector<int> answer;
for (auto two : twos)
    for (auto three : threes)
        if (two * three >= 400000000 && two * three <= 600000000)
            answer.push_back(two * three);

sort(answer.begin(), answer.end());
for (auto el : answer)
    cout << el << " ";