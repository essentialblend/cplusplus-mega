// Keep track of the sum of values entered (as well as the smallest and the largest) and the number of values entered. When the loop ends, print the smallest, the largest, the number of values, and the sum of values. Note that to keep the sum, you have to decide on a unit to use for that sum; use meters.

#include <iostream>
#include <vector>

double ConvertMeters(double value, std::string unit)
{
    double meterValue{ 0 };

    if (unit == "m")
    {
        meterValue = value * 1;
        std::cout << "You entered " << value << "m.\n";
        std::cout << "Converted to " << meterValue << "m.\n\n";
    }
    else if (unit == "in")
    {
        meterValue = value * 0.0254;
        std::cout << "You entered " << value << "in.\n";
        std::cout << "Converted to " << meterValue << "m.\n\n";
    }
    else if (unit == "ft")
    {
        meterValue = value * 0.3048;
        std::cout << "You entered " << value << "ft.\n";
        std::cout << "Converted to " << meterValue << "m.\n\n";
    }
    else if (unit == "cm")
    {
        meterValue = value * 0.01;
        std::cout << "You entered " << value << "cm.\n";
        std::cout << "Converted to " << meterValue << "m.\n\n";
    }
    else
    {
        meterValue = 0;
        std::cout << "Invalid unit!\n\n";
        std::cout << "Enter a number with unit [cm,m,in,ft] [terminate with '|']: ";
    }

    return meterValue;
}

double SumFunction(std::vector<double> arrayN)
{
    double additionValue{ 0 };
    for (int i{ 0 }; i < arrayN.size(); i++)
    {
        additionValue = additionValue + arrayN[i];
    }
    return additionValue;
}

int main()
{
    double valOne{ 0 };
    double bigNum{ 0 };
    double smallNum{ 0 };
    std::string numUnit{ 0 };
    double convertedValue{ 0 };
    double tempNum{ 0 };
    std::vector<double> arrayNums{};

    std::cout << "Enter a number with unit [cm,m,in,ft] [terminate with '|']: ";
    while (std::cin >> valOne >> numUnit)
    {
        convertedValue = ConvertMeters(valOne, numUnit);
        arrayNums.push_back(convertedValue);
        if (tempNum == 0)
        {
            bigNum = convertedValue;
            smallNum = convertedValue;
            std::cout << "Enter one number [terminate with '|']: ";
            tempNum++;
        }
        else if (convertedValue > bigNum)
        {
            bigNum = convertedValue;
            std::cout << "Enter one number [terminate with '|']: ";
        }
        else if (convertedValue < smallNum)
        {
            smallNum = convertedValue;
            std::cout << "Enter one number [terminate with '|']: ";
        }
        else
        {
            std::cout << "No change.\n\n";
            std::cout << "Enter one number [terminate with '|']: ";
        }
    }
    std::cout << "\nSmallest number: " << smallNum << ".\n";
    std::cout << "Largest number: " << bigNum << ".\n";
    std::cout << "Number of elements in array: " << arrayNums.size() << ".\n";
    std::cout << "Sum of all elements in the array: " << SumFunction(arrayNums) << " meters.\n";

    return 0;
}