#pragma once
#include <iostream>
#define SIZE 50

template <class X>
class Queue
{
    X* arr;         // ������ ��� �������� ��������� queue
    int capacity;   // ������������ ������� queue
    int front;      // front ��������� �� �������� ������� � queue (���� ����)
    int rear;       // ������ ����� ��������� �� ��������� ������� � queue
    int count;      // ������� ������ queue

public:
    Queue(int size = SIZE);     // �����������

    void dequeue();
    void enqueue(X x);
    X peek();
    int size();
    bool isEmpty();
    bool isFull();
};

