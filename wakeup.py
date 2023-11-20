import subprocess

subprocess.run('alias run="python3 TEST/test.py"', shell=True)
subprocess.run('alias end="python3 TEST/clear.py"', shell=True)
subprocess.run('alias setup="python3 SETUP/setup.py"', shell=True)
subprocess.run('alias generate="python3 TEST/generate.py"', shell=True)
