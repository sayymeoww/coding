cin = "file/input.txt"  # ввод
cout = "file/output.txt"  # вывод

make = "make"  # команда для компиляции
command = "./main"  # команда для запуска

input_template = "TEST/tester/in/in {}.txt"
output_template = "TEST/tester/out/out {}.txt"

in_path = "TEST/tester/in"
out_path = "TEST/tester/out"

progtime = 1  # ограничение времени исполнения
tab = "   ░"

tests = 0  # количество тестов


def setup() -> int:
    k = 0
    with open("TEST/tests.txt") as f:
        for line in f:
            k = int(line.rstrip())
    return k
