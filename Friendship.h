//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_FRIENDSHIP_H
#define PROIECT_SDA_FRIENDSHIP_H
#include "Array.h"
#include "Utilizator.h"
using namespace std;

class Friendship {
private:
    Utilizator user1;
    Utilizator user2;
    Array<char*> mesaje;
public:
    Friendship();
    Friendship(Utilizator &u1, Utilizator &u2);
    ~Friendship();
    Utilizator get_utilizator1();
    Utilizator get_utilizator2();
    void add_message(char* mesaj);
    void delete_message(char* mesaj);
    char** get_all_messages();
    int size_messages();
    bool operator==(const Friendship &p);

};


#endif //PROIECT_SDA_FRIENDSHIP_H
