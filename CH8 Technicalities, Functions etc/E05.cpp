/*E05 - Write two functions that reverse the order of elements in a vector<int>. For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse function should produce a new vector with the reversed sequence, leaving its original vector unchanged. The other reverse function should reverse the elements of its vector without using anyother vectors (hint: swap).*/

#include <iostream>
#include <vector>

std::vector<int> Swap_ProduceNewRetainOld(const std::vector<int>& InputVector)
{
    std::vector<int> NewReturnVector;
    for (int i = InputVector.size() - 1; i >= 0; i--)
    {
        NewReturnVector.push_back(InputVector[i]);
    }
    return NewReturnVector;
}

void Swap_ModifyOld(std::vector<int>& InputVector)
{
    for (int i{ 0 }; (i < InputVector.size() / 2); i++)
    {
        std::swap(InputVector[i], InputVector[InputVector.size() - 1 - i]);
    }
}

/*E06 - Write versions of the functions from exercise 5, but with a vector<string>. Starts with SwapString_FunctionName.*/
std::vector<std::string> SwapString_ProduceNewRetainOld(const std::vector<std::string>& InputVector)
{
    std::vector<std::string> NewReturnVector;
    for (int i = InputVector.size() - 1; i >= 0; i--)
    {
        NewReturnVector.push_back(InputVector[i]);
    }
    return NewReturnVector;
}

void SwapString_ModifyOld(std::vector<std::string>& InputVector)
{
    for (int i{ 0 }; (i < InputVector.size() / 2); i++)
    {
        std::swap(InputVector[i], InputVector[InputVector.size() - 1 - i]);
    }
}

int main()
try
{
    std::vector<int> ArrayToReverse;
    std::string UserInputString;
    std::vector<std::string> StringArrayToReverse;
    int UserInput{ 0 };
    char FinalChoice;

    std::cout << "Enter some numbers to reverse, terminate with a '0': ";
    while (std::cin >> UserInput && UserInput != 0)
    {
        ArrayToReverse.push_back(UserInput);
    }
    std::cout << "Original array: ";
    for (auto TempInt : ArrayToReverse)
    {
        std::cout << TempInt << " ";
    }
    std::cout << "\nDo you want to Swap_ProduceNewRetainOld [1] or Swap_RetainOld? [2]? ";
    std::cin >> FinalChoice;
    std::cout << "Reversed Array: ";
    switch (FinalChoice)
    {
    case '1':
    {
        std::vector<int> DisplayArray{ Swap_ProduceNewRetainOld(ArrayToReverse) };
        for (int TempInt : DisplayArray)
        {
            std::cout << TempInt << " ";
        }
        break;
    }   
    case '2':
    {
        Swap_ModifyOld(ArrayToReverse);
        for (int TempInt : ArrayToReverse)
        {
            std::cout << TempInt << " ";
        }
        break;
    }
    default:
        throw std::runtime_error("Invalid choice. Pick between 1 and 2.");
    }
    
    return 0;
}
catch (std::exception& exc)
{
    std::cout << "Runtime Error: " << exc.what() << "\n";
    return 1;
}
catch (...)
{
    std::cout << "Unknown exception!\n";
    return 2;
}