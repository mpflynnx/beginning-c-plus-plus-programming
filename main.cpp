#include <vector>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
     vector <vector<int>> movie_ratings 
     {
          {1, 2, 3, 4}, // 0 reviewer 1
          {1, 2, 4, 4}, // 1 reviewer 2
          {1, 3, 4, 5}  // 2 reviewer 3

     };

     cout << "\nReviewer 1 scores.\n";
     cout << movie_ratings.at(0).at(0) << endl;
     cout << movie_ratings.at(0).at(1) << endl;
     cout << movie_ratings.at(0).at(2) << endl;
     cout << movie_ratings.at(0).at(3) << endl;

     cout << "\nReviewer 2 scores.\n";
     cout << movie_ratings.at(1).at(0) << endl;
     cout << movie_ratings.at(1).at(1) << endl;
     cout << movie_ratings.at(1).at(2) << endl;
     cout << movie_ratings.at(1).at(3) << endl;

     cout << "\nReviewer 3 scores.\n";
     cout << movie_ratings.at(2).at(0) << endl;
     cout << movie_ratings.at(2).at(1) << endl;
     cout << movie_ratings.at(2).at(2) << endl;
     cout << movie_ratings.at(2).at(3) << endl;

     return 0;
}