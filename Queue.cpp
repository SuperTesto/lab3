#include "Queue.h"

// Конструктор для инициализации queue
template <class X>
Queue<X>::Queue(int size)
{
    arr = new X[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Вспомогательная функция для удаления переднего элемента из очереди
template <class X>
void Queue<X>::dequeue()
{
    // проверка на опустошение queue
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << arr[front] << endl;

    front = (front + 1) % capacity;
    count--;
}

// Вспомогательная функция для добавления элемента в queue
template <class X>
void Queue<X>::enqueue(X item)
{
    // проверка на переполнение queue
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

// Вспомогательная функция для возврата первого элемента queue
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

// Вспомогательная функция для возврата размера queue
template <class X>
int Queue<X>::size() {
    return count;
}

// Вспомогательная функция для проверки, пуста ли queue или нет
template <class X>
bool Queue<X>::isEmpty() {
    return (size() == 0);
}

// Вспомогательная функция для проверки того, заполнена ли queue или нет
template <class X>
bool Queue<X>::isFull() {
    return (size() == capacity);
}
