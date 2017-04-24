#ifndef LINKED_LIST
#define LINKED_LIST
#include <iostream>
#include "DSString.h"

using namespace std;

template <class T>
class LinkedList;

template<class T>
class ListNode {
    friend class LinkedList<T>; //give LinkedList access t0 ListNode's private data

public:
//Add functionality here to provide access to the ListNode Object.
    ListNode();
    ListNode(T); //constructor that takes in the object the node will store
    ListNode(T, ListNode<T>*); //constructor that takes in a memory address for the next node (for insertion)

private:
    ListNode<T>*next;
    ListNode<T>*last;
    T data;
};


template<class T>
class LinkedList {

public:

    LinkedList();
    LinkedList(T);
    LinkedList(const LinkedList<T>&);

    void add(T);
    void addTohead(T);
    T& get(int);
    int size();
    T remove(int);
    bool isEmpty();
    
    ~LinkedList();

    T& operator[] (int);
    LinkedList<T>& operator=(LinkedList<T>&);

private:

    ListNode<T>*head;
    int num_elements;

};

template<class T>
ListNode<T>::ListNode()
{
    next = nullptr;
    last = nullptr;
}

template<class T>
ListNode<T>::ListNode(T in)
{
    data = in;
    next = nullptr;
    last = nullptr;
}

template<class T>
ListNode<T>::ListNode(T object, ListNode<T>* newNext)
{
    data = object;
    next = newNext;
    if(last == nullptr) //if "this" is the head...
        newNext->last = this; // set the "last" pointer one node backwards
}

//================================

// Default constructor
template<class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    num_elements = 0;
}

//constructor with head
template<class T>
LinkedList<T>::LinkedList(T object)
{
    head = new ListNode<T>(object);
    num_elements++;
}

//copy constructor
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
    head = nullptr;
    num_elements = 0;
    ListNode<T>* curr = rhs.head;
    while(curr != nullptr)
    {
        add(curr->data);
        curr = curr->next;
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{
    ListNode<T>* curr = head;
    while(head != nullptr)
    {
        head = head->next;
        delete curr;
        curr = head;
    }
}

template<class T>
void LinkedList<T>::add(T object)
{
    if(head == nullptr) // if there's nothing in the list
        head = new ListNode<T>(object);
    else
    {
    ListNode<T>* curr = head;
    while(curr->next != nullptr)
        curr = curr->next;
    curr->next = new ListNode<T>(object); //find the last node in the list, and create a new object stored at its "next" pointer
    curr->next->last = curr; // set the pointer in the opposite direction
    }
    num_elements++;
}

template<class T>
T& LinkedList<T>::get(int loc)
{
    ListNode<T>* curr = head;
    int i = 0; // initialize outside the for loop to check if the input is valid
    for(i = 0; i < loc && curr != nullptr; i++)
    {
        curr = curr->next;
    }
    if(i == loc - 1)
        return curr->data;
    else
        //throw an exception
        return curr->data; //FIX THIS
}

//Add an object to the beginning of the linked list
template<class T>
void LinkedList<T>::addTohead(T object)
{
    if(head == nullptr) // if there's nothing in the list
    {
        head = new ListNode<T>(object);
    }
    else
    {
        head = new ListNode<T>(object, head);
    }
    num_elements++;
}

template<class T>
int LinkedList<T>::size()
{
    return num_elements;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    if(size() == 0)
        return true;
    else
        return false;
}

template<class T>
T LinkedList<T>::remove(int loc)
{
    ListNode<T>* curr = head;

    if(loc == 0)
    {
        T value = head->data;
        head->last = nullptr;
        if(curr->next != nullptr) //if there's a node that follows
            head = curr->next;
        else
            head = nullptr;
        delete curr;
        num_elements--;
        return value;
    }

    int i = 0; // initialize outside the for loop to check if the input is valid
    for(i = 0; i < loc && curr != nullptr; i++)
    {
        curr = curr->next; //go until you are at the node being deleted
    }
    if(i == loc)
    {
        T value = curr->data;
        if (curr->next == nullptr) //if the node being deleted is the last node
        {
            curr->last->next = nullptr;
            delete curr;
        }
        else //if there is a node after the one being deleted
        {
            curr->last->next = curr->next; // set the next pointer to the node ahead of the one being deleted
            curr->next->last = curr->last; // the node one in front of the node getting deleted now points to the node behind the node getting deleted
            delete curr;
        }
        num_elements--;
        return value;
    }
    else
    {
        //throw an exception

    }

}

template<class T>
LinkedList<T>& LinkedList<T>::operator= (LinkedList<T>& rhs)
{
    if(this == &rhs)
        return *this;
    else
    {
        //if the list you're copying to is not empty, delete everything
        if(head != nullptr)
        {
            ListNode<T>* curr = head;
            while(head != nullptr)
            {
                head = head->next;
                delete curr;
                curr = head;
            }
        }

        ListNode<T>* curr = rhs.head;
        while(curr != nullptr)
        {
            add(curr->data);
            curr = curr->next;
        }

        return *this;
    }
}

template<class T>
T& LinkedList<T>::operator[] (int loc)
{
    ListNode<T>* curr = head;
    int i = 0; // initialize outside the for loop to check if the input is valid
    for(i = 0; i < loc && curr != nullptr; i++)
    {
        curr = curr->next;
    }
    if(i == loc - 1)
        return curr->data;
    else
        //throw an exception
        return curr->data; //FIX THIS
}

#endif
