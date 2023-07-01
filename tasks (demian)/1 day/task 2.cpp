/*
    Найдите все натуральные числа, принадлежащие отрезку [45 000 000; 50 000 000], 
    у которых ровно пять различных нечётных делителей (количество чётных делителей может быть любым). 
    В ответе перечислите найденные числа в порядке возрастания.
*/

bool f(int n) {
    for (int i{2}; i < sqrt(n); i++)
        if (n % i == 0) 
            return false;
    return true;
}

int main() {
    int a;
    vector<int> d;

    for (int i{3}; i < pow(50000000, 0.25); i++)
        if (f(i)) d.push_back(i);
    
    for (int i{45000000}; i < 50000000; i++) {
        a = i;

        while (a % 2 == 0)
            a /= 2;
        
        if (find(d.begin(), d.end(), pow(a, 0.25)) != d.end() && 
            pow(pow(a, 0.25), 4) == a)
                cout << i << " ";
    }

    return 0;
}