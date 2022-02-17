// Change the program so that it uses doubles instead of ints.

#include <iostream>

int main()
{
    double numOne{ 0 };
    double numTwo{ 0 };

    std::cout << "Enter two ints to print [terminate with '|']: ";
    while (std::cin >> numOne >> numTwo)
    {
        (numOne == numTwo) ?
            (std::cout << numOne << " & " << numTwo << " are equal.\n\n") :
            (std::cout << "Not equal, re-enter two ints to print [terminate with '|']: ");
    }
    return 0;
}