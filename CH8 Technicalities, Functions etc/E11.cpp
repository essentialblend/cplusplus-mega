/*E11 - Write a function that finds the smallest and the largest element of a vector argument and also computes the mean and the median. Do not use global variables. Either return a struct containing the results or pass them back through reference arguments. Which of the two ways of returning several result values do you prefer and why?*/

#include <iostream>
#include <vector>
#include <algorithm>

struct VectorProperties
{
    double MinValue{ 0 };
    double MaxValue{ 0 };
    double MeanValue{ 0 };
    double MedianValue{ 0 };

    VectorProperties() : MinValue(0), MaxValue(0), MeanValue(0), MedianValue(0) {}

    void MinFromVector(const std::vector<double>& UArray)
    {
        double MinimumValue = UArray[0];

        for (double TVal : UArray)
        {
            if (TVal < MinimumValue)
                MinimumValue = TVal;
        }
        this->MinValue = MinimumValue;
    }

    void MaxFromVector(const std::vector<double>& UArray)
    {
        double MaximumValue = UArray[0];

        for (double TVal : UArray)
        {
            if (TVal > MaximumValue)
                MaximumValue = TVal;
        }
        this->MaxValue = MaximumValue;
    }

    void MeanFromVector(const std::vector<double>& UArray)
    {
        if (UArray.size() == 0) throw std::runtime_error("Empty array exception.");
        double MeanVal{ 0 };
        for (double TVal : UArray)
        {
            MeanVal += TVal;
        }
        MeanValue = MeanVal / UArray.size();
    }

    void MedianFromVector(std::vector<double>& UArray) 
    {
        /*Modifies the element order. Doesn't matter as it executes last.*/
        std::sort(UArray.begin(), UArray.end());

        if (UArray.size() % 2 == 0)
        {
            long long PVal = (UArray.size() / 2) - 1;
            MedianValue = (UArray[PVal] + UArray[PVal + 1]) / 2;
        }
        else if (UArray.size() % 2 != 0)
        {
            long long PVal = ((UArray.size() + 1) / 2) - 1;
            MedianValue = UArray[PVal];
        }
    }

    void PerformAllComputations(std::vector<double>& UArray)
    {
        MinFromVector(UArray);
        MaxFromVector(UArray);
        MeanFromVector(UArray);
        MedianFromVector(UArray);
    }
};

int main()
try
{
    VectorProperties VPObject;
    std::vector<double> UserArray;
    int NumArrayChoice{ 0 };
    double UserInput{ 0 };
    std::cout << "Number of elements (1 - 20)"; /*20 was randomly picked.*/
    if (!(std::cin >> NumArrayChoice || NumArrayChoice == 0)) throw std::runtime_error("Invalid input. Enter a number between 1-20.");

    for (int i{ 0 }; i < NumArrayChoice; i++)
    {
        std::cout << "Enter a number: ";
        if (!(std::cin >> UserInput)) throw std::runtime_error("Invalid input.");
        UserArray.push_back(UserInput);
    }

    VPObject.PerformAllComputations(UserArray);

    std::cout << "\nMIN value in your double array: " << VPObject.MinValue << ".\n";
    std::cout << "MAX value in your double array: " << VPObject.MaxValue << ".\n";
    std::cout << "MEAN value in your double array: " << VPObject.MeanValue << ".\n";
    std::cout << "MEDIAN value in your double array: " << VPObject.MedianValue << ".\n";
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