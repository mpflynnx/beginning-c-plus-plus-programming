## Solution

```c
#include <iostream>
#include <string>

int sum_of_digits(int n) {
    // Write your code below this line
    
    if (n == 0)
        return 0;
    return (n % 10 + sum_of_digits(n / 10));
    
    // Write your code above this line
}
```c