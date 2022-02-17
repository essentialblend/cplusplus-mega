#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

std::vector<char> GeneratePassword()
{
    std::vector<char> decimalArray{ 'a', 'b', 'c', 'd' };
    std::vector<char> solutionArray = decimalArray;
    auto timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937_64 timeVar(timeSeed);
    std::shuffle(solutionArray.begin(), solutionArray.end(), timeVar);
    return solutionArray;
}

void DisplayPassword(std::vector<char> tempArray)
{
    for (char x : tempArray)
    {
        std::cout << x << " ";
    }
}

int main()
try
{
startGame:
    int bullCount{ 0 };
    int cowCount{ 0 };
    char c0{ 'x' };
    char c1{ 'x' };
    char c2{ 'x' };
    char c3{ 'x' };
    std::vector<char> finalLockArray = GeneratePassword();
    std::vector<int> userInputArray{};
    int triesCount{ 0 };
    int diffLevel{ 0 };
    int plLives{ 10 };

    plLives = (int)(finalLockArray.size() + (finalLockArray.size() * 0.5));
    std::cout << "---------------Welcome to Bulls and Cows!-----------\n\n";
    std::cout << "Your password is " << finalLockArray.size() << " letters!\n";
    std::cout << "You have " << plLives << " tries!\n";
    while (bullCount != 4)
    {
        if (plLives == 0)
        {
            std::cout << "\nYou lose! You have no lives available!\n";
            goto askUserAgain;
        }
        else
        {
            bullCount = 0;
            cowCount = 0;
            userInputArray.clear();

            std::cout << "Enter your password, with only a/b/c/d [fmt: x x x x]: ";
            std::cin >> c0 >> c1 >> c2 >> c3;
            if (!std::cin >> c0 >> c1 >> c2 >> c3)
            {
                throw std::runtime_error("Invalid input type!");
            }
 
            userInputArray.push_back(c0);
            userInputArray.push_back(c1);
            userInputArray.push_back(c2);
            userInputArray.push_back(c3);

            for (int i{ 0 }; i < finalLockArray.size(); ++i)
            {
                for (int j{ 0 }; j < finalLockArray.size(); ++j)
                {
                    if (userInputArray[i] == finalLockArray[j])
                    {
                        if (i == j)
                        {
                            bullCount++;
                            break;
                        }
                        else
                        {
                            cowCount++;
                        }
                    }
                }
            }
            if (bullCount != 4)
            {
                std::cout << "Bulls: " << bullCount << ".\n";
                std::cout << "Cows: " << cowCount << ".\n";
            }
            triesCount++;
            plLives--;
        }
    }

    std::cout << "\nCongrats! You cracked the password: ";
    DisplayPassword(finalLockArray);
    std::cout << ".\nIt took you " << triesCount << " tries to crack the password!\n";
askUserAgain:
    triesCount = 0; //triesCount used again to store user's y/n choice.
    std::cout << "Do you want to play again? (0/1): ";

    while (std::cin >> triesCount)
    {
        if (!std::cin >> triesCount)
        {
            throw std::runtime_error("Invalid input type!");
        }
        if (triesCount != 1 && triesCount != 0)
        {
            std::cout << "Please enter either 0 for y or 1 for no: ";
        }
        else
        {
            if (triesCount == 0)
            {
                std::cout << "\n";
                goto startGame;
            }
            else
            {
                return 0;
            }
        }
    }
}
catch (std::exception& e)
{
    std::cout << "Please run again! Runtime error: " << e.what();
    return 1;
}
catch (...)
{
    std::cout << "Unknown exception!!";
    return 2;
}