//
// Created by mihne on 6/27/2022.
//

#include "Validator.h"
#include <cstring>
using namespace std;
void Validator::validator(Utilizator &utilizator) {
    Array<string> erori;

    if(utilizator.get_id() < 0)
        erori.add("Id-ul trebuie sa fie mai mare ca 0");
    if(strcmp(utilizator.get_username(), "\n") == 0)
        erori.add("Username-ul trebuie sa existe");

    if(erori.size() > 0)
        throw ExceptieValidator(erori);
}

ExceptieValidator::ExceptieValidator(Array<string> &erori) {
    this->msj = erori;
}

ostream &operator<<(ostream &g, ExceptieValidator &exceptie) {
    for(int i = 0; i < exceptie.msj.size(); i++)
        if(&exceptie.msj.get_array()[i] != nullptr)
            g << exceptie.msj.get_array()[i] << endl;
    return g;
}