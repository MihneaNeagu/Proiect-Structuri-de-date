//
// Created by mihne on 6/27/2022.
//

#include "UtilizatorRepo.h"
#include <cstring>

UtilizatorRepo::UtilizatorRepo() {

}

UtilizatorRepo::~UtilizatorRepo() {

}

void UtilizatorRepo::add_utilizator(Utilizator &u) {
    if(exista_utilizator(u))
        throw UtilizatorRepoExceptii("User-ul exista deja!");
    if(exista_username(u.get_username()))
        throw UtilizatorRepoExceptii("Username-ul exista deja!");
    if(exista_id(u.get_id()))
        throw UtilizatorRepoExceptii("Id-ul exista deja!");
    this->lista_utilizatori.add(u);
}

void UtilizatorRepo::delete_utilizator(Utilizator &u) {
    if(!exista_utilizator(u))
        throw UtilizatorRepoExceptii("User-ul nu exista!");
    this->lista_utilizatori.remove(u);
}

void UtilizatorRepo::update_utilizator(Utilizator &v, Utilizator &n) {
    if(!exista_utilizator(v))
        throw UtilizatorRepoExceptii("User-ul nu exista!");
    if(exista_utilizator(n))
        throw UtilizatorRepoExceptii("User-ul exista deja!");
    if(exista_username(n.get_username()))
        throw UtilizatorRepoExceptii("Username-ul exista deja!");
    for(int i = 0; i < lista_utilizatori.size(); i++)
        if(lista_utilizatori.get_array()[i] == v){
            lista_utilizatori.remove(v);
            if(exista_id(n.get_id()))
                throw UtilizatorRepoExceptii("Id-ul exista deja!");
            lista_utilizatori.add(n);
        }

}

Utilizator* UtilizatorRepo::get_all() {
    return this->lista_utilizatori.get_array();
}

int UtilizatorRepo::size() {
    return this->lista_utilizatori.size();
}

bool UtilizatorRepo::exista_utilizator(Utilizator &u) {
    for(int i = 0; i < this->size(); i++)
        if(lista_utilizatori.get_array()[i] == u)
            return true;
    return false;
}

bool UtilizatorRepo::exista_username(char *username) {
    for(int i = 0; i < this->size(); i++)
        if(strcmp(lista_utilizatori.get_array()[i].get_username(), username) == 0)
            return true;
    return false;
}

bool UtilizatorRepo::exista_id(int id) {
    for(int i = 0; i < this->size(); i++)
        if(lista_utilizatori.get_array()[i].get_id() == id)
            return true;
    return false;
}

UtilizatorRepoExceptii::UtilizatorRepoExceptii(string error) {
    this->eroare = error;
}

ostream &operator<<(ostream &g, UtilizatorRepoExceptii &exceptie) {
    g << exceptie.eroare << endl;
    return g;
}