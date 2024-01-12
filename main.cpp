#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;


int main()
{
     vector <int> test_scores {100, 98, 89};

     test_scores.push_back(85);
     test_scores.push_back(93);
     
     cout << "Fifth score at index 4: " 
     << test_scores.at(4) << endl; // 93

}