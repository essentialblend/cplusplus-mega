// Now change the body of the loop so that it reads just one double each time around. Define two variables to keep track of which is the smallest and which is the largest value you have seen so far. Each time through the loop write out the value entered. If it’s the smallest so far, write the smallest so far after the number. If it is the largest so far, write the largest so far after the number.

#include <iostream>

int main()
{
    double valOne{ 0 };
    double biggestNum{ 0 };
    double smallestNum{ 0 };
    double tempNum{ 0 };

    std::cout << "Enter one number [terminate with '|']: ";
    while (std::cin >> valOne)
    {
        if (tempNum == 0)
        {
            biggestNum = valOne;
            smallestNum = valOne;
            std::cout << valOne << " is biggest yet.\n";
            std::cout << valOne << " is smallest yet.\n\n";
            std::cout << "Enter one number [terminate with '|']: ";
            tempNum++;
        }
        else if (valOne > biggestNum)
        {
            biggestNum = valOne;
            std::cout << biggestNum << " is biggest yet.\n\n";
            std::cout << "Enter one number [terminate with '|']: ";
        }
        else if (valOne < smallestNum)
        {
            smallestNum = valOne;
            std::cout << smallestNum << " is smallest yet.\n\n";
            std::cout << "Enter one number [terminate with '|']: ";
        }
        else
        {
            std::cout << "No change.\n\n";
            std::cout << "Enter one number [terminate with '|']: ";
        }
    }
    return 0;
}
