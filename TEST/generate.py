import subprocess

subprocess.run(
    "g++ -o gen generator.cpp -g -v -stdc++=20",
    shell=True,
    stdout=subprocess.DEVNULL,
    stderr=subprocess.STDOUT,
)
