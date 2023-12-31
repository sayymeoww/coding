/*
    Напишите программу, которая ищет среди целых чисел,
    принадлежащих числовому отрезку [174457; 174505],
    числа, имеющие ровно два различных натуральных делителя,
    не считая единицы и самого числа.

    Для каждого найденного числа запишите эти два делителя
    в два соседних столбца на экране с новой строки в порядке
    возрастания произведения этих двух делителей. Делители
    в строке также должны следовать в порядке возрастания.

    Например, в диапазоне [5; 9] ровно два различных натуральных делителя имеют
   числа 6 и 8, поэтому для этого диапазона вывод на экране должна содержать
   следующие значения: 2 3 2 4
*/

vector<int> del(2);

for (int i{174457}; i <= 174505; i++) {
    int count = 0;

    for (int d = 2; d < i / 2; d++) {
        if (i % d == 0) {
            count++;
            del[count - 1] = d;
        }

        if (count > 2) break;
    }

    if (count == 2) cout << del[0] << " " << del[1] << '\n';
}