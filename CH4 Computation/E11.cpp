//  Create a program to find all the prime numbers between 1 and 100.One way to do this is to write a function that will check if a number is prime (i.e., see if the number can be divided by a prime number smaller than itself) using a vector of primes in order (so that if the vector is called primes, primes[0]==2, primes[1]==3,primes[2]==5, etc.). Then write a loop that goes from 1 to 100, checks each number to see if it is a prime, and stores each prime found in a vector. Write another loop that lists the primes you found. You might check your result by comparing your vector of prime numbers with primes. Consider 2 the first prime.

// Modify the program described in the previous exercise to take an input value max and then find all prime numbers from 1 to max.

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> PrimesArray{ 2 };

bool IsNumberPrime(int num)
{
    for (int p = 0; p < PrimesArray.size(); ++p)
    {
        if (num % PrimesArray[p] == 0)
        {
            return false;
        }  
    }
    return true;
}

int main()
{
    char input{ 0 };
    int maxNum{ 0 };
    std::cout << "Input 'y' to compute prime numbers between 1 and 100...: ";
    std::cin >> input;
    std::cout << "Enter a max value [1 - max]: ";
    std::cin >> maxNum;
    
    if (input == 'y')
    {
        for (int i = 3; i <= maxNum; ++i)
        {
            if (IsNumberPrime(i))
            {
                PrimesArray.push_back(i);
            }
        }
        std::cout << "I found " << PrimesArray.size() << " primes in your range of 1 to " << maxNum << ".\n";
        std::cout << "------- Here they are -------\n";
        for (int i = 0; i < PrimesArray.size(); ++i)
        {   
            std::cout << PrimesArray[i] << ", ";
        }
    }
    else
    {
        std::cout << "Invalid input...Run again.\n";
        return 0;
    }

}