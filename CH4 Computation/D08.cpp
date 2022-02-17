// Reject values without units or with “illegal” representations of units, such as y, yard, meter, km, and gallons.

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
    else if (unit == "cm")
    {
        cmValue = value;
        std::cout << "You entered " << value << "cm.\n";
        std::cout << "Converted to " << cmValue << "cm.\n\n";
    }
    else
    {
        cmValue = 0;
        std::cout << "Invalid unit!\n\n";
        std::cout << "Enter a number with unit [cm,m,in,ft] [terminate with '|']: ";
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