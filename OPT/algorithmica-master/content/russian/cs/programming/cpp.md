---
title: Ликбез по C++
authors:
- Сергей Слотин
- Даниил Николенко
weight: 1
draft: true
---

Первый плюс плюсов - STL, она содержит в себе множество алгоритмов и структур, чтобы ее использовать вам нужно писать 

```
using namespace std;
```

https://en.cppreference.com/ — это сайт с документацией по языку C++. Там вы можете найти много полезной информации как о самом языке, так и о его стандартных библиотеках. Здесь же вы сможете найдите краткое изложение самого полезного из STL.

## Поговорим об обычных сишных массивах


```
T a[x]; // инициализация массива a типа T размера x
```

Если вы пишите так, прекращайте, у этого метода много проблем, давайте напишем правильную реализацию и обговорим плюсы и минусы.


```
array<T, x> a;
a.begin(), a.end() // указатели (итераторы) на начало и конец массива соответственно (конец массива = после последнего элемента)
a.front(), a.back() // возвращает ссылку на первый и последний элемент соответственно
cout << a.at(5); // метод at позволяет узнать не вышли ли мы за границы массива
```

Плюсы : 

1) Указатели (итераторы) на начало и конец - прекрасная вещь, которую мы обсудим позже

2) Сишные массивы уже сейчас противоречат шаблону, в будущем их хотят вообще убрать, так что лучше от них отказаться сейчас 

3) Быстрый переход от массива к вектору

Минусы :

1) Тяжело отвыкнуть от старого массива.

## vector

`vector` &mdash; это *динамический массив*. Это означает, что его размер может меняться во время исполнения программы, вы можете добавлять элементы в конец и так далее. Чтобы объявить пустой `vector`, способный содержать в себе целые числа типа `T`, необходимо воспользоваться следующей конструкцией:


```
vector<T> vector_name;
```

Здесь `T` &mdash; это тип элементов, которые будут содержаться в `vector`, а `vector_name` &mdash; имя самого `vector`. Как и другие контейнеры C++, `vector` не может содержать элементы разных типов!

Чтобы добавить элемент в конец вектора, необходимо воспользоваться функцией `push_back`. Эта функция работает в среднем за $O(1)$ .

Существуют два способа обращения к 'vector'. Оба мы уже обсудили в массивах.


```
vector<int> a;
cout << a[5];
cout << a.at(5);
```

Кроме этого вам также могут потребоваться следующие методы :

### Как работает vector?

Как уже было сказано, добавление в конец вектора работает в среднем за $O(1)$. Это означает, что, если вы сделаете $n$ операций `push_back`, они будут в сумме работать за $O(n)$. (Но при этом некоторые из них могли работать и за линейное время!)

У `vector` есть 2 важные величины: `size` и `capacity` &mdash; размер и вместимость. Размер &mdash; это то, сколько элементов сейчас находится в векторе. Вместимость &mdash; то, под сколько элементов памяти выделено. Когда `size` < `capacity`, `push_back` просто добавляет новый элемент в первую свободную ячейку уже выделенной памяти, поэтому работает за $O(1)$. Когда `size` = `capacity`, так сделать не удастся. Поэтому, происходит следующее:
1. `capacity` увеличивается примерно в 2 раза.
2. Выделяется область памяти, вмещающая `capacity` элементов.
3. Элементы из старой области памяти копируются в новую.
4. Старая область памяти освобождается.

Поймём, почему амортизированное время работы `push_back` действительно равно $O(1)$. Пусть сейчас `capacity` = $n$. Тогда мы выделяли $n + \frac{n}{2} + \frac{n}{4} + \dots < 2n$ памяти. На копирование также ушло не более $2n$ операций. Следовательно, так как операций `push_back` было хотя бы $\frac{n}{2}$, каждая операция в среднем работала за $O(1)$.

## pair

`pair` &mdash; это тип, содержащий пару значений, притом значения могут быть разных типов. Объявление пары выглядит так:


```
pair<T1, T2> p;
```

Здесь `T1` и `T2` &mdash; это имена первого и второго типов, соответственно.

Первый элемент пары &mdash; это `p.first`; второй &mdash; `p.second`.

`make_pair(a, b)` &mdash; функция, которая создаёт пару $(a, b)$.

Рассмотрим пример работы с `pair`.


```
pair<int, double> p = make_pair(1, 2.0);
pair<int, double> q = {1, 2.5}; // другой способ инициализировать пару
cout << p.first << " " << p.second << "\n";
```

## queue


В c++ уже реализована такая структура, как очередь, она названа queue.


```
queue<T> q; //очередь типа T
```

Очередь - структура, реализующая принцип FIFO (первый пришел - первый вышел),  то есть для очереди существуют две основные функции : Вставить в конец и достать с начала. 


```
q.front(); // ссылка на первый элемент
q.back(); // ссылка на последний элемент
q.push(x); // добавить в конец
q.pop(); //удалить с начала
```

## deque

deque - структура, позволяющая работать и с началом и концом одновременно, то есть вставка и удаление с двух сторон



```
deque<T> name; // дек типа T с названием name
name.front(), name.back(); // первый и последний элемент соответственно
name.pop_front(), name.pop_back(); // удаление первого и последнего элемента
name.push_front(x), name.push_back(x); // вставка x в начало/конец
```

Очередь и дек будут более подробно рассмотрены на одном из следующих занятий.
## set

`set` &mdash; это коллекция, которая содержит **множество** уникальных упорядоченных элементов.

Чтобы добавить элемент в `set`, есть функция `insert`. В случае, если элемент уже был в множестве, ничего не происходит.  
Чтобы удалить элемент из `set`, есть функция `erase`(в нее можно передать либо итератор на элемент, либо просто элемент). В случае, если элемента не было в множестве, ничего не происходит.  
Чтобы посмотреть, если ли элемент в `set`, есть функция `count`. Она вернёт $0$, если элемента нет в множестве, и $1$, если он есть.  Также есть метод `find`,  который возвращает итератор на элемент или `end`, если элемента нет.

Все операции с элементами `set` (добавление, удаление, поиск) работают за $O(\log n$), где $n$ &mdash; количество элементов в нём, так как он реализован с помощью сбалансированного двоичного дерева поиска.

Итераторы `set` относятся к категории `BidirectionalIterator` и имеют тип `set<T>::iterator`. Начало `set` можно получить с помощью функции `begin`, конец &mdash; с помощью функции `end`. Как и в случае с вектором, `end` указывает на конец полуинтервала. Инкремент и декремент итераторов `set` также работают за логарифмическое время.

Стоит отметить, что, так как элементы в `set` упорядочены, с помощью `begin` и `end` можно искать наименьший/наибольший элемент в `set`.
Чтобы найти наименьший элемент, больший или равный заданному, есть функция `lower_bound`.  
Чтобы найти наименьший элемент, строго больший заданному, есть функция `upper_bound`.  
Каждая из этих функций возвращает итератор на искомый элемент или `end()`, если такого элемента не существует.

`set` может содержать только элементы тех типов, для которых определён оператор `<`, поскольку ему важен порядок элементов.

Рассмотрим пример простейших операций с `set`.


```
set<int> s;

s.insert(3); // s = {3}
s.insert(2); // s = {2, 3}
cout << s.size() << "\n"; // выведет 2

s.insert(3); // 3 не будет добавлено ещё раз, так как уже присутствует в множестве
cout << s.size() << "\n"; // выведет 2

s.insert(5); // s = {2, 3, 5}
cout << s.count(3) << "\n"; // выведет 1
cout << s.count(4) << "\n"; // выведет 0

s.erase(3); // s = {2, 5}
s.insert(6); // s = {2, 5, 6}

set<int>::iterator it1 = s.find(5);
it1++;
cout << *it1 << "\n"; // выведет 6

auto it2 = s.lower_bound(1);
cout << *it2 << "\n"; // выведет 2, так как это первый элемент >= 1

auto it3 = s.upper_bound(2);
cout << *it3 << "\n"; // выведет 5, так как это первый элемент > 2.

auto it4 = s.upper_bound(10);
if (it4 == s.end()) {
    cout << "No element > 10\n"; // аккуратно, если разыменуете it4, получите undefined behaviour!
}

// вывод всех элементов сета с использованием итераторов; элементы следуют в порядке возрастания
for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
}
cout << "\n"; // но для таких целей лучше использовать range-based for loop!
```



### multiset

`multiset` &mdash; то же, что и `set`, но может содержать повторяющиеся элементы.

`count` работает за $O(\log n + c)$, где $c$ &mdash; количество искомых элементов. Поэтому, чтобы проверить наличие элемента $el$ в `multiset` `s`, надо воспользоваться: `s.find(el) != s.end()`.

`erase` удаляет все элементы с таким значением. Чтобы удалить один надо делать так: `s.erase(s.find(el)).


### Примеры применения сета для решения задач

Очень часто использование сета позволяет решить задачу, которая решается и абсолютно другим способом. Иногда более сложным, а иногда и более простым. Чаще всего сет используется, если нужно сделать что-то, связанное с **количеством разных элементов** или с **минимумом или максимум какого-то множества**.

#### 1) Задача Девшука или Юноша

**Условие:** http://codeforces.com/contest/236/problem/A

**Условие вкратце:** Найти чётность числа различных символов в строке.

**Решение:** вставим все символы в сет и проверим четность размера сета.

Заметим, что эту задачу можно легко решить и подсчетом (как в сортировке подсчетом), так как символов бывает очень мало.

#### 2) A и B и ошибки компиляции

**Условие:** http://codeforces.com/contest/519/problem/B

**Условие вкратце:** Из массива убрали ровно одно число и перемешали элементы. Затем сделали так еще раз. Найдите, какие два элемента исчезли.

**Решение:** Добавим все числа в 3 различных мультисета, затем просто пройдемся по ним и найдем первый элемент, которого во втором меньше, чем в первои, но есть в первом. Мы нашли первую ошибку, вторая находится точно также.

Заметим, что эту задачу можно было бы легко решить и просто отсортировав все числа, что асимптотически тоже $O(N log N)$.

#### 3) Минимум на отрезке

**Условие:** https://informatics.msk.ru/mod/statements/view3.php?chapterid=756

**Условие вкратце:** Найти минимум на каждом отрезке длины $K$ в массиве.

**Решение:** Давайте положим в мультисет первые $K$ элементов. Далее мы будем двигать это "окно": добавлять новый элемент справа и убирать самый левый элемент. Каждый раз будем выводить минимум в сете, который лежит в `s.begin()`.

Также эта задача решается такими структурами данных как

1) Очередь с минимумом (за $O(N)$!)

2) Дерево отрезков

3) Sparse Table

4) Куча

Но решить задачу сетом гораздо проще.

## map

`map` &mdash; это ассоциативный контейнер: он содержит пары *ключ-значение*, при этом все ключи уникальны. Внутри контейнера все ключи упорядочены по возрастанию. Так же, как и в `set`, операции работают за логарифмическое время.

Объявление `map` выглядит так: `map<T1, T2> map_name`, где `T1` &mdash; тип ключа, `T2` &mdash; тип значения.

Доступ к элементам `map` осуществляется с помощью оператора `[]`. `map`, аналогично `set`, поддерживает поиск по ключу с помощью `find`, `lower_bound`, `upper_bound`. При разыменовании итератора получается пара, первый элемент которой &mdash; ключ, второй &mdash; значение.

При обращении к несуществующему элементу `map` с помощью `[]`, значение инициализируется значением по умолчанию для данного типа.

Рассмотрим работу `map` на примере:


```
map<int, int> a;
a[13] = 5;
a[2] = 7;
cout << a[2] << "\n"; // выведет 7
a[2]++;
cout << a[2] << "\n"; // выведет 8
a[100] = 42;

/* Этот цикл выведет 3 строки:
   2 8
   13 5
   100 42

   Обратите внимание, что ключи упорядочены.
*/
for (auto el : a) {
    cout << el.first << " " << el.second << "\n";
}


map<string, int> b;
b["Bob"]--;
b["Alice"] += 2;
b["Dan"] = 123;

/* Этот цикл выведет 2 строки:
   Alice 2
   Bob -1
   Dan 123
*/
for (auto el : b) {
    cout << el.first << " " << el.second << "\n";
}

map<string, vector<int>> c;
c["wow"].push_back(2);
c["abc"] = {2, -1, 17};
cout << c["abc"].size() << "\n"; // выведет 3
```

## Unordered структуры данных

Единственная проблема set и map - то что они работают за $\log(n)$, что в некоторых задачах долго. Тогда возникает идея построить их не на двоичном дереве, а например на хештаблице (о ней вы узнаете на втором курсе), тогда unordered_set поддерживает вставку и удаление за $O(1)$, единственная проблема - он содержит элементы в неотсортированном порядке, то есть мы уже не сможем искать минимум, максимум.

На питоне встроенные set и dict - это именно аналоги unordered_set  и unordered_map. Упорядоченного сета и мэпа на питоне нет.


```
unordered_set<int> a;
a.insert(x);
a.erase(x);
```

## Полезные функции из algorithm

### swap
`swap(a, b)` &mdash; обменивает значения переменных `a` и `b` местами.


```
int a = 5;
int b = 3;
cout << a << " " << b << "\n"; // выведет 5 3
swap(a, b);
cout << a << " " << b << "\n"; // выведет 3 5
```

### min_element и max_element
`min_element(first, last)` &mdash; возвращает итератор на минимум на полуинтервале `[first; last)`.  
`max_element(first, last)` &mdash; возвращает итератор на максимум на полуинтервале `[first; last)`.


Если минимумов/максимумов несколько, то возвращается первое вхождение.


```
vector<int> numbers = {5, 3, 1, 2, 1};
auto it = min_element(numbers.begin(), numbers.end());
cout << *it << " " << (it - numbers.begin()) << "\n"; // выведет 1 2
```

### reverse
`reverse(first, last)` &mdash; переворачивает полуинтервал `[first; last)` (элементы идут в обратном порядке).


```
vector<int> a = {5, 2, 3, 10, 17};
reverse(a.begin(), a.begin() + 3);
for (int x : a) {
    cout << x << " ";
}
cout << "\n";
```

В этом примере будет выведено `3 2 5 10 17 `.

### sort, unique и компараторы

`sort(first, last)` &mdash; сортирует полуинтервал `[first; last)`.


```
vector<int> a = {5, 2, 10, 11, 2, 3};
sort(a.begin(), a.end()); // сортируем весь вектор
for (int x : a) {
    cout << x << " ";
}
cout << "\n";
```

В этом примере будет выведено `2 2 3 5 10 11`.

Функция `sort` может принимать третий параметр &mdash; *компаратор*. Компаратор &mdash; это функция, которая принимает два объекта и возвращает `true`, если первый *строго меньше* второго, и `false` иначе.

Допустим, нам хотелось бы отсортировать числа по возрастанию их последней цифры, а при совпадении &mdash; по самому значению. Тогда мы могли бы написать следующий код:


```
bool cmp(int a, int b) {
    return make_pair(a % 10, a) < make_pair(b % 10, b);
}

// это внутри main
vector<int> a = {30, 32, 12, 7, 15};
sort(a.begin(), a.end(), cmp);
for (int x : a) {
    cout << x << " ";
}
cout << "\n";
```

В данном примере, как мы и хотели, будет выведено `30 12 32 15 7`.

`unique(first, last)` &mdash; принимает полуинтервал и удаляет все последовательные повторения элементов в нём. Функция возвращает итератор на конец полуинтервала, соответствующему уникализированным элементам. Значения элементов, которые следуют после этого полуинтервала, становятся неопределёнными. Поэтому рекомендуется использовать функцию `unique`, например, вместе с функцией `resize`.


```
vector<int> a = {5, 5, 5, 1, 5, 4, 4, 7, 1};
a.resize(unique(a.begin(), a.end()) - a.begin());
for (int x : a) {
    cout << x << " ";
}
cout << "\n";
```

В данном примере будет выведено `5 1 5 4 7 1`.

Часто требуется сначала отсортировать элементы, а потом убрать все повторения. Это делается следующей комбинацией:


```
sort(a.begin(), a.end());
a.resize(unique(a.begin(), a.end()) - a.begin());
```

### nth_element

Функция ставит на переданную позицию элемент, который был бы на этом месте после сортировки массива(работает за линию).


```
nth_element(begin, need, end); // need - позиция отсортированного массива, 
//begin, end - итераторы на начало и конец места, которое надо сортировать.
```

### next_permutation, prev_permutation

Генерирует следующую и предыдущую перестановку массива на отрезке с l по r;


```
next_permutation(l, r);//l, r - итераторы
prev_permutation(a.begin(), a.end());
```

### merge


```
merge(начало первой последовательности, конец первой последовательности, начало 
второй последовательности, конец второй последовательности, куда вставлять);
```

Слияние двух массивов, которое используется в сортировке слиянием.

### lower_bound, upper_bound, binary_search

Все эти функции принимают полуинтервал `[first; last)` и значение `value`. Полуинтервал должен быть упорядочен по отношению `element < value` (сначала те элементы, которые удовлетворяют этому, потом остальные).

`lower_bound` &mdash; возвращает первый элемент, больший или равный `value`.  
`upper_bound` &mdash; возвращает первый элемент, строго больший `value`.  
`binary_search` &mdash; возвращает, присутствует ли `value` на этом полуинтервале.


```
vector<int> a = {1, 5, 5, 6, 7, 10};

auto it1 = lower_bound(a.begin(), a.end(), 5);
cout << (it1 - a.begin()) << "\n"; // выведет 1

auto it2 = upper_bound(a.begin(), a.end(), 5);
cout << *it2 << "\n"; // выведет 6

if (binary_search(a.begin(), a.end(), 7)) {
    cout << "There is an element = 7\n"; // это будет выведено
}
```

#### Внимание!
Не используйте `lower_bound`, `upper_bound`, `binary_search` вместе с `set`/`map`! Они будут работать за линейное время. Используйте их собственные функции: `set::lower_bound` (вызывается через `.`) и так далее.

## Ускорение ввода и вывода

Стандартные `cin` и `cout` работают *очень* медленно. Чтобы исправить это, в начале вашей функции `main` пишите следующее:


```
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
```

Это позволяет ускорить ввод и вывод в разы!

Также крайне не рекомендуется использовать `endl` (кроме интерактивных задач). Используйте `"\n"`. Они отличаются тем, что `endl` делает `flush` вывода, то есть сразу же выводит то, что вы хотите. Если вы будете использовать `"\n"`, вывод будет накапливаться, а потом единожды выводиться, что гораздо быстрее.

## Задание

Это просто олимпиадные задачи, но почти в любой задаче можно использовать STL, чтобы упростить себе жизнь.

* Решите как можно больше задач в контесте на информатиксе: https://informatics.msk.ru/mod/statements/view3.php?id=34778&chapterid=756#1
* Решите как можно больше задач в контесте на codeforces: 
http://codeforces.com/group/g92L0id9Yb/contest/229989


### swap

`swap(a, b)` обменивает значения переменных `a` и `b` местами.

``` c++ numberLines
int a = 1, b = 2;
cout << a << ' ' << b << '\n'; // выведет 1 2
swap(a, b);
cout << a << ' ' << b << '\n'; // выведет 2 1
```

### min_element и max_element

`min_element(first, last)` возвращает итератор на минимум на
полуинтервале `[first; last)`. `max_element(first, last)`
возвращает итератор на максимум на полуинтервале `[first; last)`.

Если минимумов/максимумов несколько, то возвращается первое вхождение.

``` C++
vector<int> numbers = {5, 3, 1, 2, 1};
auto it = min_element(numbers.begin(), numbers.end());
cout << *it << " " << (it - numbers.begin()) << "\n"; // выведет 1 2
```

### nth_element

`nth_element(first, need, last)` ставит в позицию `need` элемент,
который был бы на этом месте после сортировки всех элементов в
полуинтервале `[first; last)`. `first`, `need` и `last` - итераторы.
Функция работает за линию.

### sort и компараторы

`sort(first, last)` сортирует полуинтервал `[first; lasst)`.

``` C++
vector<int> a = {5, 2, 10, 11, 2, 3};
sort(a.begin(), a.end()); // сортируем весь вектор
for (int x : a) {
    cout << x << " ";
}
cout << "\n";
// будет выведено 2 2 3 5 10 11
```

Функция `sort` может принимать третий параметр - компаратор. Компаратор
- это функция, которая принимает два объекта и возвращает `true`, если
первый строго меньше второго, и `false` иначе.

Допустим, нам хотелось бы отсортировать числа по возрастанию их
последней цифры, а при совпадении — по самому значению. Тогда
мы могли бы написать следующий код:

``` C++
bool cmp(int a, int b) {
    return make_pair(a % 10, a) < make_pair(b % 10, b);
}

// это внутри main
vector<int> a = {30, 32, 12, 7, 15};
sort(a.begin(), a.end(), cmp);
for (int x : a) {
    cout << x << " ";
}
cout << "\n";
// будет выведено 30 12 32 15 7
```

### stable_sort

TODO

### unique

`unique(first, last)` принимает полуинтервал и удаляет все
последовательные повторения элементов в нём. Функция
возвращает итератор на конец полуинтервала, соответствующему
уникализированным элементам. Значения элементов, которые следуют
после этого полуинтервала, становятся неопределёнными. Поэтому
рекомендуется использовать функцию `unique`, например, вместе с
функцией `resize`.

``` C++
vector<int> a = {5, 5, 5, 1, 5, 4, 4, 7, 1};
a.resize(unique(a.begin(), a.end()) - a.begin());
for (int x : a) {
    cout << x << " ";
}
cout << "\n";
// будет выведено 5 1 5 4 7 1
```

Если нужно удалить все повторения элементов (не только соседних), то
нужно сначала отсортировать их. Это делается так:

``` C++
sort(a.begin(), a.end());
a.resize(unique(a.begin(), a.end()) - a.begin());
```

### merge

merge(first1, last1, first2, last2, d_first) сливает два
отсортированных полуинтервала `[first1; last1)` и
`[first2; last2)` в один, начиная с `d_first` и возвращает итератор на
следующий за последним элемент.

### back_inserter

Стандартная задача: слить отсортированные векторы `vec1`, `vec2` в
вектор `res`. Можно реализовать так:

``` C++
vector<int> res;
merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(res));
```

Здесь используется `back_inserter`. Подробнее можно почитать
[тут](http://www.cplusplus.com/reference/iterator/back_insert_iterator/).
Если не использовать back_inserter, код получился бы таким:

``` C++
vector<int> res(vec1.size() + vec2.size());
merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), res.begin());
```

В первом варианте код красивее, но дольше работает, так как `res`
расширится несколько раз. Решайте, каким методом пользоваться,
опираясь на ограничения в задачах.

### reverse

`reverse(first, last)` переворачивает полуинтервал `[first; last)`
(элементы идут в обратном порядке).

``` C++
vector<int> a = {5, 2, 3, 10, 17};
reverse(a.begin(), a.begin() + 3);
for (int x : a) {
    cout << x << " ";
}
cout << "\n";
// будет выведено 3 2 5 10 17
```

### rotate

`rotate(first, n_first, last)` переставляет элементы в полуинтервале
`[first; last)` так, что элемент `n_first` становится первым, а `n_first
- 1` - последним. Например, циклический сдвиг вектора `v` влево можно
реализовать так:

``` C++
rotate(v.begin(), v.begin() + 1, v.end());
```

### next_permutation и prev_permutation

Генерируют следующую и предыдущую перестановку. Например, чтобы
перебрать все уникальные перестановки в векторе `a`, можно
написать такой код:

``` C++
sort(a.begin(), a.end());
do {
  ... // тело цикла
} while (next_permutation(a.begin(), a.end()));
```

### lower_bound, upper_bound, binary_search

Все эти функции принимают полуинтервал `[first; last)` и значение
`value`. Полуинтервал должен быть упорядочен по отношению `element <
value` (сначала те элементы, которые удовлетворяют этому, потом
остальные).

`lower_bound` - возвращает указатель на первый элемент, больший или
равный `value`. `upper_bound` - возвращает указатель на первый
элемент, строго больший `value`. `binary_search` — возвращает,
присутствует ли `value` на этом полуинтервале.

``` C++
vector<int> a = {1, 5, 5, 6, 7, 10};

auto it1 = lower_bound(a.begin(), a.end(), 5);
cout << (it1 - a.begin()) << "\n"; // выведет 1

auto it2 = upper_bound(a.begin(), a.end(), 5);
cout << *it2 << "\n"; // выведет 6

if (binary_search(a.begin(), a.end(), 7)) {
    cout << "There is an element = 7\n"; // это будет выведено
}
```

<b>Внимание\!</b>

Не используйте `lower_bound`, `upper_bound`, `binary_search` вместе с
`set`/`map`\! Они будут работать за линейное время. Используйте их
собственные функции: `set::lower_bound` (вызывается как
`s.lower_bound(elem)`) и так далее.

### fill

`fill(first, last, value)` присваивает значение `value` всем элементов
полуинтервала `[first; last)`.

### copy

`copy(first, last, d_first)` копирует элементы полуинтервала `[first;
last)` в диапазон, начиная с `d_first`.

Стандартные `cin` и `cout` работают очень медленно. Чтобы в разы их
ускорить (и, возможно, побороть TLE), в начале `main` пишите
следующее (в интерактивных задачах делать этого <b>не надо</b>):

``` C++
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
```

Также крайне не рекомендуется использовать `endl` (кроме интерактивных
задач). Используйте `"\n"`. Они отличаются тем, что `endl` делает
`flush` вывода, то есть сразу же выводит то, что вы хотите. Если вы
будете использовать `"\n"`, вывод будет накапливаться, а потом
единожды выводиться, что гораздо быстрее.