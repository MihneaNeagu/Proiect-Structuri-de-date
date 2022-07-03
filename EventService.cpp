//
// Created by mihne on 6/27/2022.
//

#include "EventService.h"


EventService::EventService() {

}

EventService::~EventService() {

}

void EventService::add_event(int id, char *nume_event) {
    Event event(id, nume_event);
    this->evrepo.add_event(event);
}

void EventService::delete_event(int id, char *nume_event) {
    Event event(id, nume_event);
    this->evrepo.delete_event(event);
}

void EventService::update_event(int id1, char *nume_event1, int id2, char *nume_event2) {
    Event event1(id1, nume_event1);
    Event event2(id2, nume_event2);
    this->evrepo.update_event(event1, event2);
}

bool EventService::event_exists(int id, char *nume_event) {
    Event event(id, nume_event);
    return this->evrepo.event_exists(event);
}

Event *EventService::get_all() {
    return this->evrepo.get_all();
}

int EventService::size() {
    return this->evrepo.size();
}