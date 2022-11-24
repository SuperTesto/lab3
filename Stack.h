#pragma once

#include <iostream>
using namespace std;

template<typename T>
class Stack
{
private:
	int top;
	size_t memSize;
	T* pMem;
public:
	Stack(size_t _memSize);
	~Stack();
	size_t size();
	bool IsEmpty();
	bool IsFull();
	void Push(const T& val);
	T Pop();
};