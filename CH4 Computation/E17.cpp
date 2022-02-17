// Write a program that finds the min, max, and mode of a sequence of strings.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<std::string> stringArray{};

std::string ModeCalculator(std::vector<std::string> strArray, int size)
{
    int count{ 1 };
    int maxChecker{ 0 };
    std::string tempMode = strArray[0];

    for (int i{ 0 }; i < strArray.size() - 1; ++i)
    {

        if (strArray[i] == strArray[(double)i + 1])
        {
            count++;
            if (count > maxChecker)
            {
                maxChecker = count;
                tempMode = strArray[i];
            }
        }
        else
        {
            count = 1;
        }
    }

    return tempMode;
}

int main()
{
    std::string userString{};
    bool firstRun = true;
    std::string smallestS{};
    std::string largestS{};
    std::string finalMode{};

    std::cout << "Enter a bunch of strings: ";
    while (std::cin >> userString)
    {
        if (userString < smallestS || firstRun)
        {
            smallestS = userString;
        }
        if (userString > largestS || firstRun)
        {
            largestS = userString;
        }
        firstRun = false;
        stringArray.push_back(userString);
    }

    std::sort(stringArray.begin(), stringArray.end());
    finalMode = ModeCalculator(stringArray, stringArray.size());
    std::cout << "Min of the array: " << smallestS << ".\n";
    std::cout << "Max of the array: " << largestS << ".\n";
    std::cout << "Mode of the array: " << finalMode << ".\n";
}
