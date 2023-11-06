class node:
    def __init__(self, row: int, column: int):
        self.parentLeft: node = None
        self.parentRight: node = None
        self.childLeft: node = None
        self.childRight: node = None

        self.row: int = row
        self.column: int = column

    def __eq__(self, other) -> bool:
        if other == None:
            return False
        return (self.row == other.row) and (self.column == other.column)

    def connect(self, other, type: int):
        if type == 0:
            self.childLeft = other
            self.childLeft.parentRight = self
        if type == 1:
            self.childRight = other
            self.childRight.parentLeft = self

    def view(self) -> (int, int):
        return (self.row, self.column)


def lowest(a: node, b: node) -> node:
    if a.row > b.row:
        return a
    return b


def highest(a: node, b: node) -> node:
    if a.row < b.row:
        return a
    return b


def left(a: node, b: node) -> node:
    if a.column < b.column:
        return a
    return b


def right(a: node, b: node) -> node:
    if a.column > b.column:
        return a
    return b


class tree:
    root: node = node(0, 0)
    path: set = set()
    height: int = 0

    visited: set = set()
    links: dict = {(0, 0): root}

    def build(self, current: node):
        if self.height == 0:
            return
        if self.height == 1:
            current.connect(node(1, 0), 0)
            current.connect(node(1, 1), 1)

            self.links[(1, 0)] = self.links[(0, 0)].childLeft
            self.links[(1, 1)] = self.links[(0, 0)].childRight

            return
        if (
            (current.row, current.column),
            (current.row + 1, current.column),
        ) in self.path:
            current.connect(node(current.row + 1, current.column), 0)

            self.links[(current.childLeft.row, current.childLeft.column)] = self.links[
                (current.row, current.column)
            ].childLeft

            self.build(current.childLeft)
        if (
            (current.row, current.column),
            (current.row + 1, current.column + 1),
        ) in self.path:
            current.connect(node(current.row + 1, current.column + 1), 1)

            self.links[
                (current.childRight.row, current.childRight.column)
            ] = self.links[(current.row, current.column)].childRight

            self.build(current.childRight)

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

    def find(self, target: node):
        return self.links[(target.row, target.column)]

    def moveUp(self, first: node, second: node) -> (int, int):
        if first == second:
            return (first.row, first.column)

        condition1: bool = (
            first.parentLeft != None and first.parentRight != None
        ) and (second.parentLeft != None and second.parentRight != None)

        condition2: bool = (
            first.parentLeft != None and first.parentRight != None
        ) and (second.parentLeft == None and second.parentRight != None)

        condition3: bool = (
            first.parentLeft != None and first.parentRight != None
        ) and (second.parentLeft != None and second.parentRight == None)

        condition4: bool = (
            first.parentLeft == None and first.parentRight != None
        ) and (second.parentLeft != None and second.parentRight != None)

        condition5: bool = (
            first.parentLeft != None and first.parentRight == None
        ) and (second.parentLeft != None and second.parentRight != None)

        condition6: bool = first.parentLeft == None
        condition7: bool = first.parentRight == None
        condition8: bool = second.parentLeft == None
        condition9: bool = second.parentRight == None

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

    def lca(self, first: node, second: node) -> (int, int):
        first = self.find(first)
        self.visited = set()

        second = self.find(second)
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

    return answer


n = int(input())

t: tree = tree()
t.height = n

t.path = generate(n, list(map(int, input().split())))
t.build(t.root)

q = int(input())
for _ in range(q):
    a, b, c, d = map(int, input().split())
    x, y = t.lca(node(a, b), node(c, d))
    print(x, y)
