/*E02, E03*/

#include <iostream>
#include <vector>

class Token
{
public:
    char TokenType{ ' ' };
    double TokenValue{ 0 };
    Token(char ch) : TokenType(ch), TokenValue(0) {}
    Token(char ch, double val) : TokenType(ch), TokenValue(val) {}
};

class TokenStream
{
public:
    TokenStream();
    Token GetToken();
    void PutbackTokenIntoStream(Token TokenToPutback);
    /*Some get/sets for debug.*/
    bool GetIsBufferFull() { return IsBufferFull; }
    double GetTokenValInf() { return TokenToHold.TokenValue; }
    char GetTokenTypeInf() { return TokenToHold.TokenType; }
private:
    bool IsBufferFull;
    Token TokenToHold;
}; 

TokenStream::TokenStream() : IsBufferFull(false), TokenToHold(0) {};
void TokenStream::PutbackTokenIntoStream(Token TokenToPutback)
{
    if (IsBufferFull)
    {
        throw std::runtime_error("TokenStream (bool)Buffer is full!");
    }
    TokenToHold = TokenToPutback;
    IsBufferFull = true;
}

Token TokenStream::GetToken()
{
    if (IsBufferFull)
    {
        IsBufferFull = false;
        return TokenToHold;
    }

    char TempChar{ ' ' };
    std::cin >> TempChar;
    switch (TempChar)
    {
    case '{': case '}': case '(': case ')': case '+': case '-': case '*': case '/': case '%': case '=': case '!':
    {
        return Token{ TempChar };
    }
    case '.': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    {
        std::cin.putback(TempChar);
        double TValue{ 0 };
        std::cin >> TValue;
        return Token{ '8', TValue };
    }
    default:
        throw std::runtime_error("Invalid input: Unable to create a new Token!");
    }
}

TokenStream TSObject;

double EvalFactorial(double TempInt)
{
    int FactVariable = TempInt;
    if (double(FactVariable) != TempInt)
    {
        throw std::runtime_error("Factorial undefined for non-integers.");
    }
    if (FactVariable < 0)
    {
        throw std::runtime_error("Factorial undefined for negative values.");
    }
    if (FactVariable > 31)
    {
        throw std::runtime_error("Too large ( > 31).");
    }
    if (FactVariable == 0)
    {
        return 1;
    }
    else
    {
        int ActualResult = FactVariable;
        for (int i{ ActualResult - 1 }; i > 0; i--)
        {
            ActualResult *= i;
        }
        return ActualResult;
    }
}


double EvalPrimary()
{
    double EvalExpression();

    Token TempToken = TSObject.GetToken();
    double TVal{ 0 };
    switch (TempToken.TokenType)
    {
    case '(':
    {
        TVal = EvalExpression();
        TempToken = TSObject.GetToken();
        if (TempToken.TokenType != ')')
        {
            throw std::runtime_error("Expecting a )!");
        }
        break;
    }
    case '{':
    {
        TVal = EvalExpression();
        TempToken = TSObject.GetToken();
        if (TempToken.TokenType != '}')
        {
            throw std::runtime_error("Expecting a }!");
        }
        break;
    }
    case '8':
        TVal = TempToken.TokenValue;
        break;
    case '-':
        TVal = -EvalPrimary();
        break;
    case '+':
        TVal = EvalPrimary();
        break;
    default:
        throw std::runtime_error("Expecting a Primary!");
    }

    TempToken = TSObject.GetToken();
    if (TempToken.TokenType != '!')
    {
        TSObject.PutbackTokenIntoStream(TempToken);
        return TVal;
    }
    return EvalFactorial(TVal);
}

double EvalTerm()
{
    double LVal = EvalPrimary();
    Token TempToken = TSObject.GetToken();
    while (true)
    {
        switch (TempToken.TokenType)
        {
        case '*':
            LVal *= EvalPrimary();
            TempToken = TSObject.GetToken();
            break;
        case '/':
        {
            double TempV = EvalPrimary();
            if (TempV == 0) throw std::runtime_error("Divide by zero!");
            LVal /= TempV;
            TempToken = TSObject.GetToken();
            break;
        }
        default:
            TSObject.PutbackTokenIntoStream(TempToken);
            return LVal;
        }
    }
}

double EvalExpression()
{
    double LVal = EvalTerm();
    Token TempToken = TSObject.GetToken();
    while (true)
    {
        switch (TempToken.TokenType)
        {
        case '+':
            LVal += EvalTerm();
            TempToken = TSObject.GetToken();
            break;
        case '-':
            LVal -= EvalTerm();
            TempToken = TSObject.GetToken();
            break;
        default:
            TSObject.PutbackTokenIntoStream(TempToken);
            return LVal;
        }
    }
}

int main()
try
{
    std::cout << "Welcome to my simple calculator. Result: '='. Quit: 'x'.\n";
    std::cout << "Enter an expression: ";
    while (std::cin)
    {
        Token MTok = TSObject.GetToken();
        while (MTok.TokenType == '=') MTok = TSObject.GetToken();
        if (MTok.TokenType == 'x') std::cout << "\nExiting program.\n";
        TSObject.PutbackTokenIntoStream(MTok);
        std::cout << EvalExpression() << ".\n";
    }
    return 0;
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