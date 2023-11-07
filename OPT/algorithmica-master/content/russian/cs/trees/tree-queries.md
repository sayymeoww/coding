---
title: Запросы на деревьях
weight: 1
authors:
- Сергей Слотин
prerequisites:
- /cs/graph-traversals/dfs
- /cs/range-queries
- /cs/segment-tree
---

В этой статье мы рассмотрим различные методы сведения задач на деревьях к задачам на отрезках, которые можно решать уже известными структурами данных.

Перед прочтением рекомендуется вспомнить свойства массивов $tin$ и $tout$, получаемых [обходом в глубину](/cs/graph-traversals/dfs).

## Запросы на поддеревьях

Первым важным свойством `dfs` является то, что $tin$-ы вершин любого поддеререва являются каким-то непрерывным отрезком.

Это свойство можно использовать для обработки разных запросов на поддеревьях, сводя их к запросам на подотрезках, которые уже можно решать стандартными методами — например, через [дерево отрезков](/cs/segment-tree).

### Сумма на поддереве

**Задача.** Дано корневое дерево. Рядом с каждой вершиной записано число. Поступают два типа запросов: изменить какое-то из значений и найти сумму значений на поддереве вершины $v_i$.

Выпишем все числа у вершин в один массив в позиции, соответствующие их $tin$-ам. Что такое «сумма на поддереве $v$» в терминах этого массива? Это просто сумма на подотрезке $[tin_v, tout_v)$.

Построим поверх массива дерево отрезков или любую другую структуру для динамической суммы, и для запросов первого типа будем отправлять структуре запрос изменения ячейки $a_{tin_v} = x$, а для второго будем делать запрос суммы на подотрезке $[tin_v, tout_v)$.

## Запросы на уровнях

Помимо $tin$ и $tout$ бывает полезно во время обхода считать *глубину* вершины. Будем в дальнейшем обозначать её за $depth_v$.

### Level Ancestor

**Задача.** Дано корневое дерево. Требуется отвечать на запросы нахождения $d_i$-того предка вершины $v_i$, то есть вершины-предка, находящейся на расстоянии $d_i$ от $v_i$.

Создадим $h$ векторов, где $h$ — высота дерева. Для каждой вершины, во время прохода в dfs, добавим её $tin$ в вектор, соответствующей её глубине. Получаем $h$ отсортированных векторов.

Теперь заметим, что внутри одного вектора все отрезки поддеревьев вершин — $[tin_v, tout_v)$ — тоже не пересекаются, а значит ещё и отсортированы. Тогда для ответа на запрос мы можем просто взять $tin$ вершины-запроса, посмотреть на вектор нужного уровня и за $O(\log n)$ сделать бинпоиск по нужному отрезку.

Также существует другой способ, требующий $O(1)$ времени на запрос, но $O(n \log n)$ памяти на предподсчет — [лестничная декомпозиция](https://neerc.ifmo.ru/wiki/index.php?title=Level_Ancestor_problem).

### Поддеревья заданной глубины

**Задача.** Дано корневое дерево. Рядом с каждой вершиной записано число. Поступают два типа запросов: изменить какое-то из значений и найти сумму значений на поддереве вершины $v_i$ *среди вершин на расстоянии не более $k_i$ от неё*.

Когда используется одновременно и глубина, и структура дерева, обычно помогает взглянуть на задачу геометрически. Сопоставим каждой вершине точку $(tin_u, depth_u)$. Тогда как выглядят искомые множества вершин? Они соответствуют тем точкам, у которых первая координата лежит между $tin_v$ и $tout_v$, а вторая больше $depth_v$.

Соответственно, запросы на таких поддеревьях можно свести к запросам на прямоугольниках, которые можно решать либо «в лоб» двумерными структурами, либо применить методы вроде сканирующей прямой.

## Запросы на путях

Если даны запросы на путях в оффлайн, то почти всегда их можно решить каким-то предподсчетом.

### Сумма на пути

**Задача.** Дано дерево. У каждого ребра есть какое-то число. Нужно отвечать на запросы нахождения суммы на пути.

Предподсчитаем во время обхода в глубину массив $s$, где $s_v$ это сумма чисел на пути от корня до вершины $v$.

Любой путь в дереве разбивается на один или два вертикальных пути. Найдем [наибольшего общего предка](../lca-rmq) $c = lca(a, b)$ и разобьём сумму как $(s_a + s_b - 2 \cdot s_c)$.

### Xor на пути

**Задача.** Дано дерево. У каждого ребра есть какое-то число. Нужно отвечать на запросы нахождения `xor`-суммы на пути.

Заметим, что в случае с `xor`-суммой не нужно даже искать эти пути — по модулю двойки слагаемое $2 \cdot s_c$ «отменит» само себя. Достаточно просто вывести `s[a] ^ s[b]`.

### Число различных чисел на пути

**Задача.** Дано дерево. У каждого ребра есть какое-то число. Требуется отвечать на $q$ запросов нахождения числа различных значений на пути с $v$ по $u$.

Для более сложных запросов в оффлайн почти всегда нужно использовать обобщение алгоритма Мо на деревья, заключающееся примерно в следующем.

- Выпишем эйлеров обход дерева: при каждом проходе по ребру выписываем номер ребра (номер нижней/верхней вершины). Заметим, что каждое ребро будет выписано дважды: при входе и выходе из нижней вершины.
- Получив запрос, определим «более раннюю» вершину $v$ (с меньшим $tin_v$) и рассмотрим подотрезок эйлерова обхода с $tin_v$ по $tin_u$.
- Какая-то подпоследовательность ребер на этом отрезке является кратчайшим путем между $v$ и $u$. А именно, это будут ровно те ребра, которые встречались на этом отрезке ровно один раз — все, которые встречались дважды, ведут в какие-то побочные поддеревья.

Теперь рядом с номерами ребер в обходе выпишем ещё и соответствующие им числа. Тогда запрос нахождения числа различных значений на пути эквивалентен нахождению числа различных значений у ребер, встречающихся ровно один раз на подотрезке. Эту задачу уже можно решить обычным алгоритмом Мо.