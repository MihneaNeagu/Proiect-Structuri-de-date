//
// Created by mihne on 6/28/2022.
//

#ifndef PROIECT_SDA_UI_H
#define PROIECT_SDA_UI_H
#include "UtilizatorService.h"
#include "FriendshipService.h"
#include "EventService.h"

class UI {
private:
    UtilizatorService utilizator_service;
    FriendshipService fr_service;
    EventService event_service;
public:
    UI();
    UI(const UtilizatorService &s);
    ~UI();
    void ui_add();
    void ui_delete();
    void ui_update();
    void show_all(Utilizator* lista);
    void ui_add_friend();
    void ui_delete_friend();
    void ui_get_all_friendships(Friendship* lista2);
    void ui_add_message();
    void ui_delete_message();
    void ui_get_all_messages();
    void ui_add_event();
    void ui_delete_event();
    void ui_update_event();
    void ui_get_all_events(Event* lista3);
    void ui_add_participant();
    void ui_delete_participant();
    void ui_lista_participanti_event();
    void default_users();
    void ui_run_menu();
    //void default_messages();
};


#endif //PROIECT_SDA_UI_H
