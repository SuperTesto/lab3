#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Lexema.h"

using namespace std;

int main()
{
    string str = "1-(123 + 10 * 2 - 3)/ 20\n";
    cout << str;
    Queue <Lexema> lex_res;
    lex_res = lex(str);
    cout << lex_res << endl;
    vector <Lexema> polka = Reverse_Polska(lex_res);
    for (int i = 0; i < polka.size(); i++)
        cout << polka[i] << endl;
    return 0;
}