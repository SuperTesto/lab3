#include "Queue.h"

// ����������� ��� ������������� queue
template <class X>
Queue<X>::Queue(int size)
{
    arr = new X[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// ��������������� ������� ��� �������� ��������� �������� �� �������
template <class X>
void Queue<X>::dequeue()
{
    // �������� �� ����������� queue
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << arr[front] << endl;

    front = (front + 1) % capacity;
    count--;
}

// ��������������� ������� ��� ���������� �������� � queue
template <class X>
void Queue<X>::enqueue(X item)
{
    // �������� �� ������������ queue
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// ��������������� ������� ��� �������� ������� �������� queue
template <class X>
X Queue<X>::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// ��������������� ������� ��� �������� ������� queue
template <class X>
int Queue<X>::size() {
    return count;
}

// ��������������� ������� ��� ��������, ����� �� queue ��� ���
template <class X>
bool Queue<X>::isEmpty() {
    return (size() == 0);
}

// ��������������� ������� ��� �������� ����, ��������� �� queue ��� ���
template <class X>
bool Queue<X>::isFull() {
    return (size() == capacity);
}
