// Change the program to write out the smaller value is: followed by the smaller of the numbers and the larger value is: followed by the larger value.

#include <iostream>

int main()
{
    int numOne{ 0 };
    int numTwo{ 0 };

    while (std::cin >> numOne >> numTwo)
    {
        (numOne > numTwo) ?
        (std::cout << "The smaller value is: " << numTwo << ".\n") && (std::cout << "The larger value is: " << numOne << ".\n") : /* ':' is else (from (e1) ? (e2) : (e3) */
        (std::cout << "The smaller value is: " << numOne << ".\n") && (std::cout << "The larger value is: " << numTwo << ".\n");
    }
    return 0;
}

