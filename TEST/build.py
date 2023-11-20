# trunk-ignore-all(isort)
import os
import subprocess
import time
from itertools import zip_longest

from data import *
import colorize as color

ok = 0
skipped = 0
error = 0


# _in - ввод для текущего теста
# _out - вывод текущего теста
def run(_in: str, _out: str, test: int):
    global cin, cout, make, command
    global ok, skipped, error

    # если теста нет - то скипаем
    if os.stat(_in).st_size == 0 or os.stat(_out).st_size == 0:
        time.sleep(0.1)
        print(
            "\033[37m│ "
            + "\033[34m↺"
            + "\033[37m (Test {}) · ———————— skipped ————————   ".format(test)
        )
        skipped += 1
        time.sleep(0.1)
        return

    time.sleep(0.5)
    # копируем данные из теста в ввод для программы
    with open(_in, "r") as _input, open(cin, "w") as _cin:
        for line in _input:
            _cin.write(line)

        # запускаем программу

    try:
        subprocess.run(make, stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)
        subprocess.run(command, timeout=1.1 * progtime)
    except subprocess.TimeoutExpired:
        error += 1
        print("╰ \033[31m✘ (Test {}) · ———————— failed! ————————   ".format(test))
        print()
        print(
            " ? ░" + " " + "\033[3mInfinity loop / TL exception  >{} s".format(progtime)
        )
        print()
        with open(cout, "r") as _cout, open(_out, "r") as _output:
            _o, _c = [], []  # вывод программы и ожидаемый вывод
            for line in _output:
                _o.append(line.rstrip())
            for line in _cout:
                _c.append(line.rstrip())
            if len(_c) == 0:
                print(tab[:3] + color.red(tab[3]) + " (output.txt) Given")
                print(tab[:3] + color.red(tab[3]))
                print(tab[:3] + color.red(tab[3]) + " 🦗 cricket sounds..")
                print(tab[:3] + color.red(tab[3]))
                print(
                    tab[:3] + color.red(tab[3]) + " (out {}.txt)  Expected".format(test)
                )
                print(tab[:3] + color.red(tab[3]))
                for line in _o:
                    print(tab[:3] + color.red(tab[3]), line)
                print(tab[:3] + color.red(tab[3]))
                # print("    ———————————————————————————————————")
                print()
                time.sleep(0.5)
                return
            if _o != _c:
                print(
                    "\033[37m"
                    + tab[:3]
                    + color.red(tab[3])
                    + "\033[37m (output.txt) Given",
                )
                print(tab[:3] + color.red(tab[3]))
                for line in _c:
                    print("\033[37m" + tab[:3] + color.red(tab[3]), line)
                print("\033[37m" + tab[:3] + color.red(tab[3]))
                print(
                    "\033[37m"
                    + tab[:3]
                    + color.red(tab[3])
                    + "\033[37m (out {}.txt)  Expected".format(test)
                )
                print("\033[37m" + tab[:3] + color.red(tab[3]))
                for line in _o:
                    print("\033[37m" + tab[:3] + color.red(tab[3]), line)
                print("\033[37m" + tab[:3] + color.red(tab[3]))
                # print("    ———————————————————————————————————")
                print()
                time.sleep(0.5)
                return

    with open(cout, "r") as _cout, open(_out, "r") as _output:
        _o, _c = [], []  # вывод программы и ожидаемый вывод
        for line in _output:
            _o.append(line.rstrip())
        for line in _cout:
            _c.append(line.rstrip())
        if _o != _c:
            error += 1
            print(
                "╰ "
                + "\033[31m✘"
                + "\033[37m (Test {}) · ———————— failed! ————————   ".format(test)
            )
            print()
            # print("    ———————————————————————————————————")
            print(
                "\033[37m" + tab[:3] + color.red(tab[3]) + "\033[37m (output.txt) Given"
            )
            print("\033[37m" + tab[:3] + color.red(tab[3]))
            for line in _c:
                print("\033[37m" + tab[:3] + color.red(tab[3]), line)
            print("\033[37m" + tab[:3] + color.red(tab[3]))
            print(
                "\033[37m"
                + tab[:3]
                + color.red(tab[3])
                + "\033[37m (out {}.txt)  Expected".format(test)
            )
            print("\033[37m" + tab[:3] + color.red(tab[3]))
            for line in _o:
                print("\033[37m" + tab[:3] + color.red(tab[3]), line)
            print("\033[37m" + tab[:3] + color.red(tab[3]))
            # print("    ———————————————————————————————————")
            print()
            time.sleep(0.5)
            return

    print(
        "╰ "
        + "\033[32m✔"
        + "\033[37m (Test {}) · ———————— passed! ————————   ".format(test)
    )
    print()
    ok += 1
    time.sleep(0.5)


# запуск всех тестов
def build():
    global ok, skipped, error
    print()
    print("\033[37m  ⏳ Testing started...")
    time.sleep(0.2)
    print()
    for i in range(4):
        # temp = error
        run(inputs[i], outputs[i], i + 1)
        # if error > temp:
        #    break
    print()
    print("\033[37m  🎉 Testing completed!       ", end="")
    print(
        "\033[32m✔"
        + "\033[37m{}  ".format(ok)
        + "\033[34m↺"
        + "\033[37m{}  ".format(skipped)
        + "\033[31m✘"
        + "\033[37m{}  ".format(error)
    )
