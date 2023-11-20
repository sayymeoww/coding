import os
import time

from data import *


def log(path: str, wait: float):
    print("🗑 {}".format(path))
    time.sleep(wait)


def check(path: str) -> bool:
    return os.stat(path).st_size == 0


if check(cin):
    print("{} is clear ✨".format(cin[5:]))
else:
    with open(cin, "wb"):
        log(cin, 0.5)
        pass

if check(cout):
    print("{} is clear ✨".format(cout[5:]))
else:
    with open(cout, "wb"):
        log(cout, 0.5)
        pass
print()

for file in inputs:
    if check(file):
        print("{} is clear ✨".format(file[15:]))
    else:
        with open(file, "wb"):
            log(file, 0.2)
            pass
print()

for file in outputs:
    if check(file):
        print("{} is clear ✨".format(file[16:]))
    else:
        with open(file, "wb"):
            log(file, 0.2)
            pass
print()
