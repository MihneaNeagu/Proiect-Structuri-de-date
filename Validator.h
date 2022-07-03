//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_VALIDATOR_H
#define PROIECT_SDA_VALIDATOR_H

#include"Array.h"
#include"Utilizator.h"
using namespace std;
class Validator {
public:
    void validator(Utilizator &utilizator);
};

class ExceptieValidator {
private:
    Array<string> msj;
public:
    ExceptieValidator(Array<string>& erori);
    friend ostream& operator<<(ostream& g, ExceptieValidator &exceptie);
};


#endif //PROIECT_SDA_VALIDATOR_H
