// Add a unit to each double entered; that is, enter values such as 10cm, 2.5in, 5ft, or 3.33m. Accept the four units: cm, m, in, ft. Assume conversion factors 1m == 100cm, 1in == 2.54cm, 1ft ==12in. Read the unit indicator into a string. You may consider 12 m (with a space between the number and the unit) equivalent to 12m (without a space).

#include <iostream>

double ConvertFunction(double value, std::string unit)
{

    int cmValue{ 0 };
    if (unit == "m")
    {
        cmValue = value * 100;
        std::cout << "You entered " << value << "m.\n";
        std::cout << "Converted to " << cmValue << "cm.\n\n";
    }
    else if (unit == "in")
    {
        cmValue = value * 2.54;
        std::cout << "You entered " << value << "in.\n";
        std::cout << "Converted to " << cmValue << "cm.\n\n";
    }
    else if (unit == "ft")
    {
        cmValue = value * (12 * 2.54);
        std::cout << "You entered " << value << "ft.\n";
        std::cout << "Converted to " << cmValue << "cm.\n\n";
    }
    else
    {
        cmValue = value;
        std::cout << "You entered " << value << "cm.\n";
        std::cout << "Converted to " << cmValue << "cm.\n\n";
    }
    return cmValue;
}

int main()
{
    double valOne{ 0 };
    double bigNum{ 0 };
    double smallNum{ 0 };
    std::string numUnit{ 0 };
    double convertedValue{ 0 };
    double tempNum{ 0 };

    std::cout << "Enter a number with unit [cm,m,in,ft] [terminate with '|']: ";
    while (std::cin >> valOne >> numUnit)
    {
        convertedValue = ConvertFunction(valOne, numUnit);
        if (tempNum == 0)
        {
            bigNum = convertedValue;
            smallNum = convertedValue;
            std::cout << convertedValue << " is biggest yet.\n";
            std::cout << convertedValue << " is smallest yet.\n\n";
            std::cout << "Enter one number [terminate with '|']: ";
            tempNum++;
        }
        else if (convertedValue > bigNum)
        {
            bigNum = convertedValue;
            std::cout << bigNum << " is biggest yet.\n\n";
            std::cout << "Enter one number [terminate with '|']: ";
        }
        else if (convertedValue < smallNum)
        {
            smallNum = convertedValue;
            std::cout << smallNum << " is smallest yet.\n\n";
            std::cout << "Enter one number [terminate with '|']: ";
        }
        else
        {
            std::cout << "No change.\n\n";
            std::cout << "Enter one number [terminate with '|']: ";
        }
    }
    return 0;
}