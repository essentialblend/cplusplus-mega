/*IE09: Read digits from input and compose them into
integers. Handle number with one to four digits.
Hint: '5'-'0' == 5 (get integer value of character)*/
#include <iostream>
#include <vector>

std::vector<std::string> WordArray{ "thousand", "hundred", "ten", "one" };

int ConvertCharToInt(std::vector<int> TempVector)
{
    if (TempVector.size() == 0)
    {
        throw std::runtime_error("Empty array was provided to Char->Int Array function.");
    }
    if (TempVector.size() > 4)
    {
        throw std::runtime_error("Char->Int function can only handle upto 4 digits.");
    }
    int TempInt{ 0 };
    for (int i{ 0 }; i < TempVector.size(); i++)
    {
        TempInt = (10 * TempInt) + TempVector[i];
    }
    return TempInt;
}

void HandlePlurals(int TempInt)
{
    if (TempInt == 0 || TempInt > 1) std::cout << "s";
    if (TempInt == 1) return;
    if (TempInt < 0) throw std::runtime_error("HandlePlurals() can only handle +ve numbers.");
}

void PrintResult(std::vector<int> TempVec, int UNum)
{
    if (UNum > 9999)
    {
        throw std::runtime_error("PrintResult() can only handle upto 4 digits.");
    }
    if (TempVec.size() == 0)
    {
        throw std::runtime_error("PrintResult() was handed an empty number.");
    }
    std::cout << UNum << " is: ";
    for (int i{ 0 }; i < TempVec.size(); i++)
    {
        std::cout << TempVec[i] << " " << WordArray[(double)i + 4 - TempVec.size()];
        HandlePlurals(TempVec[i]);
        if (i < (TempVec.size() - 1))
        {
            std::cout << " and ";
        }
    }
    std::cout << ".\n";
}

int main()
try
{
    std::vector<int> CharUserInput;
    char UserChar{ ' ' };
    std::cout << "Enter (up to a 4) digit number: ";
    while (true)
    {
        while (std::cin >> UserChar)
        {
            if (UserChar == 'q') return 0;
            if (UserChar < '0' || UserChar > '9')
            {
                std::cin.ignore(10000, '\n');
                break;
            }
            CharUserInput.push_back(UserChar - '0');
        }
        int BufferInt = ConvertCharToInt(CharUserInput);
        PrintResult(CharUserInput, BufferInt);
        std::cout << "Try again...: ";
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
    std::cout << "Unknown exception!\n";
    return 2;
}

