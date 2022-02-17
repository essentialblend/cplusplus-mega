// Write a program that writes out the first so many values of the Fibonacci series, that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next number of the series is the sum of the two previous ones. 
// Find the largest Fibonacci number that fits in an int.

#include <iostream>
#include <vector>

void CalculateFibonacci(bool bValue)
{
    int a{ 1 };
    int b{ 1 };
    int count{ 0 };
    int max{ 0 };
    std::vector<int> fibbArray{};
    if(bValue)
    {
        fibbArray.push_back(1);
        fibbArray.push_back(1);
        while (fibbArray[fibbArray.size() - 1] + fibbArray[fibbArray.size() - 2] > fibbArray[fibbArray.size() - 2])
        {
            fibbArray.push_back(fibbArray[fibbArray.size() - 1] + fibbArray[fibbArray.size() - 2]);
        }
        std::cout << "The biggest fibonacci that fits an int is: " << fibbArray[fibbArray.size() - 1] << ".\n";
        std::cout << "Belongs to index: " << (fibbArray.size() - 1) << ".\n";
        return;
    }
    else
    {
        std::cout << "Enter the number of fibonacci's you want to see: ";
        takeUserInput: // #1: begins to take user input.
        std::cin >> max;
        if (!std::cin >> max)
        {
            throw std::runtime_error("Invalid input type!");
        }
        if (max < 1)
        {
            std::cout << "Please enter a number greater than 0: ";
            goto takeUserInput; // goto #1.
        }
        std::cout << "\nFibonacci series: 1, 1, ";
        while (count < (max - 2))
        {
            int c = a + b;
            if (count == (max - 3))
            {
                std::cout << c << ".\n";
            }
            else
            {
                std::cout << c << ", ";
            }
            a = b;
            b = c;
            count++;
        }
    }
}
int main()
try
{
    int userC{ 0 };
    bool bFibOrMax = true; //True = find fib. False = find max int.
    takeUserChoice: // #2 : Begins to take input 1 or 2.
    std::cout << "Press 1 to display FN's upto N & 2 to find the max FN fitting an int: ";
    std::cin >> userC;
    if (!std::cin >> userC)
    {
        throw std::runtime_error("Invalid input type! Run again! 0"); // # at end of error statement is just for debug purposes and should be ignored for brevity.
    }
    if (userC != 1 && userC != 2)
    {
        std::cout << "Wrong input! ";
        goto takeUserChoice;
    }
    if (userC == 1)
    {
        CalculateFibonacci(!bFibOrMax);
    }
    else if(userC == 2)
    {
        CalculateFibonacci(bFibOrMax);
    }
    return 0;
}
catch (std::exception& e)
{
    std::cout << "Runtime error: " << e.what();
    return 1;
}
catch (...)
{
    std::cout << "Unknown exception!";
    return 2;
}