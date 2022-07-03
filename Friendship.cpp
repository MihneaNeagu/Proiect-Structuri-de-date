//
// Created by mihne on 6/27/2022.
//

#include "Friendship.h"




Friendship::Friendship(Utilizator &u1, Utilizator &u2) {
    this->user1 = u1;
    this->user2 = u2;
}

Friendship::Friendship() {

}



Friendship::~Friendship() {

}

void Friendship::add_message(char* mesaj) {
    this->mesaje.add(mesaj);
}

void Friendship::delete_message(char* mesaj) {
    this->mesaje.remove(mesaj);
}

char** Friendship::get_all_messages() {
    return this->mesaje.get_array();
}

int Friendship::size_messages() {
    return this->mesaje.size();
}

Utilizator Friendship::get_utilizator1() {
    return this->user1;
}

Utilizator Friendship::get_utilizator2() {
    return this->user2;
}

bool Friendship::operator==(const Friendship &p) {
    if((this->user1 == p.user1 and this->user2 == p.user2) or (this->user1 == p.user2 and this->user2 == p.user1))
        return true;
    return false;
}


