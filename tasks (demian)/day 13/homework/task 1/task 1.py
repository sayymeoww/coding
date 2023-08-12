""" Структура вершины """


class node:
    def __init__(self, row: int, column: int):
        # Связи
        self.parentLeft: node = None
        self.parentRight: node = None
        self.childLeft: node = None
        self.childRight: nide = None

        # Координаты
        self.row = row
        self.column = column

    # Реализуем оператор сравнения двух вершин
    def __eq__(self, other):
        if other == None:
            return False
        return self.row == other.row and self.column == other.column

    # Присоединение
    def connect(self, other, type: int):
        if type == 0:  # лево
            self.childLeft = other
            self.childLeft.parentRight = self
        if type == 1:  # право
            self.childRight = other
            self.childRight.parentLeft = self

    # Удаление
    def delete(self, type: int):
        if type == 0:  # лево
            self.childLeft.parentRight = None
            self.childLeft = None
        if type == 1:  # право
            self.childRight.parentLeft = None
            self.childRight = None

    # Вывод координаты вершины
    def view(self) -> (int, int):
        return (self.row, self.column)


""" Блок вспомогательных функций """


# Нижняя вершина из двух
def lowest(a: node, b: node) -> node:
    if a.row > b.row:
        return a
    return b


# Верхняя вершина из двух
def highest(a: node, b: node) -> node:
    if a.row < b.row:
        return a
    return b


# Вершина левее
def left(a: node, b: node) -> node:
    if a.column < b.column:
        return a
    return b


# Вершина правее
def right(a: node, b: node) -> node:
    if a.column > b.column:
        return a
    return b


""" Структура дерева """


class tree:
    # Корневая вершина
    root: node = node(0, 0)
    path: set = set()
    visited: set = set()

    # Спуск в самую нижнюю левую вершину
    def downToLeft(self, current: node) -> node:
        if current.childLeft == None and current.childRight == None:
            return current
        return self.downToLeft(current.childLeft)

    # Перепрыгивание на соседнюю правую вершину
    def jumpToRight(self, current: node) -> node:
        if current.row == current.column:
            return current
        return current.parentRight.childRight

    # Заполнение слоя дерево двигаясь направо
    def moveToRight(self, current: node):
        if current.childLeft != None:
            return

        if current.column == 0:
            current.connect(node(current.row + 1, current.column), 0)
            current.connect(node(current.row + 1, current.column + 1), 1)
        else:
            current.connect(current.parentLeft.childLeft.childRight, 0)
            current.connect(node(current.row + 1, current.column + 1), 1)

        self.moveToRight(self.jumpToRight(current))

    # Функция построения дерева
    def build(self, height: int):
        if height == 0:
            return
        if height == 1:  # у корня есть два ребенка
            # Обрабатываем связи
            self.root.connect(node(1, 0), 0)
            self.root.connect(node(1, 1), 1)
        else:
            self.build(1)
            height -= 1
            while height > 0:
                self.moveToRight(self.downToLeft(self.root))
                height -= 1
        return

    # Вывод дерева
    def view(self, now: node = root):
        if now == None:
            return
        if now.childLeft == None and now.childRight == None:
            print("leaf: ", now.row, now.column)
            return

        self.view(now.childLeft)
        print()
        if now.childLeft == None:
            print("vertex: ", now.row, now.column)
            print("right: ", now.childRight.view())
        elif now.childRight == None:
            print("left: ", now.childLeft.view())
            print("vertex: ", now.row, now.column)
        else:
            print("left: ", now.childLeft.view())
            print("vertex: ", now.row, now.column)
            print("right: ", now.childRight.view())
        print()
        self.view(now.childRight)
        print()

    # Подъем на вершину вверх
    def up(self, current: node) -> node:
        if current.parentLeft != None:
            return current.parentLeft
        return current.parentRight

    # Поиск вершины
    def find(self, target: node, current: node) -> node:
        if target.row == target.column:
            while target != current:
                current = current.childRight
            return current
        if target == current:
            return current

        left: node = current.childLeft
        right: node = current.childRight

        if (current.row, current.column) in self.visited:
            if left == None and right == None:
                return self.find(target, self.up(current))
            elif left == None:
                if (right.row, right.column) in visited:
                    return self.find(target, self.up(current))
                else:
                    return self.find(target, current.childRight)
            elif right == None:
                if (left.row, left.column) in self.visited:
                    return self.find(target, self.up(current))
                else:
                    return self.find(target, current.childLeft)
            else:
                if (left.row, left.column) in self.visited and (
                    right.row,
                    right.column,
                ) in self.visited:
                    return self.find(target, self.up(current))
                elif (left.row, left.column) in self.visited:
                    return self.find(target, current.childRight)
                return self.find(target, current.childLeft)
        else:
            self.visited.add((current.row, current.column))

            if current == self.root:
                if (left.row, left.column) in self.visited:
                    return self.find(target, current.childRight)
                else:
                    return self.find(target, current.childLeft)
            else:
                if left == None and right == None:
                    return self.find(target, self.up(current))
                while (
                    current.childLeft.row,
                    current.childLeft.column,
                ) in self.visited and (
                    current.childRight.row,
                    current.childRight.column,
                ) in self.visited:
                    current = self.up(current)

                if left != None:
                    return self.find(target, current.childLeft)
                else:
                    return self.find(target, current.childRight)

    # Двигаем две вершины вверх если те находятся на одном уровне
    def moveUp(self, first: node, second: node) -> (int, int):
        if first == second:
            return (first.row, first.column)

        # первый куда угодно, второй куда угодно
        condition1: bool = (
            first.parentLeft != None and first.parentRight != None
        ) and (second.parentLeft != None and second.parentRight != None)

        # первый куда угодно, второй направо
        condition2: bool = (
            first.parentLeft != None and first.parentRight != None
        ) and (second.parentLeft == None and second.parentRight != None)

        # первый куда угодно, второй налево
        condition3: bool = (
            first.parentLeft != None and first.parentRight != None
        ) and (second.parentLeft != None and second.parentRight == None)

        # первый направо, второй куда угодно
        condition4: bool = (
            first.parentLeft == None and first.parentRight != None
        ) and (second.parentLeft != None and second.parentRight != None)

        # первый налево, второй куда угодно
        condition5: bool = (
            first.parentLeft != None and first.parentRight == None
        ) and (second.parentLeft != None and second.parentRight != None)

        condition6: bool = first.parentLeft == None  # первый только направо
        condition7: bool = first.parentRight == None  # первый только налево
        condition8: bool = second.parentLeft == None  # второй только направо
        condition9: bool = second.parentRight == None  # второй только налево

        if condition1 or condition3:
            return self.moveUp(first.parentRight, second.parentLeft)
        if condition2:
            return self.moveUp(first.parentRight, second.parentRight)
        if condition4:
            return self.moveUp(first.parentRight, second.parentLeft)
        if condition5:
            return self.moveUp(first.parentLeft, second.parentLeft)

        if condition6 and condition8:
            return self.moveUp(first.parentRight, second.parentRight)
        if condition6 and condition9:
            return self.moveUp(first.parentRight, second.parentLeft)
        if condition7 and condition8:
            return self.moveUp(first.parentLeft, second.parentRight)
        if condition7 and condition9:
            return self.moveUp(first.parentLeft, second.parentLeft)

    # Поиск наименьшего общего предка
    def lca(self, first: node, second: node) -> (int, int):
        first = self.find(first, self.root)
        self.visited = set()

        second = self.find(second, self.root)
        self.visited = set()

        if first == second:
            return (first.row, first.column)

        if first.row < second.row:
            return self.lca(lowest(first, second), highest(first, second))

        if first.row == second.row:
            return self.moveUp(left(first, second), right(first, second))

        if first.parentRight == None:
            return self.lca(first.parentLeft, second)
        return self.lca(first.parentRight, second)

    # Удаление ребра
    def remove(self, first: node, second: node):
        if second.row < first.row:
            remove(second, first)
        else:
            first = self.find(first, self.root)
            self.visited.clear()

            second = self.find(second, self.root)
            self.visited.clear()

            if first.column == second.column:
                first.delete(0)
            else:
                first.delete(1)

    # Удаление ненужных ребер
    def removeEdges(self, current: node, visited: set):
        if (
            (current.row, current.column),
            (current.row + 1, current.column),
        ) in visited and (
            (current.row, current.column),
            (current.row + 1, current.column + 1),
        ) in visited:
            self.removeEdges(current.childLeft, visited)
            self.removeEdges(current.childRight, visited)
        else:
            if (
                (current.row, current.column),
                (current.row + 1, current.column),
            ) in visited:
                self.remove(
                    node(current.row, current.column),
                    node(current.row + 1, current.column + 1),
                )
                self.removeEdges(current.childLeft, visited)
            elif (
                (current.row, current.column),
                (current.row + 1, current.column + 1),
            ) in visited:
                self.remove(
                    node(current.row, current.column),
                    node(current.row + 1, current.column),
                )
                self.removeEdges(current.childRight, visited)
            else:
                return


# Генерация всех ребер
def generate(n: int, changes: list) -> set:
    path = [1] * n
    answer = set()

    for i in range(n):
        answer.add(((i, i), (i + 1, i + 1)))

    for i in range(n):
        x, y = 0, 0
        path[changes[i] - 1] = 0
        for rot in path:
            if rot == 1:
                answer.add(((x, y), (x + 1, y + 1)))
                y += 1
            else:
                answer.add(((x, y), (x + 1, y)))
            x += 1

    return sorted(answer)


Tree: tree = tree()
n = int(input())

Tree.build(n)

Tree.path = generate(n, list(map(int, input().split())))
Tree.removeEdges(Tree.root, Tree.path)
# Tree.view()

q = int(input())
for _ in range(q):
    a, b, c, d = map(int, input().split())
    print(Tree.lca(node(a, b), node(c, d)))
