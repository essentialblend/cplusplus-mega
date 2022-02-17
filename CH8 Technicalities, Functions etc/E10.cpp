/*E10 - Write a function maxv() that returns the largest element of a vectorargument.*/

#include <iostream>
#include <vector>

double ReturnMaxFromVector(const std::vector<double>& UArray)
{
    double MaxValue = UArray[0];

    for (int TVal : UArray)
    {
        if (TVal > MaxValue)
            MaxValue = TVal;
    }
    return MaxValue;
}

int main()
try
{
    std::vector<double> UserArray;
    int NumArrayChoice{ 0 };
    double UserInput{ 0 };
    std::cout << "Number of elements (1 - 20)"; /*20 was randomly picked.*/
    if (!(std::cin >> NumArrayChoice || NumArrayChoice == 0)) throw std::runtime_error("Invalid input. Enter a number between 1-20.");

    for (int i{ 0 }; i < NumArrayChoice; i++)
    {
        std::cout << "Enter a number: ";
        if (!(std::cin >> UserInput)) throw std::runtime_error("Invalid input.");
        UserArray.push_back(UserInput);
    }
    
    std::cout << "MAX value in your double array: " << ReturnMaxFromVector(UserArray) << ".\n";
    return 0;
}
catch (std::exception& exc)
{
    std::cout << "Runtime Error: " << exc.what() << "\n";
    return 1;
}
catch (...)
{
    std::cout << "Unknown exception!\n";
    return 2;
}