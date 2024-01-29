#include <iostream>
#include <vector>

int main()
{

    for (int num1 {1}; num1 <=10; ++num1){
        for (int num2 {1}; num2 <=10; ++num2){
            std::cout << num1 
                    << " * " 
                    << num2 
                    << "   = " 
                    << num1 * num2 
                    << '\n';
        }
        std::cout << "---------------" << '\n';
    }

    std::cout << '\n';
    
    return 0;
}
