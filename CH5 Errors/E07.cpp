// Quadratic equations are of the form a·x2 + b·x + c = 0. To solve these, one uses the quadratic formula: There is a problem, though: if b2–4ac is less than zero, then it will fail. Write a program that can calculate x for a quadratic equation. Create a function that prints out the roots of a quadratic equation given a, b, c. When the program detects an equation with no real roots, have it print out a message. How do you know that your results are plausible? Can you check that they are correct?

// y = -b +- sqrt(bsq - 4ac) / 2a

#include <iostream>

int main()
try
{
    double valA{ 0 };
    double valB{ 0 };
    double valC{ 0 };
    double determVal{ 0 };
    double rootOne{ 0 };
    double rootTwo{ 0 };
    double valX{ 0 };

    std::cout << "Enter values for a, b and c, each followed by a space: ";
    std::cin >> valA >> valB >> valC;

    if (!std::cin)
    {
        throw std::runtime_error("Invalid input type! Please run and try again...");
    }
    if (valA == 0)
    {
        if (valB == 0)
        {
            std::cout << "No roots since X isn't utilized.\n";
        }
        else
        {
            std::cout << "The value of x is: " << (valX = -valC / valB) << ".\n";
        }
    }
    else if (valB == 0)
    {
        valX = -valC / valA;
        if (valX == 0)
        {
            std::cout << "The value of x is 0!";
        }
        else if (valX < 0)
        {
            std::cout << "No real roots available!";
        }
        else
        {
            std::cout << "There are two available roots: " << std::sqrt(valX) << " & " << -(std::sqrt(valX)) << ".\n";
        }
    }
    else
    {
        determVal = (valB * valB) - (4 * valA * valC);
        if (determVal == 0)
        {
            std::cout << "One real root available: " << (-valB / (2 * valA)) << ".\n";
        }
        else if (determVal < 0)
        {
            std::cout << "No real roots available!\n";
        }
        else if (determVal > 0)
        {
            std::cout << "There are two real roots: " << ((-valB + std::sqrt(determVal)) / (2 * valA)) << " & " << ((-valB - std::sqrt(determVal)) / (2 * valA)) << ".\n";
        }
    }
    return 0;
}
catch (std::exception& e)
{
    std::cout << "Runtime error: " << e.what() << "\n";
    return 1;
}
catch (...)
{
    std::cout << "Unknown exception!\n";
    return 2;
}
    

