/*E04 - <Name_Value> Pairs.*/

#include <iostream>
#include <vector>

class Name_Value
{
public:
    std::string MName{ " " };
    int MValue{ 0 };
    Name_Value(std::string TName, int TValue) : MName(TName), MValue(TValue) {}
};

int main()
try
{
    std::cout << "Enter name / value pairs: ";
    std::vector<Name_Value> NVPairs;
    std::string MainName = "";
    int MainValue{ -1 };

    while ((std::cin >> MainName >> MainValue) && !(MainName == "NoName" && MainValue == 0))
    {
        for (int i = 0; i < NVPairs.size(); ++i)
            if (MainName == NVPairs[i].MName)
            {
                throw std::runtime_error("Name Duplication!");
            }
        NVPairs.push_back(Name_Value(MainName, MainValue));
    }

    for (int i{ 0 }; i < NVPairs.size(); i++)
    {
        std::cout << "Name: " << NVPairs[i].MName << " & " << "Value: " << NVPairs[i].MValue << ".\n";
    }

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

