// Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22. For each pair, add the name to a vector called names and the number to a vector called scores (in corresponding positions, so that if names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.

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
    return 0;
}