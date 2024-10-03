## C++ compiling with g++
- View Results of pre-processing with -E
  - g++ -E myprog.cpp > myprog.s // output redirected to file myprog.s

- Compile to an object file with -c
  - g++ -c myprog.cpp
  - Produces object file myprog.o

- Objects then linked to a single executable
  - g++ -o myprog myprog1.o myprog2.o

- Compile multiple files in one step
  - g++ *.cpp -o myprog
  - Will not generate object files
  - Recompiles every .cpp file each time
 
- Linking is much faster than compiling

- Wanted: compile files that have changed
  - Generate new object files if .cpp files have changed, and link them
  - This can be done with a Makefile using make
  - Automatically done if using Microsoft Visual Studio IDE
 
## External references
- [youtube.com | Dave Churchill | Introduction to the C++ Programming Language](https://youtu.be/gSubXB3HUgc?si=SbEVxgG2ZtXpywo9)
