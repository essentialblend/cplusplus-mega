/*E09 (should be 8, typing error in the book) - Write a function that given two vector<double>s price and weight computes a value (an “index”) that is the sum of all price[i]*weight[i]. Make sure to have weight.size()==price.size()..*/

#include <iostream>
#include <vector>

int main()
try
{
    std::vector<double> PriceArray;
    std::vector<double> WeightArray;
    double PriceInput{ 0 };
    double WeightInput{ 0 };
    double IndexResult{ 0 };
    int UserChoice{ 0 };
    std::cout << "How many values do you want to enter [1 - 100]?... ";
    if (!(std::cin >> UserChoice) || UserChoice <= 0)
        throw std::runtime_error("0 or invalid array-size choice. Please enter a number greater than 0 and less than 101.");
    for (int i{ 0 }; i < UserChoice; i++)
    {
        std::cout << "Enter a fmt[price weight]: ";
        if (!(std::cin >> PriceInput >> WeightInput) || (PriceInput < 0 || WeightInput < 0))
            throw std::runtime_error("Invalid Price / Weight input.");
        PriceArray.push_back(PriceInput);
        WeightArray.push_back(WeightInput);
    }
    for (int i{ 0 }; i < PriceArray.size(); i++)
    {
        IndexResult += PriceArray[i] * WeightArray[i];
    }
    std::cout << "Price * Weight: " << IndexResult << ".\n";
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