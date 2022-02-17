//Write a program that consists of a while-loop that (each time around the loop) reads in two ints and then prints them. Exit the program when a terminating '|' is entered.

#include <iostream>

int main()
{
    int numOne{ 0 };
    int numTwo{ 0 };

    std::cout << "Enter two ints to print [terminate with '|']: ";
    while (std::cin >> numOne >> numTwo)
    {
        std::cout << "Two numbers are: " << numOne << " & " << numTwo << "\n\n";
        std::cout << "Enter two ints to print: ";
    }
    return 0;
}