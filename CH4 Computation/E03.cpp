// Read a sequence of double values into a vector. Think of each value as the distance between two cities along a given route. Compute and print the total distance (the sum of all distances). Find and print the smallest and greatest distance between two neighboring cities. Find and print the mean distance between two neighboring cities.

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<double> arrayDistances{};
    double tempValue{ 0 };
    double smallest{ 0 };
    double biggest{ 0 };
    double sum{ 0 };
    double mean{ 0 };
    bool firstRun{ true };

    std::cout << "Enter a value: ";

    while (std::cin >> tempValue)
    {
        if (tempValue <= 0 || tempValue >= 2000000)
        {
            std::cout << "Invalid distance.\n";
            std::cout << "-------- STATS --------\n";
            std::cout << "The sum of all distances: " << sum << ".\n";
            std::cout << "The smallest distance: " << smallest << ".\n";
            std::cout << "The biggest distance: " << biggest << ".\n";
            std::cout << "The mean distance: " << mean << ".\n\n";
            break;
        }
        else
        {
            if (firstRun)
            {
                smallest = tempValue;
                biggest = tempValue;
                firstRun = false;
            }
            arrayDistances.push_back(tempValue);
            std::sort(arrayDistances.begin(), arrayDistances.end());
            sum += tempValue;

            if (tempValue < smallest) (smallest = tempValue);
            if (tempValue > biggest) (biggest = tempValue);
            mean = sum / arrayDistances.size();
        }
        if (arrayDistances.size() == 0)
        {
            std::cout << "No elements in the array.\n";
        }
        std::cout << "-------- STATS --------\n";
        std::cout << "The sum of all distances: " << sum << ".\n";
        std::cout << "The smallest distance: " << smallest << ".\n";
        std::cout << "The biggest distance: " << biggest << ".\n";
        std::cout << "The mean distance: " << mean << ".\n\n";
        std::cout << "Enter a value: ";
    }
    return 0;    
}