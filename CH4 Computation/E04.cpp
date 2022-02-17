// Write a program to play a numbers guessing game. The user thinks of a number between 1 and 100 and your program asks questions to figure out what the number is (e.g., “Is the number you are thinking of less than 50?”). Your program should be able to identify the number after asking no more than seven questions. Hint: Use the < and <=operators and the if-else construct.
// Credit to Benjamin Wuethrich / github - bewuethr for the logic/study reference.


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

inline void keep_window_open() { char ch; std::cin >> ch; }

int main()
{
    int guess = 50;
    std::vector<int> differences{ 25, 13, 6, 3, 2, 1 };
    int counter = 0;
    char answer = ' ';

    std::cout << "Think of a number between 1 and 100.\n";
    std::cout << "For every guess, enter if your number is (l)arger or (s)maller than the one shown.\n";
    std::cout << "Enter 'c' if the number is correctly guessed: ";
    std::cin >> answer;
    
    while (answer != 'c')
    {
        std::cout << "My guess is: " << guess << ".\n";
        std::cout << "Correct, larger or smaller(c, l, s)? : ";
        std::cin >> answer;
        counter++;
        switch (answer)
        {
        case 'c':
            break;
        case 'l':
            if (counter < differences.size())
            {
                guess += differences[counter - 1];
            }
            else
                ++guess;
            break;
        case 's':
            if (counter < differences.size())
            {
                guess -= differences[counter - 1];
            }
            else
                --guess;
            break;
        default:
            std::cout << "This is not a valid answer, use 'c', 'l' or 's'\n";
            --counter;
            break;
        }
        if (guess > 100 || guess < 1)
        {
            std::cout << "Your number has to be between 1 and 100.\n";
            return 0;
        }
        if (counter == 7 && answer != 'c')
        {
            std::cout << "Answer sadly not found. Retry while I fix my code......\n";
            return 0;
        }
    }

    std::string s_try;
    if (counter == 1)
        s_try = " try ";
    else
        s_try = " tries ";
    std::cout << "It took me " << counter << s_try << "to find your number, " << guess << ".\n";
}
