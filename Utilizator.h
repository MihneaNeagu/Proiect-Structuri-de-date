//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_UTILIZATOR_H
#define PROIECT_SDA_UTILIZATOR_H
#include <iostream>
using namespace std;

class Utilizator: public error_code {

        private:
        char *username;
        int id;
        public:
        Utilizator();
        Utilizator(char *username, int id);
        ~Utilizator();
        char *get_username();
        int get_id();
        void set_username(char *value_username);
        void set_id(int value_id);
        bool operator==(const Utilizator &u);
        Utilizator& operator=(const Utilizator &u);
        friend ostream &operator<<(ostream &os, Utilizator &u);
        friend istream &operator>>(istream &is, Utilizator &u);

};


#endif //PROIECT_SDA_UTILIZATOR_H
