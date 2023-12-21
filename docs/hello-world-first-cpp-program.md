## Hello World first C++ Program

Create a new file named `main.cpp`

```c++
#include <iostream>

int main() {
    std::cout << "Hello Gitpod World" << std::endl;
    return 0;
}
```

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