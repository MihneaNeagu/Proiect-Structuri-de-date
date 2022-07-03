//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_DICTIONARY_H
#define PROIECT_SDA_DICTIONARY_H

#include "Nod.h"

template<class K, class V>
class Dictionary
{
private:
    Nod<K,V>* first;
    int size;
public:
    Dictionary()
    {
        this->first = nullptr;
        this->size = 0;
    }
    void add(K key, V value)
    {
        if (first == nullptr)
        {
            first = new Nod<K, V>(key, value);
            this->size++;
        }
        else
        {
            Nod<K, V>* x = first;
            while (x->next != nullptr && x->key != key) x = x->next;
            if (x->key == key) x->value = value;
            else x->next = new Nod<K, V>(key, value), this->size++;
        }
    }
    V get(K key) {
        Nod<K,V>* x = first;
        while (x != nullptr)
        {
            if (x->key == key) return x->value;
            x = x->next;
        }
        return {};
    }
    int get_size()
    {
        return this->size;
    }
    void remove(K key)
    {
        Nod<K, V>* x = first;
        Nod<K, V>* prev = nullptr;
        if (x != nullptr && x->key == key)
        {
            first = x->next;
            delete x;
            this->size--;
            return;
        }
        else
        {
            while (x != nullptr && x->key != key)
            {
                prev = x;
                x = x->next;
            }
            if (x == nullptr)
                return;
            prev->next = x->next;
            delete x;
            this->size--;
        }
    }
};
#endif //PROIECT_SDA_DICTIONARY_H
