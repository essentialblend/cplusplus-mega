// Write a program that reads and stores a series of integers and then computes the sum of the first N integers. First ask for N, then read the values into a vector, then calculate the sum of the first N values. For example: “Please enter the number of values you want to sum:”3“ Please enter some integers (press '|' to stop): ”12 23 13 24 15 | “The sum of the first 3 numbers ( 12 23 13 ) is 48.” Handle all inputs. For example, make sure to give an error message if the user asks for a sum of more numbers than there are in the vector.

// Modify the program from exercise 8 to write out an error if the result cannot be represented as an int. -- P.S Result is always an int.

#include <iostream>
#include <vector>
#include <stdexcept>

int main()
try
{
    double userInput{ 0 }; //Taking the value in double, truncating it into an int incase the user decides to enter a fractional value.
    int userArrInput{ 0 };
    std::vector<int> numArray{};
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
