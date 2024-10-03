## Section x: Visual Studio Code Make file project

## Table of Contents

- [Visual Studio Code Extensions](#visual-studio-code-extensions)


### Visual Studio Code Extensions

#### C/C++ by Microsoft
The C/C++ extension adds language support for C/C++ to Visual Studio Code, including editing (IntelliSense) and debugging features.

#### C/C++ makefile Project by Adriano Markovic
This extension is generating a simple C/C++ project structure together with a Makefile which fits almost 99% of all small project's needs.

#### Code Runner by Jun Han
Run code snippet or code file for multiple languages: C, C++ and more

### Extension usage

#### Code Runner by Jun Han
Run a simple program like 'hello world' contained in one file. Use Run Code or Alt+Ctrl+N

#### C/C++ makefile Project by Adriano Markovic
Initialize the project in the current working directory with `Ctrl+Shift+P` on a Windows/Linux and choose `C/C++ Make: INIT Project`

- Two new folders will be created named obj and src
- One new file Makefile

#### Compiling using make
Edit Makefile line 11. Change APPNAME = myapp to match the folder name the project was initialised in (SimpleList). This will be the name of the executable.

Create a main.cpp file inside src folder

```c
#include <iostream>

int main(){

    std::cout << "Hello World!" << std::endl;
    return 0;

}
```

Compile the project using make

Using the Terminal type: make

```bash
➜  SimpleList make
```
#### Terminal Output
```bash
g++ -std=c++11 -Wall -o obj/main.o -c src/main.cpp
g++ -std=c++11 -Wall -o SimpleList obj/main.o 
```

The make command, compiled src/main.cpp and linked the obj/main.o file to create the executable file name SimpleList.

Run the newly created executable using the following terminal command

```bash
➜  SimpleList ./SimpleList 
```

#### Terminal Output
```bash
Hello World!
```

## References
- [youtube.com | SavvyNik | Master C++ on Linux | Full Course](https://www.youtube.com/watch?v=VXvPpPCF7E0)
