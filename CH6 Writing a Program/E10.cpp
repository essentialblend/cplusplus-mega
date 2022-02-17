/*E10 - Calculate Permutations and Combinations.
P(a,b) = a! / (a - b)!
C(a,b) = P(a,b) / b!
*/
#include <iostream>
#include <vector>

const double CalculateFactorial(const int& TempDouble)
{
    if (TempDouble < 0) throw std::runtime_error("Can't compute factorial of a negative number.");
    return (TempDouble > 1) ? (TempDouble * CalculateFactorial(TempDouble - 1)) : 1;
}

int main()
try
{
    int UserN{ 0 };
    int UserR{ 0 };
    char UserChoice{ ' ' };
    std::cout << "Enter a positive integer > 0 for N and R [n r]: ";
    std::cin >> UserN >> UserR;
    if (!std::cin || UserN == 0 || UserR == 0) throw std::runtime_error("Invalid input.");
    std::cout << "Do you want to calculate permutations or combinations [P/C]...";
    std::cin >> UserChoice;

    switch (UserChoice)
    {
    case 'P': case 'p':
        std::cout << "Permutations of " << UserN << "/" << UserR << " are: " << (CalculateFactorial(UserN) / CalculateFactorial(UserN - UserR)) << ".\n";
        break;
    case 'C': case 'c':
        std::cout << "Combinations of " << UserN << "/" << UserR << " are: " << ((CalculateFactorial(UserN) / CalculateFactorial(UserN - UserR)) / CalculateFactorial(UserR)) << ".\n";
        return 0;
    default:
        throw std::runtime_error("Invalid answer. Pick p/P or c/C...");
    }
}


catch (std::exception& exc)
{
    std::cout << "Runtime error: " << exc.what() << "\n";
    return 1;
}
catch (...)
{
    std::cout << "Unknown exception!\n";
    return 2;
}