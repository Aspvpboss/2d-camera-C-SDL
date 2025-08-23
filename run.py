import subprocess
import os

subprocess.run("gcc -Wall -Werror -Wpedantic -o bin/SDL_2d_camera src/*.c -Iinclude -lSDL3 -lSDL3_image -I C:\\msys64\\ucrt64\\include -L C:\\msys64\\ucrt64\\lib", shell = True)
bin_dir = os.path.join(os.getcwd(), "bin")
exe_path = os.path.join(bin_dir, "SDL_2d_camera.exe")  # or just "out" if using MSYS2 bash

subprocess.run(exe_path, cwd=bin_dir, shell=True)