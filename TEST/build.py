import os
import subprocess
import time
from itertools import zip_longest

import colorize as color
from data import *

o: int = 0
s: int = 0
e: int = 0

inputs: list = []
outputs: list = []


def generate_test_files(tests):
    for _in in inputs:
        f = open(_in, "w+")
        f.close()

    for _out in outputs:
        f = open(_out, "w+")
        f.close()


# проверка пустой ли файл
def check_empty(path: str) -> bool:
    return os.stat(path).st_size == 0


# функция ожидания
def wait(t: float):
    time.sleep(t)


# вывод пропущенного теста
def print_skip(test: int):
    if test == 1:
        print(
            "\033[37m╭ "
            + "\033[34m↺"
            + "\033[37m (Test {})    ———————— skipped ———————— ╮  ".format(test)
        )
    elif test == tests:
        print(
            "\033[37m╰ "
            + "\033[34m↺"
            + "\033[37m (Test {})    ———————— skipped ———————— ╯  ".format(test)
        )
    else:
        print(
            "\033[37m│ "
            + "\033[34m↺"
            + "\033[37m (Test {})    ———————— skipped ———————— │  ".format(test)
        )


# запуск программы
def build_main():
    global make, command, progtime
    subprocess.run(make, stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)
    subprocess.run(command, timeout=1.1 * progtime)


# запись в файл
def write_file(_from: str, _to: str):
    with open(_from, "r") as f, open(_to, "w") as t:
        for line in f:
            t.write(line)


# запись трех файлов в три массива
def show_3files(out: str, output: str, input: str) -> (list, list, list):
    _out, _output, _input = [], [], []
    with open(out, "r") as _c, open(output, "r") as _o, open(input, "r") as _i:
        for line in _c:
            _out.append(line.rstrip())
        for line in _o:
            _output.append(line.rstrip())
        for line in _i:
            _input.append(line.rstrip())
    return _out, _output, _input


# отработка ошибки бесконечного цикла / превышения времени
def loop_error(test: int, progtime: int):
    print("\033[37m╭ · · · · ·  ╮╭                           ╮".format(progtime))
    print(
        "╰ \033[31m✘"
        + "\033[37m (Test {}) ╯╰ ———————— failed! ———————— ╯  ".format(test)
    )

    wait(0.1)

    print()
    print(" ? ░" + " " + "\033[37m\033[3mInfinity loop / TL exception".format(progtime))
    print()


# вывод входных данных
def print_input(test: int, _input: list):
    global tab
    print(
        "\033[37m" + tab[:3] + color.red(tab[3]) + "\033[37m (in {}.txt)".format(test),
    )
    print(tab[:3] + color.red(tab[3]))
    for line in _input:
        print("\033[37m" + tab[:3] + color.red(tab[3]), line)
    print()


# вывод выходных данных
def print_output(test: int, _output: list):
    print(
        "\033[37m" + tab[:3] + color.red(tab[3]) + "\033[37m (output.txt) Given",
    )
    print(tab[:3] + color.red(tab[3]))
    for line in _output:
        print("\033[37m" + tab[:3] + color.red(tab[3]), line)
    print()


# вывод выходных данных в случае если файл пустой
def print_output_cricket():
    global tab
    print(tab[:3] + color.red(tab[3]) + " (output.txt) Given")
    print(tab[:3] + color.red(tab[3]))
    print(tab[:3] + color.red(tab[3]) + " 🦗 cricket sounds..")
    # print(tab[:3] + color.red(tab[3]))
    print()


# вывод "вывода" теста
def print_test(test: int, _output: list):
    global tab
    print(tab[:3] + color.red(tab[3]) + " (out {}.txt)  Expected".format(test))
    print(tab[:3] + color.red(tab[3]))
    for line in _output:
        print(tab[:3] + color.red(tab[3]), line)
    print()


# тест пройден
def passed(test: int):
    print(
        "╰ "
        + "\033[32m✔"
        + "\033[37m (Test {}) ╯╰ ———————— passed! ———————— ╯  ".format(test)
    )
    print()


# тест не пройден
def failed(test: int):
    print(
        "╰ \033[31m✘"
        + "\033[37m (Test {}) ╯╰ ———————— failed! ———————— ╯  ".format(test)
    )
    print()


# запуск теста
def run(_in: str, _out: str, test: int):
    global cin, cout, make, command, progtime, tab
    global o, s, e
    global fs

    if check_empty(_in) or check_empty(_out):
        wait(0.1)

        print_skip(test)

        s += 1
        wait(0.1)

        return

    wait(0.5)
    write_file(_in, cin)

    flag: bool = False
    try:
        build_main()
    except subprocess.TimeoutExpired:
        flag = True
        e += 1

        loop_error(test, progtime)

        _c: list = []
        _o: list = []
        _i: list = []
        _c, _o, _i = show_3files(cout, _out, _in)

        if len(_c) == 0:
            failed(test)
            print_input(test, _i)
            print_output_cricket()
            print_test(test, _o)
            wait(0.5)
            return
        if _o != _c:
            failed(test)
            print_input(test, _i)
            print_output(test, _c)
            print_test(test, _o)
            wait(0.5)

    if flag:
        return

    _c: list = []
    _o: list = []
    _i: list = []
    _c, _o, _i = show_3files(cout, _out, _in)

    if _o != _c:
        e += 1

        failed(test)
        print_input(test, _i)
        print_output(test, _c)
        print_test(test, _o)
        wait(0.5)

        return

    passed(test)
    o += 1
    wait(0.5)


# основная программа
def build():
    global o, s, e
    global inputs, outputs
    global tests

    print()

    command = "n"
    try:
        command = str(input("\033[37m> Setup tests? (y/n): "))
    except:
        pass

    if command == "y":
        try:
            n = int(input("\033[37m> Tests (default 4): "))
            tests = n
        except:
            pass

        with open("TEST/tests.txt", "w") as t:
            t.write(str(tests))

        generate_test_files(tests)
        wait(1)

        print()
        print("\033[37m>" + "\033[32m  ✔ " + "\033[37mTests are ready!")
    else:
        tests = setup()

        for i in range(1, tests + 1):
            inputs.append(input_template.format(i))

        for i in range(1, tests + 1):
            outputs.append(output_template.format(i))

        print()
        print("\033[37m  ⏱︎ Testing started...")
        wait(0.2)
        print()

        if tests == 0:
            print("\033[37m    No tests found :( ")
        else:
            for test in range(tests):
                try:
                    run(inputs[test], outputs[test], test + 1)
                except:
                    print_skip(test + 1)
                    s += 1

            print()
            print("\033[32m  ✔ " + "\033[37mTesting completed!       ", end="")
            print(
                "\033[32m  ✔"
                + "\033[37m{}  ".format(o)
                + "\033[34m↺"
                + "\033[37m{}  ".format(s)
                + "\033[31m✘"
                + "\033[37m{}".format(e)
            )
