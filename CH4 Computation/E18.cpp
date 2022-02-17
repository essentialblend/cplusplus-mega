// Write a program to solve quadratic equations. A quadratic equation is of the form: ax2 + bx + c = 0

#include <iostream>

int main()
{
    double a{ 0 };
    double b{ 0 };
    double c{ 0 };
    double valueX1{ 0 };
    double valueX2{ 0 };
    double bSquared{ 0 };
    double qNumer{ 0 };
    double tempVar{ 0 };

    std::cout << "Enter values for a (a > 0), b and c followed by a space: ";
    while (std::cin >> a >> b >> c)
    {
        if (a == 0)
        {   
            std::cout << "a cannot be 0.\n";
            std::cout << "Enter values for a (a > 0), b and c followed by a space: ";
        }
        else
        {
            // -b +- sqrt(b rt 2 - 4ac) / 2a;
            bSquared = std::pow(b, 2.0);
            tempVar = bSquared - (4 * a * c);
            if (tempVar < 0)
            {
                std::cout << "No complex math.\n";
                std::cout << "Enter values for a (a > 0), b and c followed by a space: ";
            }
            else if (tempVar == 0 || tempVar > 0)
            {
                qNumer = std::sqrt(tempVar);
                valueX1 = (-b + qNumer) / (2 * a);
                valueX2 = (-b - qNumer) / (2 * a);

                std::cout << "The x1 value: " << valueX1 << ".\n";
                std::cout << "The x2 value: " << valueX2 << ".\n";
                std::cout << "\nEnter values for a (a > 0), b and c followed by a space: ";
            }
        }
    }
    return 0;
}