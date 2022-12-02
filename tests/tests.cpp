#include <gtest/gtest.h>
#include "../Lexema.h"
#include "../Queue.h"
#include "../Stack.h"
using namespace std;

Lexema tmpVal("testVal", Value);
Lexema tmpOper("testOper", Operation);

TEST(Lexema, Value_type)
{
	EXPECT_EQ(tmpVal.getType(), Value);
}

TEST(Lexema, Operation_type)
{
	EXPECT_EQ(tmpOper.getType(), Operation);
}

TEST(Lexema, to_lex)
{
	string S = "123+5/3";
	Lexema L1("123", Value);
	Lexema L2("+", Operation);
	Lexema L3("5", Value);
	Lexema L4("/", Operation);
	Lexema L5("3", Value);
	Queue<Lexema>Q1 = lex(S);
	EXPECT_EQ(Q1.Pop().getStr(), L1.getStr());
	EXPECT_EQ(Q1.Pop().getType(), L1.getType());
}
