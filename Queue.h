#pragma once
#include <iostream>
#define SIZE 50

template <class X>
class Queue
{
    X* arr;         // массив дл€ хранени€ элементов queue
    int capacity;   // максимальна€ емкость queue
    int front;      // front указывает на передний элемент в queue (если есть)
    int rear;       // задн€€ часть указывает на последний элемент в queue
    int count;      // текущий размер queue

public:
    Queue(int size = SIZE);     // конструктор

    void dequeue();
    void enqueue(X x);
    X peek();
    int size();
    bool isEmpty();
    bool isFull();
};

