// Change the program so that it writes out the numbers are almost equal after writing out which is the larger and the smaller if the two numbers differ by less than 1.0 / 100.

#include <iostream>

int main()
{
    double inputNumOne{ 0 };
    double inputNumTwo{ 0 };
    double bigNum{ 0 };
    double smallNum{ 0 };

    std::cout << "Enter two numbers [terminate with '|']: ";
    while (std::cin >> inputNumOne >> inputNumTwo)
    {
        (inputNumOne > inputNumTwo) ?
            (bigNum = inputNumOne) && (smallNum = inputNumTwo) &&
            (std::cout << "The smaller / larger numbers (resp) are: " << smallNum << " & " << bigNum << ".\n") :
            (bigNum = inputNumTwo) && (smallNum = inputNumOne) &&
            (std::cout << "The smaller / larger numbers (resp) are: " << smallNum << " & " << bigNum << ".\n");
        if ((std::abs(bigNum) - std::abs(smallNum) < (1.0/100)))
        {
            std::cout << "The numbers are almost equal.\n\n";
            std::cout << "Enter two numbers [terminate with '|']: ";
        }
        else if(inputNumOne == inputNumTwo)
        {
            std::cout << "The numbers are equal.\n";
            std::cout << "Enter two numbers [terminate with '|']: ";
        }
    }
    return 0;
}