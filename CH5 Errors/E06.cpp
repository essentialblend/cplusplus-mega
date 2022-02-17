// Write a program that converts from Celsius to Fahrenheit and from Fahrenheit to Celsius (formula in §4.3.3). Use estimation (§5.8) to see if your results are plausible.

#include <iostream>

void ConvertFunction(int userPick)
{
    double finalValue{ 0 };
    double userInput{ 0 };

    switch (userPick)
    {
    case 1:
        std::cout << "Enter a value (deg C): ";
        if (!(std::cin >> userInput))
        {
            throw std::runtime_error("Invalid form of input!");
        }
        if (userInput < -273.15)
        {
            throw std::runtime_error("Temp below absolute zero!");
        }
        finalValue = (userInput * 9 / 5) + 32;
        std::cout << "\nYour value " << userInput << " deg C converts to: " << finalValue << " F!\n";
        break;
    
    case 2:
        std::cout << "Enter a value (F): ";
        if (!(std::cin >> userInput))
        {
            throw std::runtime_error("Invalid form of input!");
        }
        if (userInput < -459.67)
        {
            throw std::runtime_error("Temp below absolute zero!");
        }
        finalValue = (userInput - 32) * (5 / 9);
        std::cout << "\nYour value " << userInput << " F converts to: " << finalValue << " deg C!\n";
        break;
    default:
        break;
    }
}

int main()
try
{
    int userChoice{ 0 };
    std::cout << "Enter 1: (degC to F) OR 2: (F to degC): ";
    while (std::cin >> userChoice)
    {
        if (userChoice != 1 && userChoice != 2 && (!std::cin >> userChoice))
        {
            std::cout << "Invalid choice!\nEnter 1: (degC to F) and 2: (F to degC): ";
        }
        else
        {
            ConvertFunction(userChoice);
            return 0;
        }
    }
}
catch (std::exception& e)
{
    std::cout << "Runtime Error: " << e.what() << "\n";
    return 1;
}
catch (...)
{
    std::cout << "Unknown exception!";
    return 2;
}