/*
    Перед вами квадратная матрица ячеек. В каждой ячейке находится одно целое число. 
    Одинаковых чисел в матрице нет. Вам надо разделить матрицу на непересекающиеся цепочки.

    Цепочкой называется такая последовательность различных ячеек, в которой две соседние 
    ячейки имеют общую сторону и числа в этой последовательности «почти» возрастают. 
    Это означает, что можно исключить не более 1 числа из последовательности, чтобы получилась 
    возрастающая последовательность.

    Цепочки пересекаются, если имеют общую ячейку.
    Не должно быть двух цепочек, ячейки которых можно объединить и получить новую цепочку.

    Сначала идет размерность матрицы — целое число от 1 до 100. Затем идут элементы матрицы по строкам. 
    Каждое число по модулю не превосходит 10000.

    Распечатайте одно из разбиений матрицы на цепочки. Сначала распечатайте количество цепочек. 
    Затем печатайте каждую цепочку на отдельной строке. Цепочку требуется выводить в формате - 
    число элементов в цепочки, затем сами элементы Числа в строке печатайте в десятичном виде 
    через пробелы.
*/

using snake = vector<int>;          //тип змейка
using field = vector<vector<int>>;  //тип поле
using coord = pair<int, int>;       //тип координат

snake s;        // инициализация змейки
field f;        // инициализация поля
field visited;  // посещенные клетки

int posx, posy; // текущая позиция
int cx, cy;     // позиция соседней клетки

// направления движения
vector<pair<int, int>> directions = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

// проверяем соседнюю клетку на возможного кандидата
bool checkCell(int x, int y, int n, field visited) {
    return (x >= 0 && y >= 0 && x <= n - 1 && y <= n - 1 && visited[x][y] == 0);
}

// получаем соседей
vector<coord> neighbours(int x, int y, int n, field visited) {
    vector<coord> answer = {};

    for (auto diff : directions) {
        if (checkCell(x + diff.first, y + diff.second, n, visited)) {
            answer.push_back({x + diff.first, y + diff.second});
        }
    }

    return answer;
}

// проверяем можем ли мы добавить
bool check(snake s, int el) {
    if ((int)s.size() == 0) return true;

    s.push_back(el);

    if ((int)s.size() <= 2) return true;

    snake ns = {-inf};
    for (auto el : s)
        ns.push_back(el);

    int u = 0; //ups
    int d = 0; //downs
    int index = inf;

    for (int i = 1; i < (int)ns.size(); i++) {
        if (ns[i] < ns[i - 1]) {
            index = i - 1;
            break;
        }
    }

    if (index == inf)
        return true;

    ns.erase(ns.begin() + index);

    for (int i = 1; i < (int)ns.size(); i++) {
        if (ns[i] > ns[i - 1]) u++;
        else if (ns[i] < ns[i - 1]) d++;
    }

    int len = (int)ns.size();

    return (d == 0 && u == len - 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // * start coding here
    // * (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
    
    int n;
    cin >> n;

    vector<snake> answer; // вектор змеек
    
    //ставим размеры у полей
    f.resize(n, vector<int>(n));
    visited.resize(n, vector<int>(n));
    visited.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> f[i][j];
        }
    }

    // начальные позиции
    posx = 0;
    posy = 0;

    int moves = 0; // количество ходов

    s = {f[posx][posy]}; // начальная змейка

    while (moves < n * n) {
        visited[posx][posy] = 1; // мы эту позицию посетили

        if ((int)s.size() == 0)
            s.push_back(f[posx][posy]);

        bool flag = false;
        
        vector<coord> cells = neighbours(posx, posy, n, visited); // получаем соседей

        if ((int) cells.size() != 0){
            for (auto cell : cells) {
                cx = cell.first;
                cy = cell.second;
                
                // проверяем можем ли мы добавить
                if (check(s, f[cx][cy]) && !flag) {
                    s.push_back(f[cx][cy]);

                    posx = cx;
                    posy = cy;

                    visited[cx][cy] = 1;

                    flag = true;

                    break;
                }
            }

            // если ничего не добавили - заносим змейку в ответ и ищем новые координаты
            if (!flag) {
                answer.push_back(s);
                s.clear();

                bool F = false;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (visited[i][j] == 0) {
                            posx = i;
                            posy = j;

                            F = true;
                            break;
                        }
                    }
                    if (F) break;
                }

                if (!F) break;
            }
        } else { // если змейка нулевая
            answer.push_back(s);
            s.clear();

            bool F = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (visited[i][j] == 0) {
                        posx = i;
                        posy = j;

                        F = true;
                        break;
                    }
                }
                if (F) break;
            }

            if (!F) break;
        }

        moves++;
    }

    // выводим ответ
    cout << (int)answer.size() << '\n';
    for (auto Snake : answer) {
        for (auto el : Snake) {
            cout << el << " ";
        }
        cout << '\n';
    }

    return 0;
}