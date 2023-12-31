---
title: Сведение игр к ниму
weight: 7
draft: true
---


Примеры игр
Для наглядной демонстрации теории Шпрага-Гранди, разберём несколько задач.

Особо следует обратить внимание на задачи "лестничный ним", "nimble-2", "turning turtles", в которой демонстрируется нетривиальное сведение исходной задачи к ниму с увеличениями.

"Крестики-крестики"
Условие. Рассмотрим клетчатую полоску размера 1 \times n клеток. За один ход игроку надо поставить один крестик, но при этом запрещено ставить два крестика рядом (в соседние клетки). Проигрывает тот, кто не может сделать ход. Сказать, кто выиграет при оптимальной игре.

Решение. Когда игрок ставит крестик в какую-либо клетку, можно считать, что вся полоска распадается на две независимые половинки: слева от крестика и справа от него. При этом сама клетка с крестиком, а также её левый и правый сосед уничтожаются — т.к. в них больше ничего нельзя будет поставить.

Следовательно, если мы занумеруем клетки полоски от 1 до n, то, поставив крестик в позицию 1 < i < n, полоска распадётся на две полоски длины i-2 и n-i-1, т.е. мы переходим в сумму двух игр i-2 и n-i-1. Если же крестик ставится в позицию 1 или n, то это особый случай — мы просто перейдём в состояние n-2.

Таким образом, функция Гранди g[n] имеет вид (для n \ge 3):

 g[n] = {\rm mex} \Bigg\{ g[n-2], \bigcup_{i=2}^{n[...]

Т.е. g[n] получается как \rm mex от множества, состоящего из числа g[n-2], а также всевозможных значений выражения g[i-2] \oplus g[n-i-1].

Итак, мы получили решение этой задачи за O (n^2).

На самом деле, посчитав на компьютере таблицу значений для первой сотни значений n, можно увидеть, что, начиная с n=52, последовательность g[n] становится периодичной с периодом 34. Эта закономерность сохраняется и дальше (что, вероятно, можно доказать по индукции).

"Крестики-крестики — 2"
Условие. Снова игра ведётся на полоске 1 \times n клеток, и игроки по очереди ставят по одному крестику. Выигрывает тот, кто поставит три крестика подряд.

Решение. Заметим, что если n>2 и мы оставили после своего хода два крестика рядом или через один пробел, то противник следующим ходом выиграет. Следовательно, если один игрок поставил где-то крестик, то другому игроку невыгодно ставить крестик в соседние с ним клетки, а также в соседние с соседними (т.е. на расстоянии 1 и 2 ставить невыгодно, это приведёт к поражению).

Тогда решение получается практически аналогичным предыдущей задаче, только теперь крестик удаляет у каждой половинки не по одной, а сразу по две клетки.

"Пешки"
Условие. Есть поле 3 \times n, на котором в первом и третьем ряду стоят по n пешек — белых и чёрных, соответственно. Первый игрок ходит белыми пешками, второй — чёрными. Правила хода и удара — стандартные шахматные, за исключением того, что бить (при наличии такой возможности) обязательно.

Решение. Проследим, что происходит, когда одна пешка сделает ход вперёд. Следующим ходом противник будет обязан съесть её, затем мы будем обязаны съесть пешку противника, затем снова он съест, и, наконец, наша пешка съест вражескую пешку и останется, "упёршись" в пешку противника. Таким образом, если мы в самом начале пошли пешкой в колонке 1 < i < n, то в результате три колонки [i-1; i+1] доски фактически уничтожатся, и мы перейдём к сумме игр размера i-2 и n - i - 1. Граничные случаи i=1 и i=n приводят нас просто к доске размера n-2.

Таким образом, мы получили выражения для функции Гранди, аналогичные рассмотренной выше задаче "Крестики-крестики".

"Lasker's nim"
Условие. Имеется n кучек камней заданных размеров. За один ход игрок может взять любое ненулевое число камней из какой-либо кучки, либо же разделить какую-либо кучку на две непустые кучки. Проигрывает тот, кто не может сделать ход.

Решение. Записывая оба вида переходов, легко получить функцию Шпрага-Гранди как:

 g[n] = {\rm mex} \Bigg\{ \bigcup_{i=0}^{n-1} g[i][...]

Однако можно построить таблицу значений для малых n и увидеть простую закономерность:

 \matrix{
n & 0 & 1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 &[...]

Здесь видно, что g[n] = n для чисел, равных 1 или 2 по модулю 4, и g[n] = n \pm 1 для чисел, равных 3 и 0 по модулю 4. Доказать это можно по индукции.

"The game of Kayles"
Условие. Есть n кегель, выставленных в ряд. За один удар игрок может выбить либо одну кеглю, либо две рядом стоящие кегли. Выигрывает тот, который выбил последнюю кеглю.

Решение. И когда игрок выбивает одну кеглю, и когда он выбивает две — игра распадается на сумму двух независимых игр.

Нетрудно получить такое выражение для функции Шпрага-Гранди:

 g[n] = {\rm mex} \Bigg\{ \bigcup_{i=0}^{n-1} \Big[...]

Посчитаем для него таблицу для нескольких первых десятков элементов:

 \matrix{
g[0 \ldots 11]: & 0 & 1 & 2 & 3 & 1 & 4[...]

Можно заметить, что, начиная с некоторого момента, последовательность становится периодичной с периодом 12. В дальнейшем эта периодичность также не нарушится.

Grundy's game
Условие. Есть n кучек камней, размеры которых мы обозначим через a_i. За один ход игрок может взять какую-либо кучку размера как минимум 3 и разделить её на две непустые кучки неравных размеров. Проигрывает тот, кто не может сделать ход (т.е. когда размеры всех оставшихся кучек меньше либо равны двум).

Решение. Если n > 1, то все эти несколько кучек, очевидно, — независимые игры. Следовательно, наша задача — научиться искать функцию Шпрага-Гранди для одной кучки, а ответ для нескольких кучек будет получаться как их XOR-сумма.

Для одной кучки эта функция строится также легко, достаточно просмотреть все возможные переходы:

 g[n] = {\rm mex} \Bigg\{ \bigcup_{i=[1 \ldots n-1[...]

Чем эта игра интересна — тем, что до сих пор для неё не найдено общей закономерности. Несмотря на предположения, что последовательность g[n] должна быть периодичной, она была просчитана вплоть до 2^{35}, и периодов в этой области обнаружено не было.

"Лестничный ним"
Условие. Есть лестница с n ступеньками (занумерованными от 1 до n), на i-ой ступеньке лежит a_i монет. За один ход разрешается переместить некоторое ненулевое число монет с i-ой на i-1-ую ступеньку. Проигрывает тот, кто не может сделать хода.

Решение. Если попытаться свести эту задачу к ниму "в лоб", то получится, что ход у нас — это уменьшение одной кучки на сколько-то, и одновременное увеличение другой кучки на столько же. В итоге мы получаем модификацию нима, решить которую весьма сложно.

Поступим по-другому: рассмотрим только ступеньки с чётными номерами: a_2, a_4, a_6, \ldots. Посмотрим, как будет меняться этот набор чисел при совершении одного хода.

Если ход делается с чётным i, то тогда этот ход означает уменьшение числа a_i. Если же ход делается с нечётным i (i > 1), то это означает увеличение a_{i-1}.

Получается, что наша задача — это обыкновенный ним с увеличениями с размерами кучек a_2, a_4, a_6, \ldots.

Следовательно, функция Гранди от него — это XOR-сумма чисел вида a_{2i}.

"Nimble" и "Nimble-2"
Условие. Есть клетчатая полоска 1 \times n, на которой расположены k монет: i-ая монета находится в a_i-ой клетке. За один ход игрок может взять какую-то монету и подвинуть её влево на произвольное число клеток, но так, чтобы она не вылезла за пределы полоски. В игре "Nimble-2" дополнительно запрещается перепрыгивать другие монеты (или даже ставить две монеты в одну клетку). Проигрывает тот, кто не может сделать ход.

Решение "Nimble". Заметим, что монеты в этой игре независимы друг от друга. Более того, если мы рассмотрим набор чисел a_i-1 (i = 1 \ldots k), то понятно, что за один ход игрок может взять любое из этих чисел и уменьшить его, а проигрыш наступает, когда все числа обращаются в ноль. Следовательно, игра "Nimble" — это обычный ним, и ответом на задачу является XOR-сумма чисел a_i-1.

Решение "Nimble-2". Перенумеруем монеты в порядке их следования слева направо. Тогда обозначим через d_i расстояние от i-ой до i-1-ой монеты:

 d_i = a_i - a_{i-1} - 1, ~~~~ (i = 1 \ldots k) 

(считая, что a_0 = 0).

Тогда за один игрок может отнять от какого-нибудь d_p некоторое число q, и прибавить это же число q к d_{p+1}. Таким образом, эта игра — это фактически "лестничный ним" над числами d_i (надо лишь изменить порядок этих чисел на противоположный).

"Turning turtles" и "Twins"
Условие. Дана клетчатая полоска размера 1 \times n. В каждой клетке стоит либо крестик, либо нолик. За один ход можно взять какой-то нолик и превратить его в крестик.

При этом дополнительно разрешается выбрать одну из клеток слева от изменяемой и изменить в ней значение на противоположное (т.е. нолик заменить на крестик, а крестик — на нолик). В игре "turning turtles" делать это не обязательно (т.е. ход игрока может ограничиваться превращением нолика в крестик), а в "twins" — обязательно.

Решение "turning turtles". Утверждается, что эта игра — это обычный ним над числами b_i, где b_i — позиция i-го нолика (в 1-индексации). Проверим это утверждение.

Если игрок просто поменял нолик на крестик, не воспользовавшись дополнительным ходом — то это можно понимать как то, что он просто забрал всю кучку, соответствующую этому нолику. Иными словами, если игрок поменял нолик на крестик в позиции x (1 \le x \le n), то тем самым он взял кучку размера x и сделал её размер равным нулю.
Если игрок воспользовался дополнительным ходом, т.е. помимо того, что поменял нолик в позиции x на крестик, он ещё изменил клетку в позиции y (y < x), то можно считать, что он уменьшил кучку x до размера y. Действительно, если в позиции y раньше был крестик — то, в самом деле, после хода игрока там станет нолик, т.е. появится кучка размера y. А если в позиции y раньше был нолик, то после хода игрока эта кучка исчезает — или, что то же самое, появилась вторая кучка точно такого же размера y (поскольку в ниме две кучки одинаковых размеров фактически "уничтожают" друг друга).
Таким образом, ответ на задачу — это XOR-сумма чисел — координат все ноликов в 1-индексации.

Решение "twins". Все рассуждения, приведённые выше, остаются верны, за исключением того, что хода "обнулить кучку" теперь у игрока нет. Т.е. если мы от всех координат отнимем единицу — то снова игра превратится в обычный ним.

Таким образом, ответ на задачу — это XOR-сумма чисел — координат все ноликов в 0-индексации.

Northcott's game
Условие. Есть доска размера n \times m: n строк и m столбцов. В каждой строке стоят по две фишки: одна чёрная и одна белая. За один ход игрок может взять любую фишку своего цвета и подвинуть её внутри строки вправо или влево на произвольное число шагов, но не перепрыгивая через другую фишку (и не вставая на неё). Проигрывает тот, кто не может сделать хода.

Решение. Во-первых, понятно, что каждая из n строк доски образует независимую игру. Поэтому задача сводится к анализу игры в одной строке, а ответом на задачу будет XOR-сумма значений Шпрага-Гранди для каждой из строк.

Решая задачу для одной строки, обозначим через x расстояние между чёрной и белой фишкой (которое может меняться от нуля до m-2). За один ход каждый игрок может либо уменьшить x на некоторое произвольное значение, либо, возможно, увеличить его до некоторого значения (увеличения доступны не всегда). Таким образом, эта игра — это "ним с увеличениями", и, как мы уже знаем, увеличения в этой игре бесполезны. Следовательно, функция Гранди для одной строки — это и есть это расстояние x.

(Следует заметить, что формально такое рассуждение неполно — т.к. в "ниме с увеличениями" предполагается, что игра конечна, а здесь правила игры позволяют игрокам играть бесконечно долго. Впрочем, бесконечная игра не может иметь места при оптимальной игре — т.к. стоит одному игроку увеличить расстояние x (ценой приближения к границе поля), как другой игрок приблизится к нему, уменьшив x обратно. Следовательно, при оптимальной игре противника игроку не удастся совершать увеличивающие ходы бесконечно долго, поэтому всё же описанное решение задачи остаётся в силе.)

Триомино
Условие. Дано клетчатое поле размера 2 \times n. За один ход игрок может поставить на поле одну фигурку в форме буквы "Г" (т.е. связную фигуру из трёх клеток, не лежащих на одной прямой). Запрещено ставить фигурку так, чтобы она пересеклась хотя бы одной клеткой с какой-то из уже поставленных фигурок. Проигрывает тот, кто не может сделать ход.

Решение. Заметим, что постановка одной фигурки разбивает всё поле на два независимых поля. Таким образом, нам надо анализировать не только прямоугольные поля, но и поля, у которых левая и/или правая границы неровные.

Нарисовав различные конфигурации, можно понять, что какой бы ни была конфигурация поля, главное — лишь то, сколько на этом поле клеток. На самом деле, если в текущем поле x свободных клеток, и мы хотим разбить это поле на два поля размером y и z (где y+z+3 = x), то это всегда можно сделать, т.е. всегда можно найти соответствующее место для фигурки.

Таким образом, наша задача превращается в такую: изначально у нас есть кучка камней размера 2n, и за один ход мы можем выкинуть из некоторой кучки 3 камня и затем разбить эту кучку на две кучки произвольных размеров. Функция Гранди для такой игры имеет вид:

 g[n] = {\rm mex} \Bigg\{ \bigcup_{i=0}^{n-3} \Big[...]

Фишки на графе
Условие. Дан ориентированный ациклический граф. В некоторых вершинах графа стоят фишки. За один ход игрок может взять какую-то фишку и передвинуть её вдоль какого-либо ребра в новую вершину. Проигрывает тот, кто не может сделать ход.

Также бывает и второй вариант этой задачи: когда считается, что если две фишки приходят в одну вершину, то они обе взаимно уничтожают друг друга.

Решение первого варианта задачи. Во-первых, все фишки — независимы друг от друга, поэтому наша задача — научиться искать функцию Гранди для одной фишки в графе.

Учитывая, что граф ацикличен, мы можем делать это рекурсивно: предположим, что мы посчитали функцию Гранди для всех потомков текущей вершины. Тогда функция Гранди в текущей вершине — это \rm mex от этого множества чисел.

Таким образом, решением задачи является следующее: для каждой вершины рекурсивно посчитать функцию Гранди, если бы фишка стояла именно в этой вершине. После этого ответом на задачу будет XOR-сумма значений Гранди от тех вершин графа, в которых по условию стоят фишки.

Решение второго варианта задачи. На самом деле, второй вариант задачи ничем не отличается от первого. В самом деле, если две фишки стоят в одной и той же вершине графа, то в результирующей XOR-сумме их значения Гранди взаимно уничтожают друг друга. Следовательно, фактически это одна и та же задача.

Реализация
С позиции реализации интерес может представлять реализация функции \rm mex.

Если это не является узким местом в программе, то можно написать какой-нибудь простой вариант за O (c \log c) (где c — количество аргументов):

int mex(vector<int> a) {
	set<int> b(a.begin(), a.end());
	for (int i=0; ; ++i)
		if (!b.count(i))
			return i;
}
Впрочем, не так уж и сложным является вариант за линейное время, т.е. за O (c), где c — число аргументов функции \rm mex. Обозначим через D константу, равную максимально возможному значению c (т.е. максимальной степени вершины в графе игры). В таком случае результат функции \rm mex не будет превосходить D.

Следовательно, при реализации достаточно завести массив размера D+1 (массив глобальный, или статический — главное, чтобы он не создавался при каждом вызове функции). При вызове функции \rm mex мы сначала отметим в этом массиве все c аргументов (пропустив те из них, которые больше D — такие значения, очевидно, не влияют на результат). Затем проходом по этому массиву мы за O (c) найдём первый неотмеченный элемент. Наконец, в конце можно снова пройтись по всем переданным аргументам и обнулить обратно массив для них. Тем самым, мы выполним все действия за O (c), что на практике может оказаться существенно меньше максимальной степени D.

int mex (const vector<int> & a) {
	static bool used[D+1] = { 0 };
	int c = (int) a.size();
 
	for (int i=0; i<c; ++i)
		if (a[i] <= D)
			used[a[i]] = true;
 
	int result;
	for (int i=0; ; ++i)
		if (!used[i]) {
			result = i;
			 2 break;
		}
 
	for (int  1 i=0; i<c; ++i)
		if (a[i] <= D)
			used[a[i]] = false;
 
	return result;
}
Другой вариант — воспользоваться техникой "числового used". Т.е. сделать \rm used массивом не булевских переменных, а чисел ("версий"), и завести глобальную переменную, обозначающую номер текущей версии. При входе в функцию \rm mex мы увеличиваем номер текущей версии, в первом цикле мы проставляем в массиве \rm used не \rm true, а номер текущей версии. Наконец, во втором цикле мы просто сравниваем {\rm used}[i] с номером текущей версии — если они не совпали, то это означает, что текущее число не встречалось в массиве a. Третий цикл (который ранее занулял массив \rm used) в таком решении не нужен.



## Задача

Есть лестница с $n$ ступеньками (занумерованными от 1 до $n$), на $i$-ой
ступеньке лежит $a_i$ монет. За один ход разрешается переместить
некоторое ненулевое число монет с $i$-ой на $i-1$-ую ступеньку.
Проигрывает тот, кто не может сделать хода.

## Решение

Возьмем ним только с четными номерами ступенек($a_{2}, a_{4},
\\dots$).

Есть два варианта хода :

Мы можем положить со ступеньки $i$ с четным номером на ступеньку $i - 1$
с нечетным номером $x$ камней, но такое действие эквивалентно действию в
ниме(забрать из $i$-ой кучки $x$ камней).

Мы можем положить со ступеньки $i$ с нечетным номером на ступеньку $i -
1$ с четным номером $x$ камней, но такое действие эквивалентно действию
в ниме с прибавлением (прибавить к $i$-ой кучке $x$ камней), а
следовательно мы можем в победной стратегии на него ответить,
тем что заберем с $i - 1$ ступеньки $x$ камней, так как сумма
количества камней конечна, то и количество действий конечно, а
следовательно игра ациклична.

---

## Задача

Дан ним($n$ кучек размера $a_{1} \\dots a_{n}$, ход - взятие камней из
кучки), выигрывает игрок, который не может сделать ход.

## Подсказка

Пусть вам дана выигрышная стратегия в ним, можете ли вы ее как-нибудь
применить к ниму в поддавки.

## Решение

Отдельно рассмотрим случай, где все кучки - размера 1, в таком ниме
ответ обратен ниму в поддавки, так как единственный возможный ход -
взять всю кучку и кто выигрывает зависит только от четности количества
кучек.

Заметим, что в ниме в поддавки игра заканчивается на том, что остается
кучка размера 1, заметим, что существует оптимальная стратегия Нима,
где в конце мы получили сколько-то кучек размера 1, тогда вернемся к
последнему ходу, который привел нас к тому, что остались только кучки
размера 1(так как мы рассмотрели отдельно случай, когда все кучки из
одного камушка, то такой ход был). Сделаем теперь ход не до кучки
размера 1, а до кучки размера 0, так как мы поменяли четность
количества кучек размера 1, то мы и поменяли игрока, который
выигрывает, а следовательно мы научились выигрывать в ниме с
поддавками, если мы умеем выигрывать в обычном ниме.

---

## Условие

Есть клетчатая полоска $1 \\times n$, на которой расположены $k$ монет:
$i$-ая монета находится в $a_i$-ой клетке. За один ход игрок может
взять какую-то монету и подвинуть её влево на произвольное число
клеток, но так, чтобы она не вылезла за пределы полоски, запрещается
перепрыгивать другие монеты (или даже ставить две монеты в одну
клетку). Проигрывает тот, кто не может сделать ход.

## Решение

Первым делом добавим фиктивную монетку, стоящую в самой крайней точке.

Можно заметить, что эта игра эквивалента [Лесенка](Лесенка "wikilink"),
а именно давайте посчитаем расстояние между соседними монетками, будем
считать, что расстояние от $i$-ой до $i+1$-й монетки в текущей задачи -
количество монет на $i + 1$-ой ступеньке в оригинальной задаче.

Тогда задача сводится к переместить все монетки на первую ступеньку.
