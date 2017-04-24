#ifndef QUEUE
#define QUEUE

#include "linkedlist.h"

template<class T>
class Queue{

    public:

        T dequeue();
        T peek();
        void enqueue(T);
        bool isEmpty();

    private:

        LinkedList<T> data;

};

template<class T>
void Queue<T>::enqueue(T in)
{
    data.add(in);
}

template<class T>
T Queue<T>::dequeue()
{
    return data.remove(0);
}

template<class T>
T Queue<T>::peek()
{
    return data.get(0);
}

template<class T>
bool Queue<T>::isEmpty()
{
    if(data.size() == 0) return true;
    else return false;
}

#endif
