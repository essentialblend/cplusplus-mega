// There is an old story that the emperor wanted to thank the inventor of the game of chess and asked the inventor to name his reward. The inventor asked for one grain of rice for the first square, 2 for the second, 4 for the third, and so on, doubling for each of the 64 squares.That may sound modest, but there wasn’t that much rice in the empire! Write a program to calculate how many squares are required to give the inventor at least 1000 grains of rice, at least 1,000,000 grains, and at least 1,000,000,000 grains. You’ll need a loop, of course, and probably an int to keep track of which square you are at, an int to keep the number of grains on the current square, and an int to keep track of the grains on all previous squares. We suggest that you write out the value of all your variables for each iteration of the loop so that you can see what’s going on.

// Try to calculate the number of rice grains that the inventor asked for in exercise 8 above. You’ll find that the number is so large that it won’t fit in an int or a double. Observe what happens when the number gets too large to represent exactly as an int and as a double. What is the largest number of squares for which you can calculate the exact number of grains (using an int)? What is the largest number of squares for which you can calculate the approximate number of grains (using a double)?

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

int main()
{
    double grainValue{ 0 };
    std::string userInput{ 0 };
    std::cout << "Your majesty pays you in rice grains.. Press y to accept...";
    std::cin >> userInput;
    for (double i = 0; i <= 64; i++)
    {
        grainValue = std::powf(2, i);
        //std::cout << "\nGrain value at " << i << "th square: " << grainValue << ".\n";
        if (grainValue == 1024)
        {
            std::cout << "\nGrain value hit " << "1024 at square: " << i << ".\n";
        }
        if (grainValue == 1048576)
        {
            std::cout << "\nGrain value hit " << "1,048,576 at square: " << i << ".\n";
        }
        if (grainValue == 1073741824)
        {
            std::cout << "\nGrain value hit " << "1,073,741,824 at square: " << i << ".\n";
        }
    }
    return 0;
}