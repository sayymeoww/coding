# DFS (ориент, неориент), поиск цикла, топсорт, эйлеров путь, ксс

* Рассказать что такое ориентированный/неориентированный граф
* Как хранить граф (список ребер, матрица смежности)

## DFS (обход в глубину)

* рассказать как писать dfs рекурсивно
* как писать dfs на stack
* Как обойти несколько компонент связности в неориент графе
* Как можно использовать `int used[N]` вместо bool для нескольких запусков dfs.
* Как искать цикл в графе (идем дфсом пока не встретим посещенную вершину но не родителя (хотя можно и родителя в ориент. графе))
* Эйлеров путь/цикл: [src with proof](https://neerc.ifmo.ru/wiki/index.php?title=%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%BF%D0%BE%D1%81%D1%82%D1%80%D0%BE%D0%B5%D0%BD%D0%B8%D1%8F_%D0%AD%D0%B9%D0%BB%D0%B5%D1%80%D0%BE%D0%B2%D0%B0_%D1%86%D0%B8%D0%BA%D0%BB%D0%B0).
  * Суть: идем дфсом. Но used массив только для ребер. При заходе в вершину кладем ее в stack S. Когда встречаем вершину, ребра которой все посещены, записываем ее в ответ и удаляем из стека.
  * Краткое док-во: Допустим, что в момент окончания работы алгоритма имеются еще не пройденные ребра. Поскольку граф связен, должно существовать хотя бы одно не пройденное ребро, инцидентное посещенной вершине. Но тогда эта вершина не могла быть удалена из стека и он не мог стать пустым. Значит алгоритм пройдёт по всем рёбрам хотя бы один раз. Но так как после прохода по ребру оно удаляется, то пройти по нему дважды алгоритм не может.

## топологическая сортировка

В ориентированом графе без циклов.

Сортирует вершины таким образом, что для любого ребра $u\to v$ вершина $u$ идет раньше $v$ в массиве.

Алгоритм через дфс (есть еще bfs, но про него не рассказываем тут):
* Добавляем вершину в массив когда идем по ребру. Утверждается что это корректно

### дп на топсорте

Задача: найти самый длинный путь в ориент графе без циклов. Решение: $dp[v]$ - макс длина пути из вершины $v$.

## Компоненты сильной связности

### Kosaraju’s algorithm

1. DFS проходим по графу и выписываем вершины в массив $A$ когда выходим из них. (что-то типа топсорта)
2. Реверсим ребра.
3. Идем с конца массива $A$ и для каждой вершины, которая еще не в КСС, запускаем из нее дфс по реверснутым ребрам и помечаем что все вершины, достижимые из нее с ней в ксс.

Почему это корректно?
* Если две вершины $u, v$ были взаимнодостижимы в графе, то они будут в одной ксс. Пусть $u$ шла в $A$ позже $v$. Тогда что $v\to u$ в оригинальном графе очевидно по 3 шагу. Но тк $v$ была раньше в $A$, мы вышли из нее раньше чем из $u$. С другой стороны, если бы не было пути $u\to v$, мы бы дошли из $v\to u$ и получили $u$ раньше в массиве $A$.
