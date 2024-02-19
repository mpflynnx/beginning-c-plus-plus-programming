## Implementing a Recursive Function - Save a Penny

[udemy.com | Implementing a Recursive Function - Save a Penny](https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/quiz/4473892#questions)

In this exercise you will create a program that calculates the total_amount of money that will be accumulated if you start with a penny and double it everyday for n number of days.

E.g.

Day 1: $0.01

Day 2: $0.02

Day 3: $0.04

. . .

. . .

. . .

Day 16: $327.68

Day 17: $655.36

Day 18: $1310.72

For this program, assume that all money will be represented as a double value and so a penny will be represented as 0.01.

Begin by completing the function prototype a_penny_doubled_everyday which is passed an int and a double.

Now that the function prototype is declared, at the bottom of the file define the function.

The function should return the total_amount accumulated after n number of days. For example, if n = 18, the function should return 1310.72. The function should be able to calculate the total_amount for any number of days starting with any amount however the default amount should be a penny.

Now, from the function body of amount_accumulated, declare and initialize the variable total_amount by calling the a_penny_doubled_everyday function for n = 25 days.

Note: if you get an error such as "Oops, there was a problem on our end". This may mean that you have infinite recursion in your solution. Make sure your logic checks for a base case and doesn't recurse forever.

You can find my solution by clicking on the solution.txt file on the left pane. But please make sure you give it a go yourself first, and only check the solution if you really get stuck.