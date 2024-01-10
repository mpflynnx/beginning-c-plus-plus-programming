## Hello World first C++ Program

Create a new file named `main.cpp`

```c
#include <iostream>

int main() {
    std::cout << "Hello Gitpod World" << std::endl;
    return 0;
}
```
**Program breakdown**
```c
#include <iostream>
```
This is known as a preprocessor directive and begins with # no semi-colon `;` is needed at the end.

```c
int main() 
{
    // main fucntion code here
}
```

The main function is the entry point to the program.

```c
std::cout << "Hello Gitpod World" <<
```

Use namespace `std`, `cout` to output to the console.

Insertion operator `<<` is use to insert into `cout`.

```c
"Hello Gitpod World"
```
The text to display on screen should be placed inside double quotes. This is known as a string literal.
```c
<< std::endl;
```
Inserts to `cout` a new line, using the namespace `std`, `endl` to output to the console.

Compile file `main.cpp` to create new file `a.out`

Open terminal and type:
```bash
$ g++ -Wall -std=c++14 main.cpp
```

Execute file `a.out`

```bash
$ ./a.out
```

Expected output

```bash
$ ./a.out
Hello Gitpod World
$
```