//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_EVENT_H
#define PROIECT_SDA_EVENT_H
#include "Utilizator.h"
#include "Array.h"

class Event {
private:
    int id;
    char *nume_event;
    Array<Utilizator> lista_utilizatori;
public:
    Event();
    Event(int id, char *nume_event);
    ~Event();
    int get_id();
    char* get_nume_event();
    Utilizator* get_lista_utilizatori();
    int get_nr_utilizatori();
    void set_id(int value_id);
    void set_nume_event(char* value_nume_event);
    void set_lista_utilizatori(Array<Utilizator> lista_utilizatori);
    void add_utilizator(Utilizator &utilizator);
    void delete_utilizator(Utilizator &utilizator);
    bool operator==(const Event &event);
    Event& operator=(const Event &event);
    friend istream &operator>>(istream &f, Event &ev);
};


#endif //PROIECT_SDA_EVENT_H
