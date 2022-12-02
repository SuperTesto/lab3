#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Lexema.h"

using namespace std;

int main()
{
    string str = "((123 + 10 * 2 - 3)/ 20\n";
    cout << "Expression: " << str;
    Queue <Lexema> lex_res;
    cout << "Lexems:\n";
    lex_res = lex(str);
    cout << lex_res << endl;
    vector <Lexema> polka;
    double m;
    try
    {
        polka = Reverse_Polska(lex_res);
        cout << "\nReverse Polska result:\n";
        for (int i = 0; i < polka.size(); i++)
            cout << polka[i];
    }
    catch (exception ex)
    {
        cout << ex.what();
        return 0;
    }
    try
    {
        Calculate(polka);
    }
    catch (exception ex)
    {
        cout << ex.what();
        return 0;
    }

    cout << "Calculate result: " << Calculate(polka);
    cout << "\nResult: " << (123.0 + 10.0 * 2.0 - 3.0) / 20.0;
    return 0;
}