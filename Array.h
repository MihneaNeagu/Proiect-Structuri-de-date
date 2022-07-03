//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_ARRAY_H
#define PROIECT_SDA_ARRAY_H
#include "iostream"
#include "Utilizator.h"
using namespace std;

template<typename T>
class Array {
private:
    T *entities;
    int nr_elements{};
    int max_capacity{};
    void resize();
public:
    Array();
    Array(const Array &a);
    void add(const T& elem);
    int size();
    int search(const T &elem);
    void remove(T &elem);
    T get_at(int position);
    T* get_array();
    bool operator==(const Array<T> array);
};

template<typename T>
bool Array<T>::operator==(const Array<T> array) {
    for(int i = 0; i < this->size(); i++)
        if(entities[i] == array.entities[i])
            return true;
    return false;
}

template<typename T>
Array<T>::Array() : entities{ new T[100]}, nr_elements{0}, max_capacity{10}{}

template<typename T>
Array<T>::Array(const Array<T> &a) {
    entities = new T[a.max_capacity];
    for(int i = 0; i < a.nr_elements; i++)
        entities[i] = a.entities[i];
    nr_elements = a.nr_elements;
    max_capacity = a.max_capacity;
}

template<typename T>
void Array<T>::resize() {
    T * newElems = new T[max_capacity*2];
    for(int i=0;i< nr_elements;i++)
        newElems[i]= entities[i];
    max_capacity*=2;
    delete[] entities;
    entities = newElems;
}

template<typename T>
void Array<T>::add(const T& elem) {
    if(nr_elements == max_capacity)
        resize();
    entities[nr_elements++] = elem;
}

template<typename T>
void Array<T>::remove(T &elem) {
    for(int i = 0; i < nr_elements; i++)
        if(entities[i] == elem)
        {
            for(int j = i; j < nr_elements - 1; j++)
                entities[j] = entities[j + 1];
            i = nr_elements + 1;
        }
    nr_elements--;
}

template<typename T>
int Array<T>::size() {
    return nr_elements;
}

template<typename T>
int Array<T>::search(const T &elem) {
    for(int i = 0; i < nr_elements; i++)
        if(entities[i] == elem)
            return i;
    return -1;
}

template<typename T>
T Array<T>::get_at(int position) {
    return entities[position];
}

template<typename T>
T* Array<T>::get_array() {
    return entities;
}
#endif //PROIECT_SDA_ARRAY_H
