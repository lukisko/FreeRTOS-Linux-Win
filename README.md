# FreeRTOS-Template
A minimalistic FreeRTOS project only for Windows and Linux

This project is inspired by [supervisor's repository](https://github.com/ihavn/MSVC-FreeRTOS-Template-202012.00). This repository needed to be changed so people can run the same code on linux and also windows

## Manual:

1. clone git repository to place where you want it.

### To run on linux

2. go to the folder that you just colned from git
3. make sure that in folder _FreeRTOS/Source/include_ there is no file named _FreeRTOSConfig.h_. If so, remove that file.
3. open command line here
4. run `make clean && make` to create .o files
5. now run `./build/linux_demo` to run the app

### To run on Windows
 
2. Open folder in Visual Studio
4. Set the solution target to: **`x86`**
5. make sure that in folder FreeRTOS/Source/include is file called FreeRTOSConfig.h, if not move file from FreeRTOS/ConfigWin/FreeRTOSConfig.h to location previously mentioned
6. Rename the project to the project name you want
7. Run the project

## Making project

To  make your own project you need to modify my_main.c file and repete **To run on linux** if runing on linux and **To run on Windows** if your PC runs windows

## Contibuting

If you find something wrong you have some questions or you have something that can help do not hesitate to make new branch and make pull request.
