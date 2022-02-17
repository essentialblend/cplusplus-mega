// Modify the program from exercise 19 so that when you enter a name, the program will output the corresponding score or name not found.

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::string userName{};
    int userNum{ 0 };
    int counter{ 0 };
    bool firstRun = true;
    std::vector<std::string> nameArr{};
    std::vector<int> numArr{};

    std::cout << "Enter a (string)name and (int)value pair: ";
    while (std::cin >> userName >> userNum)
    {
        if (firstRun)
        {
            firstRun = false;
            nameArr.push_back(userName);
            numArr.push_back(userNum);
            std::cout << "Enter a (string)name and (int)value pair: ";
        }
        else if (userName == "NoName" && userNum == 0)
        {
            break;
        }
        else if (userName == nameArr[counter])
        {
            std::cout << "ERROR: " << nameArr[counter] << " was entered twice.\n";
            //Display list.
            break;
        }
        else
        {
            counter++;
            nameArr.push_back(userName);
            numArr.push_back(userNum);
            std::cout << "Enter a (string)name and (int)value pair: ";
        }
    }
    std::cout << "\nThe pairs are: \n";
    for (int i{ 0 }; i < nameArr.size(); ++i)
    {
        std::cout << (i + 1) << ": " << nameArr[i] << " : " << numArr[i] << "..\n";
    }

    //E20
    std::cout << "Enter a name: ";
    while (std::cin >> userName)
    {
        for (int i{ 0 }; i <= nameArr.size(); ++i) // > and = as a simple trick to control flow)
        {
            if (i == nameArr.size())
            {
                std::cout << "Name not found!\n";
                std::cout << "Enter a name: ";
                break;
            }
            else if (nameArr[i] == userName)
            {
                std::cout << "The name is " << nameArr[i] << " & the score is: " << numArr[i] << ".\n";
                std::cout << "Enter a name: ";
                break;
            } 
        }
    }
    return 0;
}