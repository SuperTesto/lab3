#include <stdio.h>
#include "Stack.h"


template<typename T>
Stack<T>::Stack(size_t _memSize): top(-1), memSize(1), pMem(new T[memSize]){}

template<typename T>
Stack<T>::~Stack()
{
	delete[] pMem;
}

template<typename T>
size_t Stack<T>::size() 
{
	return top + 1;
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return top == -1;
}

template<typename T>
bool Stack<T>::IsFull()
{
	return top == memSize - 1;
}

template<typename T>
void Stack<T>::Push(const T& val)
{
	pMem[++top] = val;
}

template<typename T>
T Stack<T>::Pop()
{
	return pMem[top--];
}

