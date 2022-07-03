//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_UTILIZATORSERVICE_H
#define PROIECT_SDA_UTILIZATORSERVICE_H
#include "Utilizator.h"
#include "UtilizatorRepo.h"
#include "Validator.h"
class UtilizatorService {
private:
    UtilizatorRepo repo;
    Validator validator;
public:
    UtilizatorService();
    UtilizatorService(UtilizatorRepo &ur);
    ~UtilizatorService();
    void add_utilizator(int id, char *username);
    void delete_utilizator(int id, char *username);
    void update_utilizator(int id_vechi, char *username_vechi, int id_nou, char *username_nou);
    int size();
    Utilizator* get_all();
    bool exista_user(int id, char* username);
};


#endif //PROIECT_SDA_UTILIZATORSERVICE_H
