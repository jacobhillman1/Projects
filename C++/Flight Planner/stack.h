#ifndef STACK
#define STACK

#include "linkedlist.h"

template<class T>
class Stack{

    public:

        Stack();
        //Stack(const Stack<T>&); //copy constructor
        T pop();
        T peek();
        T get(int);
        void push(T);
        bool isEmpty();
        bool contains(T);
        int size();

    private:

        LinkedList<T> data;

};

template<class T>
Stack<T>::Stack()
{

}

template<class T>
T Stack<T>::pop()
{
   return data.remove(data.size() - 1);
}

template<class T>
void Stack<T>::push(T in)
{
    data.add(in);
}

template<class T>
T Stack<T>::peek()
{
    return(data.get(data.size() - 1));
}

// get returns the value of the object held at a certain loc
// much like peek(), just not sequential
template<class T>
T Stack<T>::get(int i)
{
    return data.get(i);
}

template<class T>
bool Stack<T>::isEmpty()
{
    if(data.size() == 0) return true;
    else return false;
}

/* Takes in an object, returns true if an identical object is
 * already contained in the stack */
template<class T>
bool Stack<T>::contains(T in)
{
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i] == in)
            return true;
    }

    return false;
}

template<class T>
int Stack<T>::size()
{
    return data.size();
}

#endif
