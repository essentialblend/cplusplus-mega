//  Implement a little guessing game called (for some obscure reason) “Bulls and Cows.” The program has a vector of four different integers in the range 0 to 9 (e.g., 1234 but not 1122) and it is the user’s task to discover those numbers by repeated guesses. Say the number to be guessed is 1234 and the user guesses 1359; the response should be “1 bull and 1 cow” because the user got one digit (1) right and in the right position (a bull) and one digit (3) right but in the wrong position (a cow). The guessing continues until the user gets four bulls, that is, has the four digits correct and in the correct order.
// The program is a bit tedious because the answer is hard-coded into the program. Make a version where the user can play repeatedly (without stopping and restarting the program) and each game has a new set of four digits. You can get four random digits by calling the random number generator randint(10) from std_lib_facilities.h four times. You will note that if you run that program repeatedly, it will pick the same sequence of four digits each time you start the program. To avoid that, ask the user to enter a number (any number) and call srand(n) where n is the number the user entered before calling randint(10). Such an n is called a seed, and different seeds give different sequences of random numbers.

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

std::vector<int> GeneratePassword()
{
    std::vector<int> decimalArray{ 0,1,2,3,4,5,6,7,8,9 };
    std::vector<int> solutionArray = decimalArray;
    auto timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    std::mt19937_64 timeVar(timeSeed);
    std::shuffle(solutionArray.begin(), solutionArray.end(), timeVar);
    solutionArray.resize(4);
    return solutionArray;
}

void DisplayPassword(std::vector<int> tempArray)
{
    for (int x : tempArray)
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
    int c0{ 0 };
    int c1{ 0 };
    int c2{ 0 };
    int c3{ 0 };
    std::vector<int> finalLockArray = GeneratePassword();
    std::vector<int> userInputArray{};
    int triesCount{ 0 };
    int diffLevel{ 0 };
    int plLives{ 10 };

    plLives = finalLockArray.size() + (finalLockArray.size() * 0.5);
    std::cout << "---------------Welcome to Bulls and Cows!-----------\n\n";
    std::cout << "Your password is " << finalLockArray.size() << " digits!\n";
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

            std::cout << "Enter your guess [fmt: x x x x]: ";
            std::cin >> c0 >> c1 >> c2 >> c3;
            if (!std::cin >> c0 >> c1 >> c2 >> c3)
            {
                throw std::runtime_error("Invalid input type!");
            }
            if (c0 < 0 || c1 < 0 || c2 < 0 || c3 < 0)
            {
                throw std::runtime_error("Negative input(s)!");
            }
            if (c0 > 9 || c1 > 9 || c2 > 9 || c3 > 9)
            {
                throw std::runtime_error("Input(s) greater than 9!");
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