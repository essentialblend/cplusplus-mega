/*E07 - Read five names into a vector<string> name, then prompt the userfor the ages of the people named and store the ages in a vector<double> age. Then print out the five (name[i],age[i])pairs. Sort the names (sort(name.begin(),name.end())) and printout the (name[i],age[i]) pairs. The tricky part here is to get the age vector in the correct order to match the sorted name vector. Hint: Before sorting name, take a copy and use that to make a copy of agein the right order after sorting name. Then, do that exercise again but allowing an arbitrary number of names.*/

#include <iostream>
#include <vector>

int main()
try
{
    std::vector<std::string> NameArray;
    std::vector<double> AgeArray;
    int NameCount{ 0 };
    std::string UserInputString{ " " };
    double UserInputAge{ 0 };

    std::cout << "How many elements in array?... ";
    if (!(std::cin >> NameCount || NameCount > 100 || NameCount == 0))
        throw std::runtime_error("Invalid input, please enter a number between 1-100.");

    for (int i{ 0 }; i < NameCount; i++)
    {
        std::cout << "Enter name " << (i + 1) << ": ";
        if (!(std::cin >> UserInputString)) throw std::runtime_error("Invalid input. Please enter a string.");
        NameArray.push_back(UserInputString);
    }

    for (int i{ 0 }; i < NameArray.size(); i++)
    {
        std::cout << "Enter " << NameArray[i] << "'s age: ";
        if (!(std::cin >> UserInputAge)) throw std::runtime_error("Invalid input. Please enter a double.");
        AgeArray.push_back(UserInputAge);
    }

    for (int i{ 0 }; i < NameArray.size(); i++)
    {
        std::cout << "Name / Age: " << NameArray[i] << " / " << AgeArray[i] << ".\n";
    }
    
    return 0;
}
catch (std::exception& exc)
{
    std::cout << "Runtime error: " << exc.what() << "\n";
    return 1;
}
catch (...)
{
    std::cout << "Unknown exception.\n";
    return 2;
}