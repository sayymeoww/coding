import os
import shutil
import time

source_main = "OPT/templates/simple.cpp"
dest_main = "main.cpp"

source_gen = "OPT/templates/generator.cpp"
dest_gen = "generator.cpp"

with open(source_main, "r") as _source, open(dest_main, "r") as _dest:
    _s, _d = [], []
    for line in _source:
        _s.append(line.rstrip())
    for line in _dest:
        _d.append(line.rstrip())
    if _s == _d:
        print("✔ main is ready to go")
        time.sleep(0.2)
    else:
        shutil.copy2(source_main, dest_main)
        print("✔ " + source_main + " > " + dest_main)
        time.sleep(0.1)

with open(source_gen, "r") as _source, open(dest_gen, "r") as _dest:
    _s, _d = [], []
    for line in _source:
        _s.append(line.rstrip())
    for line in _dest:
        _d.append(line.rstrip())
    if _s == _d:
        print("✔ gen is ready to go")
        time.sleep(0.2)
    else:
        shutil.copy2(source_gen, dest_gen)
        print("✔ " + source_gen + " > " + dest_gen)
        time.sleep(0.1)
