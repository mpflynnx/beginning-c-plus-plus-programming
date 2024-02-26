#include <iostream>
#include <vector>
#include <string>

int main() {

   std::vector<std::string> stooges { "Larry", "Moe", "Curly"};

   for (auto &str: stooges)
      str = "Funny"; 

   for (auto const &str: stooges)
      std::cout << str << '\n'; // 

   return 1;
}
