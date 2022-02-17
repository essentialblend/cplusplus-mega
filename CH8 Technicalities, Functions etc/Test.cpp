
#include <iostream>
#include <vector>
#include <algorithm>



void MyMethod(std::vector<int>& Vec1, int High)
{
    int SearchStart = 0;
    int SearchEnd = Vec1.size();
    int ArrayMid = (Vec1.size() / 2) - 1;

    std::sort(Vec1.begin(), Vec1.end());

    if (High > Vec1[ArrayMid])
    {
        SearchStart = ArrayMid + 1;
    }
    else
    {
        SearchStart = Vec1[0];
        SearchEnd = Vec1[ArrayMid];
    }

    for (int i = SearchStart; i < SearchEnd; ++i)
    {
        std::cout << Vec1[i] << "\n";
    }

}

int main()
{
    std::vector<int> Vec1{ 90, 80, 70, 60, 50, 40, 30, 20, 10, 1 };

    int High = 45;
    std::cout << "original array: \n";
    for (int a : Vec1)
    {
        std::cout << a << "\n";
    }
    
    MyMethod(Vec1, High);


    return 0;
}
