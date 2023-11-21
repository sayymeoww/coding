import subprocess

subprocess.run(
    "g++ -o gen generator.cpp -g -v -std=c++20",
    stdout=subprocess.DEVNULL,
    stderr=subprocess.STDOUT,
    shell=True,
)
subprocess.run("./gen", shell=True)
