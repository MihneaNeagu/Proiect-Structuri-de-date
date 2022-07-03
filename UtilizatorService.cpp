//
// Created by mihne on 6/27/2022.
//

#include "UtilizatorService.h"

UtilizatorService::UtilizatorService() {

}

UtilizatorService::UtilizatorService(UtilizatorRepo &ur) {
    this->repo = ur;
}

UtilizatorService::~UtilizatorService() {

}

void UtilizatorService::add_utilizator(int id, char *username) {
    Utilizator u1(username, id);
    this->validator.validator(u1);
    this->repo.add_utilizator(u1);
}

void UtilizatorService::delete_utilizator(int id, char *username) {
    Utilizator u(username, id);
    this->repo.delete_utilizator(u);
}

void UtilizatorService::update_utilizator(int id_vechi, char *username_vechi, int id_nou, char *username_nou) {
    Utilizator v(username_vechi, id_vechi);
    Utilizator n(username_nou, id_nou);
    this->validator.validator(n);
    this->repo.update_utilizator(v, n);
}

Utilizator* UtilizatorService::get_all() {
    return this->repo.get_all();
}

int UtilizatorService::size() {
    return this->repo.size();
}

bool UtilizatorService::exista_user(int id, char *username) {
    Utilizator u(username, id);
    return this->repo.exista_utilizator(u);
}

