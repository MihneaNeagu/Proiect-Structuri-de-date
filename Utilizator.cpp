//
// Created by mihne on 6/27/2022.
//

#include "Utilizator.h"
#include "cstring"

Utilizator::Utilizator() {

}

Utilizator::Utilizator(char *username, int id) {
    this->username = new char[strlen(username) + 1];
    strcpy(this->username, username);
    this->id = id;
}

Utilizator::~Utilizator() {

}

char* Utilizator::get_username() {
    return this->username;
}

int Utilizator::get_id() {
    return this->id;
}

void Utilizator::set_username(char *value_username) {
    this->username = new char[strlen(value_username) + 1];
    strcpy(this->username, value_username);
}

void Utilizator::set_id(int value_id) {
    this->id = value_id;
}

bool Utilizator::operator==(const Utilizator &u) {
    if(this->id == u.id and strcmp(this->username, u.username) == 0)
        return true;
    return false;
}

ostream &operator<<(ostream &g, Utilizator &u){
    g << "Utilizatorul are: ( id: " << u.get_id() <<"si username: " << u.get_username() << " )";
    return g;
}

istream &operator>>(istream &f, Utilizator &u){
    int id;
    char *username;
    cout << "Dati id: ";
    f >> id;
    username = new char[100];
    cout << "Dati username: ";
    f >> username;
    u.set_id(id);
    u.set_username(username);
    return f;
}

Utilizator& Utilizator::operator=(const Utilizator &u) {
    if(this != &u){
        this->username = nullptr;
        this->username = new char[strlen(u.username ) + 1];
        strcpy(this->username, u.username);
        this->id = u.id;
    }
    return *this;
}
