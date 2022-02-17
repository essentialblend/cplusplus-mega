/*E03 - Create a vector of Fibonacci numbers and print them using the function from exercise 2. To create the vector, write a function, fibonacci(x,y,v,n), where integers x and y are ints, v is an emptyvector<int>, and n is the number of elements to put into v; v[0] will be x and v[1] will be y. A Fibonacci number is one that is part of a sequence where each element is the sum of the two previous ones. For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, . . . . Yourfibonacci() function should make such a sequence starting with its xand y arguments.
  E04 - An int can hold integers only up to a maximum number. Find an approximation of that maximum number by using fibonacci().*/

#include <iostream>
#include <vector>
#define OUT 

void CalculateFibonacci(const int& TempA, const int& TempB, OUT std::vector<int>& FibArray, const int& GenerateUptoValue)
{
    FibArray.push_back(TempA);
    FibArray.push_back(TempB);
    while (GenerateUptoValue > FibArray.size())
    {
        FibArray.push_back(FibArray[FibArray.size() - 1] + FibArray[FibArray.size() - 2]);
    }
}

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
    int UserChoice{ 0 };
    int OneV{ 1 };
    int TwoV{ 2 };
    std::vector<int> FinalFibArray;
    std::string OutputLabel{ " " };
    std::cout << "Enter n to generate up to 20 Fibonacci's: ";
    std::cin >> UserChoice;
    if (UserChoice < 1 || UserChoice > 20)
    {
        throw std::runtime_error("Please enter a number between 1 and 20.");
    }
    std::cout << "Enter a suitable label: ";
    std::cin >> OutputLabel;
    if (!std::cin)
    {
        throw std::runtime_error("Please enter a suitable string label.");
    }
    CalculateFibonacci(OneV, TwoV, FinalFibArray, UserChoice);
    PrintVectorOfInts(OutputLabel, FinalFibArray);
    CalculateBiggestInt(OneV, TwoV, FinalFibArray, UserChoice);
    //std::cout << "\n Biggest int: " << FinalFibArray[FinalFibArray.size() - 1];
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

