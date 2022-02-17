// Augment the program so that it writes the line the numbers are equal (only) if they are equal.

#include <iostream>

int main()
{
    int numOne{ 0 };
    int numTwo{ 0 };

    std::cout << "Enter two ints to print [terminate with '|']: ";
    while (std::cin >> numOne >> numTwo)
    {
        (numOne == numTwo) ? 
            (std::cout << numOne << " & " << numTwo << " are equal.\n\n") :
            (std::cout << "Not equal, re-enter two ints to print [terminate with '|']: ");
    }
    return 0;
}