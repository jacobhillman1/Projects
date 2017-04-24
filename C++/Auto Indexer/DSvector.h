#ifndef VECTOR
#define VECTOR

#include<iostream>
#include "fstream"

using namespace std;

template<class T>
class Vector{

  public:

      Vector();
      Vector(int);

      Vector(const Vector<T>&); //copy constructor

      void add(T);

      void add(T, int);//adds or replaces an object in the specified location

      T get(int); // returns an object in the vector

      ~Vector();

      int size();
      int getCapacity();
      void deleteData();

      void sort();
      bool contains(T); //originally had nothing in the parameter
      int containsAt(T); //returns the location of where the duploicate is contained

      T& operator[](int);
      Vector<T>& operator=(Vector<T>&);  

      //ostream& operator<<(ostream&, const Vector<classT>&);
      Vector<T>& operator+=(T);

  private:

      void resize();
      T* data;
      int Vsize = 0;
      int capacity = 0;

};

template<class T>
Vector<T>::Vector() {
    capacity = 10;
    data = new T[capacity];
}

template<class T> //copy constructor
Vector<T>::Vector(const Vector<T> & rhs) {
    capacity = rhs.capacity;
    Vsize = rhs.Vsize;

    data = new T[capacity];

    for(int i = 0; i < Vsize; i++)
        data[i] = rhs.data[i];

}

template<class T>
Vector<T>::Vector(int s) {
    Vsize = s;
    capacity = s*1.5;
    data = new T[capacity];
}

template<class T>
void Vector<T>::add(T object) {
    if(Vsize == capacity) // if the capacity is reached, create a new array of objects 1.5 times bigger than the previous
        resize();
    data[Vsize] = object; //place the object in the next available space in the array
    Vsize++; //increment the size by +1
}

template<class T>
void Vector<T>::add(T object, int k) {
    if(Vsize == capacity) // if the capacity is reached, create a new array of objects 1.5 times bigger than the previous
        resize();
    for(int i = Vsize - 1; i >= k - 1; i-- ) // start at last element of the array. Push all of the poceeding objects one space to the right
    {
        data[i + 1] = data[i];
    }

    data[k] = object; // add the object in the now empty position

    Vsize++; // increment the size

}

template<class T>
T Vector<T>::get(int i) {
    return data[i];
}

template<class T>
int Vector<T>::size() {
    return Vsize;
}

template<class T>
int Vector<T>::getCapacity() {
    return capacity;
}

template<class T>
void Vector<T>::resize() {
    capacity *= 1.5;
    T* temp = new T[capacity];
    for(int i = 0; i < Vsize; i++)
        temp[i] = data[i];
    delete[] data;
    data = temp; // data now points to the array created at location temp
}

template<class T>
Vector<T>::~Vector() {
    delete[] data;
}

//used when reusing the same temp object that contains a vector
template<class T>
void Vector<T>::deleteData()
{
    if(Vsize != 0)
        delete[] data;
    Vsize = 0;
    capacity = 10;
    data = new T[capacity];
}

template<class T>
T& Vector<T>::operator[](int i) {

    return data[i];
}

template<class T>
void Vector<T>::sort() {
    bool sorted = false;
    T temp;
    while(!sorted)
    {
        // Set true initially, and eventually set false if characters are out of order
        sorted = true;
        for(int i = 0; i < Vsize - 1; i++)
        {
            if(data[i] > data[i + 1])
            {
                // If objects are determined to be out of order, swaps the letters and sets sorted to false to continue the loop.
                temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                sorted = false;
            }
        }
    }
}

template<class T>
bool Vector<T>::contains(T input) {
    bool contains = false;
    if(Vsize != 0)
    { 
        for(int i = 0; i < Vsize; i++)
        {
            if(data[i] == input)
                contains = true; // parse through each object in the data array. If an object matches the input object, set contains = true
        }
    }

    return contains;
}

template<class T>
int Vector<T>::containsAt(T input) {
    if(Vsize != 0)
    {
        for(int i = 0; i < Vsize; i++)
        {
            if(data[i] == input)
            {
                return i;
            }
        }
    }

    return 0;
}


template<class T>
Vector<T>& Vector<T>::operator+=(T object) { //functionally identtical to the add function
    if(Vsize == capacity) // if the capacity is reached, create a new array of objects 1.5 times bigger than the previous
    {
        resize();
    }
    data[Vsize] = object; //place the object in the next available space in the array
    Vsize++; //increment the size by +1

    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector<T>& rhs) {
    capacity = rhs.getCapacity();
    Vsize = rhs.size();
    T* temp = new T[capacity]; //make a new array of objects the same size as rhs
    for(int i = 0; i < Vsize; i++)
        temp[i] = rhs[i]; // this creates an entirely new copy of the object passed as a parameter
    delete[] data;
    data = temp;

    return *this;

}


#endif
