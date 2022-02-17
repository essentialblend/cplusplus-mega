/*E02 - Write a function print() that prints a vector of ints to cout. Give it two arguments: a string for “labeling” the output and a vector.*/

#include <iostream>
#include <vector>

void PrintVectorOfInts(std::string& OutputLabel, std::vector<int>& VectorToPrint)
{
    std::cout << OutputLabel << "{ ";
    for (int i{ 0 }; i < VectorToPrint.size(); i++)
    {
        if (i == (VectorToPrint.size() - 1))
        {
            std::cout << VectorToPrint[i];
        }
        else
        {
            std::cout << VectorToPrint[i] << ", ";
        }
    }
    std::cout << " }\n";
}

int main()
try
{
    std::vector<int> UserVector{ 1,2,3,4,5 };
    std::string OutputLabel{ "Node" };
    PrintVectorOfInts(OutputLabel, UserVector);
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

