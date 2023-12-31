---
title: Верхние и нижние огибающие
weight: 5
---

Для большого количества применений нам на самом деле нужны не выпуклые оболочки, а только их половины (правые и левые или верхние и нижние), которые называют *огибающими* (англ. *envelope*).

Огибающие строить немного проще: можно отсортировать точки по $x$ и пройтись по ним в таком порядке, поддерживая на стеке верхнюю огибающую для текущего префикса. При добавлении очередной точки нам нужно аналогичным образом проверить и удалить сколько-то верхних точек на стеке:

```c++
vector<r> upper_envelope(vector<r> points) {
    sort(points.begin(), points.end(), [](r a, r b){
        return a.x < b.x;
    });

    vector<r> s = {p0};
    for (r p : points) {
        while (...) {
            s[s.size()-2] = s[s.size()-1];
            s.pop_back();
        }
        s.push_back(p);
    }

    return s;
}
```

С огибающими работать легче, чем с целыми оболочками: их легко пересекать, объединять и делать бинпоиск (например, чтобы находить касательные). Объединение, кстати, можно производить за линейное время, пройдясь двумя указателями по обеим оболочкам одновременно, что позволяет альтернативно строить огибающую методом «разделяй и властвуй», тоже за $O(n \log n)$.

Иногда имеет смысл разбить оболочку на две огибающие и работать с ними по отдельности. Основной минус такого подхода в том нужно либо писать в два раза больше кода, либо писать его так, чтобы все внутренние процедуры не отличали «выше» от «ниже» — тогда точки нижней огибающей можно передавать в те же рутины, что и для верхней, заменив $y_i$ на $-y_i$.

Также для построения выпуклой оболочки можно поступить следующим образом: построить верхнюю огибающую, построить нижнюю огибающую, а затем одну из них перевернуть и добавить в конец другой. Если точки уже отсортированы по $x$, $y$ или вдоль любой другой прямой, алгоритм будет работать за $O(n)$. Такой подход называется *алгоритмом Эндрю*.

### Динамические выпуклые оболочки

Оперируя с оболочкой как с двумя огибающими, можно относительно просто обрабатывать запросы добавления точек, обернув огибающие в `std::set` или любое другое дерево так, что они оказываются отсортированными по $x$. При добавлении точки нужно найти её позицию в дереве, проверить, что она находится выше огибающей, и, возможно, удалить сколько-то её левых и правых соседей.

Обрабатывать *удаление* точки из множества сложнее. Если запросы известны заранее, то проще воспользоваться идеями корневой эвристики или dynamic connectivity problem и поддерживать только те точки, которые существуют на всем текущем блоке, и сводить удаление к добавлению.

Если же запросы удаления требуется обрабатывать онлайн (fully dynamic convex hull), то для этого есть [очень неприятный алгоритм](https://neerc.ifmo.ru/wiki/index.php?title=%D0%94%D0%B8%D0%BD%D0%B0%D0%BC%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B0%D1%8F_%D0%B2%D1%8B%D0%BF%D1%83%D0%BA%D0%BB%D0%B0%D1%8F_%D0%BE%D0%B1%D0%BE%D0%BB%D0%BE%D1%87%D0%BA%D0%B0_%28%D0%B4%D0%BE%D1%81%D1%82%D0%B0%D1%82%D0%BE%D1%87%D0%BD%D0%BE_log%5E2_%D0%BD%D0%B0_%D0%B4%D0%BE%D0%B1%D0%B0%D0%B2%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5/%D1%83%D0%B4%D0%B0%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5%20) на 250-300 строк кода, заключающийся в поддержании огибающих для всех поддеревьев в этом дереве поиска и быстром объединении огибающих при перестроении дерева. Алгоритм работает за $O(\log^2 n)$ на запрос: при слиянии огибающих при объединении вершин используется бинпоиск с разбором 7 случаев.
