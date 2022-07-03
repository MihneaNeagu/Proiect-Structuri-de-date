//
// Created by mihne on 6/27/2022.
//

#include "Event.h"
#include <cstring>

Event::Event() {

}

Event::~Event() {

}

void Event::add_utilizator(Utilizator &utilizator) {
    this->lista_utilizatori.add(utilizator);
}

void Event::delete_utilizator(Utilizator &utilizator) {
    this->lista_utilizatori.remove(utilizator);
}

int Event::get_nr_utilizatori() {
    return this->lista_utilizatori.size();
}

Event::Event(int id, char *nume_event) {
    this->id = id;
    this->nume_event = new char[strlen(nume_event) + 1];
    strcpy(this->nume_event, nume_event);
}

int Event::get_id() {
    return this->id;
}

char *Event::get_nume_event() {
    return this->nume_event;
}

Utilizator *Event::get_lista_utilizatori() {
    return this->lista_utilizatori.get_array();
}

void Event::set_id(int value_id) {
    this->id = value_id;
}


void Event::set_nume_event(char *value_nume_event) {
    this->nume_event = new char[strlen(value_nume_event) + 1];
    strcpy(this->nume_event, value_nume_event);
}

bool Event::operator==(const Event &event) {
    if(this->id == event.id and strcmp(this->nume_event, event.nume_event) == 0)
        return true;
    return false;
}

void Event::set_lista_utilizatori(Array<Utilizator> lista_participanti) {
    for(int i = 0; i < lista_participanti.size(); i++)
        this->lista_utilizatori.add(lista_participanti.get_array()[i]);
}

Event &Event::operator=(const Event &event) {
    if(this != &event){
        this->id = event.id;
        delete[] this->nume_event;
        this->nume_event = new char [strlen(event.nume_event) + 1];
        strcpy(this->nume_event, event.nume_event);
    }
    return *this;
}

istream &operator>>(istream &f, Event &ev){
    int id;
    char* nume_event;
    cout << "Dati id: ";
    f >> id;
    nume_event = new char[30];
    cout << "Dati nume event: ";
    f >> nume_event;
    ev.set_id(id);
    ev.set_nume_event(nume_event);
    return f;
}







