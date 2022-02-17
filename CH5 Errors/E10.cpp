// Modify the program from exercise 8 to use double instead of int. Also, make a vector of doubles containing the N–1 differences between adjacent values and write out that vector of differences.

#include <iostream>
#include <vector>
#include <stdexcept>

int main()
try
{
    double userInput{ 0 }; //Taking the value in double, truncating it into an int incase the user decides to enter a fractional value.
    double userArrInput{ 0 };
    std::vector<double> numArray{};
    std::vector<double> diffArray{};
    int sumVal{ 0 };

    std::cout << "Enter the value for N, which is the 1-n summation: ";
    if (!(std::cin >> userInput))
    {
        throw std::runtime_error("Invalid input type!");
    }
    else if (userInput <= 0)
    {
        throw std::runtime_error("Can't sum elements less than 1!");
    }
    else
    {
        userInput = std::trunc(userInput);
        std::cout << "Enter the values of the array, terminate with '|': ";
        while (std::cin >> userArrInput)
        {
            numArray.push_back(userArrInput);
            //E10
            if (numArray.size() >= 2)
            {
                diffArray.push_back(userInput - numArray[numArray.size() - 2]);
            }
        }
        if (numArray.size() < userInput)
        {
            throw std::out_of_range("Out of range: Insufficient numbers provided!");
        }
        for (int i{ 0 }; i < userInput; ++i)
        {
            sumVal += numArray[i];
        }
        std::cout << "\nThe sum of the first " << userInput << " numbers in the array is: " << sumVal << ".\n";
        return 0;
    }
}
catch (std::exception& e)
{
    std::cout << "Runtime error: " << e.what() << "\n";
}
catch (...)
{
    std::cout << "Unknown error!\n";
    return 2;
}
