/*  Section 7
    Challenge
    
    Write a C++ program as follows:
    
    Declare 2 empty vectors of integers named
    vector1 and vector 2, respectively.
    
    Add 10 and 20 to vector1 dynamically using push_back
    Display the elements in vector1 using the at() method as well as its size using the size() method
    
    Add 100 and 200 to vector2 dynamically using push_back
    Display the elements in vector2 using the at() method as well as its size using the size() method

    Declare an empty 2D vector called vector_2d
    Remember, that a 2D vector is a vector of vector<int>
    
    Add vector1 to vector_2d dynamically using push_back
    Add vector2 to vector_2d dynamically using push_back
    
    Display the elements in vector_2d using the at() method
    
    Change vector1.at(0) to 1000
    
    Display the elements in vector_2d again using the at() method
    
    Display the elements in vector1 
    
    What did you expect? Did you get what you expected? What do you think happended?
*/

#include <iostream>
#include <vector>

using std::vector;

int main()
{
     // Declare 2 empty vectors of integers named
     // vector1 and vector 2, respectively.

     vector <int> vector1 {}; // {} can be omitted
     vector <int> vector2 {}; // {} can be omitted

     // Add 10 and 20 to vector1 dynamically using push_back
     // Display the elements in vector1 using the at() method as well as its size using the size() method

     vector1.push_back(10);
     vector1.push_back(20);

     // Display the elements in vector1 using the at() method as well as its size using the size() method

     std::cout << "\nvector1 elements:\n";
     std::cout << "vector1[0]: " << vector1.at(0) << '\n';
     std::cout << "vector1[1]: "  << vector1.at(1)<< '\n';
     std::cout << "vector1 size: "  << vector1.size()<< '\n';

     // Add 100 and 200 to vector2 dynamically using push_back
     vector2.push_back(100);
     vector2.push_back(200);

     // Display the elements in vector2 using the at() method as well as its size using the size() method

     std::cout << "\nvector2 elements:\n";
     std::cout << "vector2[0]: " << vector2.at(0) << '\n';
     std::cout << "vector2[1]: "  << vector2.at(1)<< '\n';
     std::cout << "vector2 size: "  << vector2.size()<< '\n';

     // Declare an empty 2D vector called vector_2d
     // Remember, that a 2D vector is a vector of vector<int>

     vector <vector<int>> vector_2d {}; // {} can be omitted

     // Add vector1 to vector_2d dynamically using push_back
     // Add vector2 to vector_2d dynamically using push_back

     vector_2d.push_back(vector1);
     vector_2d.push_back(vector2);

     // Display the elements in vector_2d using the at() method
     std::cout << "\nvector_2d row 0.\n";
     std::cout << vector_2d.at(0).at(0) << '\n';
     std::cout << vector_2d.at(0).at(1) << '\n';

     std::cout << "\nvector_2d row 1.\n";
     std::cout << vector_2d.at(1).at(0) << '\n';
     std::cout << vector_2d.at(1).at(1) << '\n';

     // Change vector1.at(0) to 1000
     vector1.at(0) = 1000;

     // Display the elements in vector_2d again using the at() method
     // vector_2d doesn't pick up change to vector1, it gets a copy of vector at initialisation
     std::cout << "\nvector_2d row 0.\n";
     std::cout << vector_2d.at(0).at(0) << '\n';
     std::cout << vector_2d.at(0).at(1) << '\n';

     std::cout << "\nvector_2d row 1.\n";
     std::cout << vector_2d.at(1).at(0) << '\n';
     std::cout << vector_2d.at(1).at(1) << '\n';

     // Display the elements in vector1 using the at() method as well as its size using the size() method

     std::cout << "\nvector1 elements:\n";
     std::cout << "vector1[0]: " << vector1.at(0) << '\n';
     std::cout << "vector1[1]: "  << vector1.at(1)<< '\n';

     return 0;
}