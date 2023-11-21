import os
import time

from data import *


def log(path: str, wait: float):
    print("> 🗑 {}".format(path))
    time.sleep(wait)


def check(path: str) -> bool:
    return os.stat(path).st_size == 0


time.sleep(0.2)
if check(cin):
    print("> {} is clear ✨".format(cin[5:]))
else:
    with open(cin, "wb"):
        log(cin, 0.5)
        pass

time.sleep(0.4)
if check(cout):
    print("> {} is clear ✨".format(cout[5:]))
else:
    with open(cout, "wb"):
        log(cout, 0.5)
        pass
print()
time.sleep(0.2)

with open("TEST/tests.txt", "w") as t:
    t.write("0")


def clear_tests(folder: str):
    for filename in os.listdir(folder):
        file_path = os.path.join(folder, filename)
        try:
            if os.path.isfile(file_path):
                os.remove(file_path)
                print("> Removing {}...".format(filename))
                time.sleep(0.1)
        except Exception as e:
            print(f"> Can't remove {file_path}. {e}")


clear_tests(in_path)
clear_tests(out_path)

time.sleep(0.2)
print()
print("> Everything is clear! ✨")
