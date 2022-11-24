#include <string>
#include <iostream>

#include "Stack.h"
#include "Queue.h"

using namespace std;


enum TypeElement {
	Operation,
	Value
};

class Lexema {
	string str;
	TypeElement type;
public:
	Lexema(string _str, TypeElement _type) : str(_str), type(_type) {};
	string getStr() { return str; }
	TypeElement getType() { return type; }
	friend ostream& operator << (ostream& out, Lexema& p) {
		out << "{" << p.str << ", ";
		if (p.type == Operation) {
			out << "operation";
		}
		else if (p.type == Value) {
			out << "value";
		};
		out << "}";
		return out;
	}
};

Queue <Lexema> lex(string input) {
	Queue<Lexema>res;
	input += ' ';
	int i = 0;
	string tmp = "";
	string op = "+-*/()";
	string sep = " \n\t";
	int state = 0;
	for (i = 0; i < input.size(); i++) {
		char c = input[i];
		int fres;
		switch (state)
		{
		case 0: // ��������
			if (c >= '0' && c <= '9') {
				tmp = c;
				state = 1;
				break;
			}
			fres = op.find(c);
			if (fres >= 0) {
				tmp = c;
				Lexema l(tmp, Operation);
				res.enqueue(l);
				state = 0;
				break;
			}
			break;
		case 1: // �����
			if (c >= '0' && c <= '9') {
				tmp += c;
				state = 1;
				break;
			}
			fres = op.find(c);
			if (fres >= 0) {
				Lexema l1(tmp, Value);
				res.enqueue(l1);
				tmp = c;
				Lexema l2(tmp, Operation);
				res.enqueue(l2);
				state = 0;
				break;
			}
			fres = sep.find(c);
			if (fres >= 0) {
				Lexema l(tmp, Value);
				res.enqueue(l);
				state = 0;
				break;
			}
			break;
		}
	}
	return res;
}

void print(Queue <Lexema> t) {
	while (!t.isEmpty()) {
		cout << t.peek() << endl;
		t.dequeue();
	}
}

int main() 
{
	string str = "( 123 -10)/ 50 *	\t	30 \n";
	cout << str;
	Queue <Lexema> lex_res;
	lex_res = lex(str);
	print(lex_res);
	return 0;
}