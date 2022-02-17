// Write a program that takes an input value n and then finds the first n primes.

#include <iostream>
#include <vector>

std::vector<int> primesArray{};

bool IsPrime(int num)
{
    
    for (int i = 0; primesArray[i] <= std::sqrt(num); ++i)
    {
        if (num % primesArray[i] == 0)
            return false;
    }
    return true;
}

int main()
{
    int userNum{ 0 };

    int num{ 5 };
    std::cout << "Enter n to find the first n primes: ";
    std::cin >> userNum;
    if (userNum == 0)
    {
        std::cout << "No primes. Invalid. Enter again...";
        return 0;
    }
    else
    {
        primesArray.push_back(2);
        for (int i{ 3 }; primesArray.size() < userNum; i+=2)
        {
            if (IsPrime(i))
            {
                primesArray.push_back(i);
            }
        }

        std::cout << "Your first " << userNum << " primes are:\n";
        for (int i = 0; i < primesArray.size(); i++)
        {
            std::cout << (i + 1) << ". " << primesArray[i] << ".\n";
        }
        return 0;
    }
    
}