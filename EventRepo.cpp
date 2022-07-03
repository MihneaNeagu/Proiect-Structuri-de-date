//
// Created by mihne on 6/27/2022.
//

#include "EventRepo.h"


EventRepo::EventRepo() {

}

EventRepo::EventRepo(Array<Event> lista_evenimente) {

}

EventRepo::~EventRepo() {

}

void EventRepo::add_event(Event &e) {
    this->lista_evenimente.add(e);
}

void EventRepo::delete_event(Event &e) {
    this->lista_evenimente.remove(e);
}

void EventRepo::update_event(Event &v, Event &n) {
    for(int i = 0; i < lista_evenimente.size(); i++)
        if(lista_evenimente.get_array()[i] == v){
            this->lista_evenimente.remove(v);
            this->lista_evenimente.add(n);
        }
}

int EventRepo::size() {
    return this->lista_evenimente.size();
}

bool EventRepo::event_exists(Event &e) {
    for(int i = 0; i < this->lista_evenimente.size(); i++)
        if(this->lista_evenimente.get_array()[i] == e)
            return true;
    return false;
}

Event *EventRepo::get_all() {
    return this->lista_evenimente.get_array();
}