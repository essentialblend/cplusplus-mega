// Write a program that performs as a very simple calculator. Your calculator should be able to handle the four basic math operations — add, subtract, multiply, and divide — on two input values. Your program should prompt the user to enter three arguments: two double values and a character to represent an operation.

#include <iostream>
#include <string>

int main()
{
    double opr1{ 0 };
    double opr2{ 0 };
    double ans{ 0 };
    char oprtr = ' ';

    startPoint:
    std::cout << "\n[enter 'exit' to exit]\n";
    std::cout << "Enter an OPERATOR <space> OPERAND <space> OPERAND: ";
    

    while ((std::cin >> oprtr >> opr1 >> opr2))
    {
        if ((oprtr != 'exit'))
        {
            switch (oprtr)
            {
            case '+':
                ans = opr1 + opr2;
                std::cout << "The sum of " << opr1 << " & " << opr2 << " is: " << ans << ".\n";
                break;
            case '-':
                ans = opr1 - opr2;
                std::cout << "The difference between " << opr1 << " & " << opr2 << " is: " << ans << ".\n";
                break;
            case '*':
                ans = opr1 * opr2;
                std::cout << "The product of " << opr1 << " & " << opr2 << " is: " << ans << ".\n";
                break;
            case '/':
                ans = opr1 / opr2;
                std::cout << "The division between " << opr1 << " & " << opr2 << " is: " << ans << ".\n";
                break;
            default:
                std::cout << "Invalid operator.\n";
                break;
            }
        }
          
        std::cout << "Do you want to run again?: ";
        std::cin >> oprtr;
        if (oprtr == 'y') goto startPoint; //goes to line 12.
        else return 0;
    }
    return 0;

}