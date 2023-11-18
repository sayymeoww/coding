import os
import subprocess
import time
from itertools import zip_longest

from data import *

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
        print("🌀 (Test {}) · ———————— skipped ————————   ".format(test))
        skipped += 1
        time.sleep(0.1)
        return

    time.sleep(0.5)
    # копируем данные из теста в ввод для программы
    with open(_in, "r") as _input, open(cin, "w") as _cin:
        for line in _input:
            _cin.write(line)

    # запускаем программу
    subprocess.run(make, stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT)
    subprocess.run(command)

    with open(cout, "r") as _cout, open(_out, "r") as _output:
        _o, _c = [], []  # вывод программы и ожидаемый вывод
        for line in _output:
            _o.append(line.rstrip())
        for line in _cout:
            _c.append(line.rstrip())
        if _o != _c:
            error += 1
            print("📛 (Test {}) · ———————— failed  ————————   ".format(test))
            print("    ———————————————————————————————————")
            print("   | (output.txt) Expected")
            print("   |")
            tab = "   |"
            for line in _c:
                print(tab, line)
            print("   |")
            print("   | (out {}.txt)  Given".format(test))
            print("   |")
            for line in _o:
                print(tab, line)
            print("   |")
            print("    ———————————————————————————————————")
            time.sleep(0.5)
            return

    print("✅ (Test {}) · ———————— passed! ————————   ".format(test))
    ok += 1
    time.sleep(0.5)


# запуск всех тестов
def build():
    global ok, skipped, error
    print()
    for i in range(4):
        temp = error
        run(inputs[i], outputs[i], i + 1)
        if error > temp:
            break
    print()
    print("🎉 Testing completed!     ✅{}, 🌀{}, 📛{}".format(ok, skipped, error))
