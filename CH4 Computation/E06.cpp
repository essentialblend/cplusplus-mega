// Make a vector holding the ten string values "zero", "one", . . ."nine". Use that in a program that converts a digit to its corresponding spelled-out value; e.g., the input 7 gives the output seven. Have the same program, using the same input loop, convert spelled - out numbers into their digit form; e.g., the input seven gives the output 7.

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::vector<std::string> answerArray{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    int userDigit{ 0 };
    char userChoice{ 0 };
    std::string userChoiceWord{ 0 };

    startPoint:
    std::cout << "Enter xx or invalid input to exit...\n";
    std::cout << "Do you want to *number to word* or *word to number*? [Enter 1 or 2]: ";

    while (std::cin >> userChoice)
    {
        switch (userChoice)
        {
        case '1':
            std::cout << "Enter a digit between 0 and 9: ";
            std::cin >> userDigit;
            if (userDigit >= 0 && userDigit <= 9)
            {
                std::cout << "Your digit " << userDigit << " converts to the word: " << answerArray[userDigit] << ".\n\n";
                goto startPoint; //goes to line 15.
            }
            else
            {
                std::cout << "Not between 0 and 9. Try again....\n";
                return 0;
            }
            break;
        case '2':
            std::cout << "Enter a number as a word between 0 and 9 in smallcaps: ";
            std::cin >> userChoiceWord;
            for (int i = 0; i < answerArray.size(); i++)
            {
                if (userChoiceWord == answerArray[i])
                {
                    std::cout << "Your word " << userChoiceWord << " converts to the digit: " << i << ".\n\n";
                    goto startPoint;
                }
                else return 0;
            }
            break;
        default:
            std::cout << "\nExiting program....\n";
            return 0;
        }
    }
}