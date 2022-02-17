#include <iostream>
#include <vector>

class Token
{
public:
    double MValue{ 0 };
    char MKind{ ' ' };
    Token(char TempChar) : MKind{ TempChar }, MValue{ 0 } {}
    Token(char TempChar, double TempValue) : MKind{ TempChar }, MValue{ TempValue } {}
};

class TokenStream
{
public:
    TokenStream();
    Token GetToken();
    void PutbackToken(Token TempToken);
    bool GetBufferStatus() { return IsBufferFull; }
        
private:
    bool IsBufferFull = false;
    Token TokenInBuffer;
};

TokenStream::TokenStream() : IsBufferFull{ false }, TokenInBuffer{ 0 } {}
Token TokenStream::GetToken()
{
    if (IsBufferFull)
    {
        IsBufferFull = false;
        return TokenInBuffer;
    }
    char Inp{ ' ' };
    std::cin >> Inp;
    switch (Inp)
    {
    case '+': case '-': case '*': case '/': 
    case '(': case ')': case '=':
        return Token{ Inp };

    case '0': case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9':
    {
        std::cin.putback(Inp);
        double InpValue{ 0 };
        std::cin >> InpValue;
        return Token{ '8', InpValue };
    }
    default:
        throw std::runtime_error("Invalid input! Source:TokenStream::GetToken().");
    }
}
void TokenStream::PutbackToken(Token TempToken)
{
    if (IsBufferFull)
    {
        throw std::runtime_error("TokenStream Buffer is full!");
    }
    TokenInBuffer = TempToken;
    IsBufferFull = true;
}

double EvalPrimary()
{

}
double EvalTerm()
{

}
double EvalExpr()
{

}

int main()
try
{
    std::cout << "Welcome to my simple calculator. Result: '='. Quit: 'x'.\n";
    std::cout << "Enter an expression: ";
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