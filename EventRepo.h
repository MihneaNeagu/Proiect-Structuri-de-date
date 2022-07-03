//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_EVENTREPO_H
#define PROIECT_SDA_EVENTREPO_H
#include "Event.h"
#include "Array.h"

class EventRepo {
private:
    Array<Event> lista_evenimente;
public:
    EventRepo();
    EventRepo(Array<Event> lista_evenimente);
    ~EventRepo();
    void add_event(Event &e);
    void delete_event(Event &e);
    void update_event(Event &v, Event &n);
    int size();
    bool event_exists(Event &e);
    Event* get_all();
};


#endif //PROIECT_SDA_EVENTREPO_H
