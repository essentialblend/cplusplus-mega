// E02 The following program takes in a temperature value in Celsius and converts it to Kelvin. This code has many errors in it. Find the errors, list them, and correct the code.

// E03 Absolute zero is the lowest temperature that can be reached; it is –273.15°C, or 0K. The above program, even when corrected, will produce erroneous results when given a temperature below this. Place a check in the main program that will produce an error if a temperature is given below –273.15°C.

// E04 Do exercise 3 again, but this time handle the error inside ctok().

// E05 Add to the program so that it can also convert from Kelvin to Celsius.

#include <iostream>

double ctok(double c)
{
    /*E04
    if (c < -273.15)
    {
        throw std::runtime_error("Temp below -273.15C.");
    }*/
    
    double k = c + 273.15;
    return k;
}

//E05
double ktoc(double k)
{
    if (k < 0)
    {
        throw std::runtime_error("Temp below absolute zero.");
    }

    double c = k - 273.15;
    return c;
}

int main()
{
    try
    {
        double c = 0;
        std::cin >> c;
        
        /*E03
        if (c < -273.15)
        {
            throw std::runtime_error("Temp below -273.15C");
        }*/

        double k = ctok(c);
        std::cout << k << '\n';
    }
    catch (std::exception& e)
    {
        std::cout << "Runtime error: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        std::cout << "Unknown exception!!\n";
        return 2;
    }
    return 0;
}