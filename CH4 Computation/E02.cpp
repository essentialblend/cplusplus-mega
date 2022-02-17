// If we define the median of a sequence as “a number so that exactly as many elements come before it in the sequence as come after it,” fix the program in 4.6.3 so that it always prints out a median. Hint: A median need not be an element of the sequence.

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<double> tempVector{};
    double value{ 0 };
    double medianTemp{ 0 };
    std::cout << "Enter a temp value to store: ";
    
    while (std::cin >> value)
    {
        tempVector.push_back(value);
        std::sort(tempVector.begin(), tempVector.end());

        if (tempVector.size() % 2 == 0)
        {
            medianTemp = tempVector[tempVector.size() / 2] + tempVector[(tempVector.size() + 2) / 2];
            std::cout << "The median of the array is: " << medianTemp << ".\n";
        }
        else
        {
            medianTemp = tempVector[(tempVector.size() + 1) / 2];
            std::cout << "The median of the array is: " << medianTemp << ".\n";
        }
    }
    return 0;
}