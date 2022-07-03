//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_EVENTSERVICE_H
#define PROIECT_SDA_EVENTSERVICE_H
#include "Event.h"
#include "EventRepo.h"

class EventService {
private:
    EventRepo evrepo;
public:
    EventService();
    ~EventService();
    void add_event(int id, char *nume_event);
    void delete_event(int id, char* nume_event);
    void update_event(int id1, char* nume_event1, int id2, char* nume_event2);
    bool event_exists(int id, char* nume_event);
    Event* get_all();
    int size();
};


#endif //PROIECT_SDA_EVENTSERVICE_H
