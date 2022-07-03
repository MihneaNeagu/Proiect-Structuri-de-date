//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_NOD_H
#define PROIECT_SDA_NOD_H

template <class K, class V>
class Dictionary;

template <class K, class V>
class Nod
{
private:
    K key;
    V value;
    Nod<K, V>* next;
public:
    Nod(K key, V value) : key(key), value(value)
    {
        this->next = nullptr;
    }
    friend class Dictionary<K, V>;
};
#endif //PROIECT_SDA_NOD_H
