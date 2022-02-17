// Write a program that plays the game “Rock, Paper, Scissors.” If you are not familiar with the game do some research (e.g., on the webusing Google). Research is a common task for programmers. Use a switch-statement to solve this exercise. Also, the machine should give random answers (i.e., select the next rock, paper, or scissors randomly). Real randomness is too hard to provide just now, so just build a vector with a sequence of values to be used as “the next value.” If you build the vector into the program, it will always play the same game, so maybe you should let the user enter some values. Try variations to make it less easy for the user to guess which move the machine will make next.

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

std::vector<int> piArray{ 3,1,4,1,5,9,2,6,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9 };
int indexValue{ 0 };

int piDigitsRandom()
{
    if (indexValue >= piArray.size()) indexValue == 3; //Random index assigned out of laziness.
    int res{ 0 };
    res = piArray[indexValue] % 3;
    indexValue++;
    return res;
}

void compSeed(int seed)
{
    int temp{ 0 };
    for (int i = 0; i < seed; i++)
    {
        temp = piDigitsRandom();
    }
    std::cout << "\nDebug: Starting value within the pi array: " << temp << ".\n";
}

bool AskForRematch(int pScore, int cScore, std::string winString, std::vector<std::string> RPSArray, int p1In, int p2In)
{
    std::string pInput{ 0 };
    std::cout << winString << " You chose " << RPSArray[p1In] << " & I chose " << RPSArray[p2In] << ".\n";
    std::cout << "You (Player): " << pScore << " -- " << "Me (AI): " << cScore << ".\n";
    std::cout << "Do you want to play again (y/n)?...";
    std::cin >> pInput;
    if (pInput == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::vector<std::string> rpsArray{ "ROCK", "PAPER", "SCISSORS" };
    std::string p1InputS{ 0 };
    std::string winString{ "I WIN!!" };
    int p1InputN{ 0 };
    int playerSeed{ 0 };
    int playerScore{ 0 };
    int computerScore{ 0 };
    int AIpick{ 0 };
    gameSetup:
    std::cout << "\nRock, Paper, Scissors!\n";
    std::cout << "Enter a seed: ";
    std::cin >> playerSeed;
    
    compSeed(playerSeed);
    gameStart:
    std::cout << "\nMake your play: [rock / paper / scissors]: ";
    while (std::cin >> p1InputS)
    {
        //Player makes a move.
        if (p1InputS == "Rock" || p1InputS == "rock" || p1InputS == "r")
        {
            p1InputN = 0;
        }
        else if (p1InputS == "Paper" || p1InputS == "paper" || p1InputS == "p")
        {
            p1InputN = 1;
        }
        else if (p1InputS == "Scissors" || p1InputS == "scissors" || p1InputS == "s")
        {
            p1InputN = 2;
        }
        else
        {
            std::cout << "Invalid Input!!!\n";
            goto gameStart;
        }
        //Computer move.
        AIpick = piDigitsRandom();
        //Draw.
        if ((p1InputN == 0 && AIpick == 0) || (p1InputN == 1 && AIpick == 1) || (p1InputN == 2 && AIpick == 2))
        {
            winString = "IT'S A DRAW!!";
            if (AskForRematch(playerScore, computerScore, winString, rpsArray, p1InputN, AIpick))
            {
                goto gameSetup;
            }
            else
                break;
        }
        //P1 - R CPU - P
        else if (p1InputN == 0 && AIpick == 1)
        {
            computerScore++;
            if (AskForRematch(playerScore, computerScore, winString, rpsArray, p1InputN, AIpick))
            {
                goto gameSetup;
            }
            else
                break;
        }
        //P1 - P CPU - S
        else if (p1InputN == 1 && AIpick == 2)
        {
            computerScore++;
            if (AskForRematch(playerScore, computerScore, winString, rpsArray, p1InputN, AIpick))
            {
                goto gameSetup;
            }
            else
                break;
        }
        //P1 - S CPU - R
        else if (p1InputN == 2 && AIpick == 0)
        {
            computerScore++;
            if (AskForRematch(playerScore, computerScore, winString, rpsArray, p1InputN, AIpick))
            {
                goto gameSetup;
            }
            else
                break;
        }
        else
        {
            playerScore++;
            winString = "YOU WIN!!";
            if (AskForRematch(playerScore, computerScore, winString, rpsArray, p1InputN, AIpick))
            {
                goto gameSetup;
            }
            else
                break;
        }
    }
}

