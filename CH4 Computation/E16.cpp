// In the drill, you wrote a program that, given a series of numbers, found the max and min of that series. The number that appears the most times in a sequence is called the mode. Create a program that finds the mode of a set of positive integers.

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> numArray{ 2,5,3,6,7,5,4,2,1,5,9,8,9,1,2,5,8,9,0,1,10,25,4,33,53,63,34 };
std::vector<int> modeArray{};

int CalculateMode(std::vector<int> array, int size)
{
    int max{ 0 };
    int count{ 1 };
    int mode = array[0];

    for (int i{ 0 }; i < size - 1; ++i)
    {
        if (array[i] == array[(double)i + 1])
        {
            count++;
            if (count > max)
            {
                max = count;
                mode = array[i];
            }
        }
        else
        {
            count = 1;
        }
    }
    return mode;
}

int main()
{
    std::sort(numArray.begin(), numArray.end());
    std::cout << "Sorted array: ";
    for (int i{ 0 }; i < numArray.size(); i++)
    {
        std::cout << numArray[i] << ", ";
    }
    std::cout << "\nThe mode is: " << CalculateMode(numArray, numArray.size()) << ".\n";
}