import shutil

source = "OPT/templates/simple.cpp"
destination = "main.cpp"

shutil.copy2(source, destination)
