import subprocess
subprocess.run("gcc -Wall -Werror -Wpedantic -o out src/*.c -Iinclude -lSDL3 -I C:\\msys64\\ucrt64\\include -L C:\\msys64\\ucrt64\\lib && out", shell = True)
