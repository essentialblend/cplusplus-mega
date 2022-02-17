// Create a program to find all the prime numbers between 1 and 100. There is a classic method for doing this, called the “Sieve of Eratosthenes.” If you don’t know that method, get on the web and look it up. Write your program using this method.

// Modify the program described in the previous exercise to take an input value max and then find all prime numbers from 1 to max.

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numberList{};
    std::vector<bool> numberEliminate{};
    int maxNum{ 0 };
    int p{ 2 };
    int tempStorage{ 1 };

    std::cout << "Please enter n for primes between 1-n: ";
    std::cin >> maxNum;

    for (int i{ 2 }; i <= maxNum; i++)
    {
        numberList.push_back(i);
        numberEliminate.push_back(false);
    }

    std::cout << "Number of elements in array: " << numberList.size() << ".\n";
    std::cout << "Indice range 0 to " << numberList.size() - 1 << ".\n";

    while (p < maxNum)
    {
        int res{ 0 };
        for (int i{ 2 }; res <= maxNum; i++)
        {
            for (int j{ 0 }; j < numberList.size(); j++)
            {
                res = i * p;
                if (numberList[j] == res)
                {
                    numberEliminate[j] = true;
                }
            }
        }
        for (int i{ 0 }; i < numberEliminate.size(); i++)
        {
            if (numberList[i] > p)
            {
                p = numberList[i];
                break;
            }
        }
    }
    std::cout << "\nOutputting (hopefully) prime numbers between 1 to " << maxNum << ": ---- \n";
    std::cout << "----------------------------\n";
    for (int i{ 0 }; i < numberEliminate.size(); i++)
    {
        if (numberEliminate[i] == false)
        {
            std::cout << tempStorage++ << ". " << numberList[i] << ".\n";
        }
    }
    std::cout << "\n";
    return 0;
}