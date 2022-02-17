/* E05 - E06 */
/* Grammar Implementation.
 Implements this grammar:

    Sentence:
        Subject Verb
        Sentence Conjunction Sentence

        Subject:
            Noun
            "the" Noun

        Conjunction:
            "and"
            "or"
            "but"

        Noun:
            "birds"
            "fish"
            "C++"

        Verb:
            "rules"
            "fly"
            "swim"

    and checks if an entered sentence is correct according to it or not. */


#include <iostream>
#include <string.h>

class StringStream
{
public:
    StringStream();
    std::string GetString();
    void PutBackString(std::string PutbackStr);
private:
    bool IsStreamFull{ false };
    std::string StringToHold{ "" };
};

StringStream::StringStream() : IsStreamFull(false), StringToHold("") {}
std::string StringStream::GetString()
{
    if (IsStreamFull)
    {
        IsStreamFull = false;
        return StringToHold;
    }
    std::string UserString{ "" };
    std::cin >> UserString;
    return UserString;
}

void StringStream::PutBackString(std::string PutBackStr)
{
    if (IsStreamFull)
    {
        throw std::runtime_error("Can't store string in a full buffer.");
    }
    StringToHold = PutBackStr;
    IsStreamFull = true;

}

StringStream StrStreamOBJ;

bool CheckConjunction()
{
    std::string TempString = StrStreamOBJ.GetString();

    if (TempString == "but" || TempString == "or" || TempString == "and")
    {
        return true;
    }
    else
        return false;
}

bool CheckNoun()
{
    std::string TempString = StrStreamOBJ.GetString();

    if (TempString == "birds" || TempString == "fish" || TempString == "C++")
    {
        return true;
    }
    else
        return false;
}
bool CheckVerb()
{
    std::string TempString = StrStreamOBJ.GetString();

    if (TempString == "fly" || TempString == "rules" || TempString == "swim")
    {
        return true;
    }
    else
        return false;
}

bool CheckSubject()
{
    std::string TempString = StrStreamOBJ.GetString();
    if (TempString == "the")
    {
        return CheckNoun();
    }
    else
    {
        StrStreamOBJ.PutBackString(TempString);
        return CheckNoun();
    }
}

bool CheckSentence()
{
    return (CheckSubject() && CheckVerb());
}

int main()
try
{
    bool IsSuccess{ false };
    while (true)
    {
        IsSuccess = CheckSentence();

        if (!IsSuccess)
        {
            std::cout << "Invalid grammar.\n";
            return 0;
        }

        std::string TempStr = StrStreamOBJ.GetString();
        if (TempStr == ".")
        {
            std::cout << "Valid Grammar.\n";
            return 0;
        }
        else
        {
            StrStreamOBJ.PutBackString(TempStr);
            IsSuccess = CheckConjunction();
            if (!IsSuccess)
            {
                std::cout << "Invalid grammar.\n";
                return 0;
            }
        }
    }
}

    
catch (std::exception& exc)
{
    std::cout << "Runtime error: " << exc.what() << "\n";
    return 1;
}
catch (...)
{
    std::cout << "Unknown exception!\n";
    return 2;
}