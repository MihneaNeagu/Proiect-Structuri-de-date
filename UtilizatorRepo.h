//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_UTILIZATORREPO_H
#define PROIECT_SDA_UTILIZATORREPO_H
#include "Utilizator.h"
#include "Array.h"

class UtilizatorRepo {
private:
    Array<Utilizator> lista_utilizatori;
public:
    UtilizatorRepo();
    ~UtilizatorRepo();
    void add_utilizator(Utilizator &u);
    void delete_utilizator(Utilizator &u);
    void update_utilizator(Utilizator &v, Utilizator &n);
    int size();
    Utilizator* get_all();
    bool exista_utilizator(Utilizator &u);
    bool exista_username(char username[]);
    bool exista_id(int id);
};


class UtilizatorRepoExceptii{
private:
    string eroare;
public:
    UtilizatorRepoExceptii(string err);
    friend ostream& operator<<(ostream& g, UtilizatorRepoExceptii &exceptie);
};



#endif //PROIECT_SDA_UTILIZATORREPO_H
