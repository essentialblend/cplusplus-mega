// Modify the “mini calculator” from exercise 5 to accept (just) single-digit numbers written as either digits or spelled out.

#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> numArr{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int parseInput()
{
    int result{ 0 };
    std::string num{ 0 };
    if (std::cin >> result)
    {
        return result;
    }
    else
    {
        std::cin.clear();
        std::cin >> num;
        for (int i = 0; i < numArr.size(); i++)
        {
            if (num == numArr[i])
            {
                return (result = i);
            }
        }
    }
}

int main()
{
    int num1{ 0 };
    int num2{ 0 };
    char oprtr{ 0 };
    std::string userInp{ 0 };
    

    std::cout << "Enter op opr1 opr2 [e.g + 5 zero]: ";
    while (true)
    {
        std::cin >> oprtr;
        num1 = parseInput();
        num2 = parseInput();

        switch (oprtr)
        {
        case '+':
            std::cout << num1 << " " << oprtr << " " << num2 << " is: " << (num1 + num2) << ".\n";
            break;
        case '-':
            std::cout << num1 << " " << oprtr << " " << num2 << " is: " << (num1 - num2) << ".\n";
            break;
        case '*':
            std::cout << num1 << " " << oprtr << " " << num2 << " is: " << (num1 * num2) << ".\n";
            break;
        case '/':
            if (num2 == 0) { std::cout << "No division by 0.\n"; }
            else
            {
                std::cout << num1 << " " << oprtr << " " << num2 << " is: " << (num1 / num2) << ".\n";
            }
            break;
        default:
            std::cout << "This is not a valid operation (use +, -, * or /)\n";
            break;
        }
    }
}
