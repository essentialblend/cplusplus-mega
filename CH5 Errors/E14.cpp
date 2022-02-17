// Read (day-of-the-week,value) pairs from standard input. Collect all the values for each day of the week in a vector<int>. Write out the values of the seven day-of-the-week vectors. Print out the sum of the values in each vector. Ignore illegal days of the week, such as Funday, but accept common synonyms such as Mon and monday. Write out the number of rejected values.

#include <iostream>
#include <vector>

std::vector<int> monArr{};
std::vector<int> tueArr{};
std::vector<int> wedArr{};
std::vector<int> thuArr{};
std::vector<int> friArr{};
std::vector<int> satArr{};
std::vector<int> sunArr{};
int rejectedDays{ 0 };

int SortPairs(std::string dayStr, int dayVal)
{
    int contStr = 0;

    if (dayStr == "Monday" || dayStr == "monday" || dayStr == "Mon" || dayStr == "mon")
    {
        monArr.push_back(dayVal);
    }
    else if (dayStr == "Tuesday" || dayStr == "tuesday" || dayStr == "Tue" || dayStr == "tue")
    {
        tueArr.push_back(dayVal);
    }
    else if (dayStr == "Wednesday" || dayStr == "wednesday" || dayStr == "Wed" || dayStr == "wed")
    {
        wedArr.push_back(dayVal);
    }
    else if (dayStr == "Thursday" || dayStr == "thursday" || dayStr == "Thu" || dayStr == "thu")
    {
        thuArr.push_back(dayVal);
    }
    else if (dayStr == "Friday" || dayStr == "friday" || dayStr == "Fri" || dayStr == "fri")
    {
        friArr.push_back(dayVal);
    }
    else if (dayStr == "Saturday" || dayStr == "saturday" || dayStr == "Sat" || dayStr == "sat")
    {
        satArr.push_back(dayVal);
    }
    else if (dayStr == "Sunday" || dayStr == "sunday" || dayStr == "Sun" || dayStr == "sun")
    {
        sunArr.push_back(dayVal);
    }
    else if (dayStr == "|" && dayVal == 0)
    {
        contStr = -1;
    }
    else
    {
        rejectedDays++;
    }
    return contStr;
}

int GetSums(std::vector<int> dayArr)
{
    int sum{ 0 };
    for (int i{ 0 }; i < dayArr.size(); ++i)
    {
        sum += dayArr[i];
    }
    return sum;
}

void DisplayData(std::string dayString, std::vector<int> dayArr)
{
    if (dayArr.size() > 0)
    {
        std::cout << dayString << ": ";
        for (int i{ 0 }; i < dayArr.size(); ++i)
        {
            if (i == (dayArr.size() - 1))
            {
                std::cout << dayArr[i] << ".\n";
                std::cout << "The sum is: " << GetSums(dayArr) << ".\n\n";
            }
            else
            {
                std::cout << dayArr[i] << ", ";
            }
        }
    }
}

int main()
try
{
    std::string userDay;
    int userNum{ 0 };
    int contVal{ 0 };

    std::cout << "Enter a day and a #, foll. by a space (Tuesday 15): ";
    while (std::cin >> userDay >> userNum)
    {
        /*if (!(std::cin >> userDay >> userNum))
        {
            throw std::runtime_error("Invalid input type!");
        }*/
        contVal = SortPairs(userDay, userNum);
        if (contVal == -1)
        {
            std::cout << "Values........\n";
            DisplayData("Mondays: ", monArr);
            DisplayData("Tuesdays: ", tueArr);
            DisplayData("Wednesdays: ", wedArr);
            DisplayData("Thursdays: ", thuArr);
            DisplayData("Fridays: ", friArr);
            DisplayData("Saturdays: ", satArr);
            DisplayData("Sundays: ", sunArr);
            std::cout << rejectedDays << " values were REJECTED!!\n";
            return 0;
        }
    }
}
catch (std::exception& e)
{
    std::cout << "Runtime error: " << e.what();
}
catch (...)
{
    std::cout << "Unknown exception!";
}