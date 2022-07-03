//
// Created by mihne on 6/28/2022.
//

#include "UI.h"


#include "cstring"
#include <iostream>
#include "vector"

using namespace std;

UI::UI() {

}

UI::UI(const UtilizatorService &service) {
    this->utilizator_service = service;
}

UI::~UI() {

}

void UI::ui_add() {
    Utilizator u;
    cin >> u;
    this->utilizator_service.add_utilizator(u.get_id(),
                                            u.get_username());
}

void UI::ui_delete() {
    Utilizator u;
    cin >> u;
    this->utilizator_service.delete_utilizator(u.get_id(),
                                               u.get_username());
}

void UI::ui_update() {
    Utilizator vechi;
    Utilizator nou;
    cin >> vechi;
    cin >> nou;
    this->utilizator_service.update_utilizator(vechi.get_id(),
                                               vechi.get_username(),
                                               nou.get_id(),
                                               nou.get_username());
}

void UI::show_all(Utilizator* lista) {
    for(int i = 0; i < this->utilizator_service.size(); i++)
        cout << lista[i] << endl;
}

void UI::ui_add_friend() {
    Utilizator u1, u2;
    cout<<"Prietenia se va face intre utilizatorul : ";
    cin >> u1;
    cout << "Si utilizatorul: ";
    cin >> u2;
    if(not this->fr_service.friendship_exists(u1.get_username(),
                                                u1.get_id(),
                                                u2.get_username(),
                                                u2.get_id()))
        fr_service.add_friend(u1.get_username(),
                              u1.get_id(),
                              u2.get_username(),
                              u2.get_id());
    else
        cout << "Exista deja o prietenie intre cei 2 utilizatori" << endl;
}

void UI::ui_delete_friend() {
    Utilizator u1, u2;
    cout << "Dati primul user: ";
    cin >> u1;
    cout << "Dati al doilea user: ";
    cin >> u2;
    if(this->fr_service.friendship_exists(u1.get_username(),
                                          u1.get_id(),
                                          u2.get_username(),
                                          u2.get_id()))
        this->fr_service.delete_friend(u1.get_username(),
                                       u1.get_id(),
                                       u2.get_username(),
                                       u2.get_id());
    else
        cout << "Nu exista o prietenie intre cei 2 utilizatori" << endl;
}

void UI::ui_get_all_friendships(Friendship *lista2) {
    for(int i = 0; i < fr_service.size(); i++)
        cout << lista2[i].get_utilizator1().get_username()
        << " este prieten cu "
        << lista2[i].get_utilizator2().get_username() << endl;
}

void UI::ui_add_message() {
    Utilizator u1, u2;
    cin >> u1;
    cin >> u2;
    char *mesaj;
    mesaj = new char[777];
    cout << "Dati mesaj: " << endl;
    cin.getline(mesaj, 777, '.');
    if (this->fr_service.friendship_exists(u1.get_username(),
                                           u1.get_id(),
                                           u2.get_username(),
                                           u2.get_id())){
        Friendship friendship(u1, u2);
        for (int i = 0; i < this->fr_service.size(); i++)
            if (this->fr_service.get_all()[i] == friendship)
                fr_service.get_all()[i].add_message(mesaj);
    }
    else
        cout << "Nu se poate adauga mesaj deoarece cei doi utilizatori nu sunt prieteni" << endl;
    cout << endl;
}

void UI::ui_delete_message() {
    Utilizator u1, u2;
    cin >> u1;
    cin >> u2;
    char *mesaj ;
    mesaj =  new char[1000];
    cout << "Dati mesaj: ";
    cin.getline(mesaj, 1000, '.');
    if(this->fr_service.friendship_exists(u1.get_username(),
                                          u1.get_id(),
                                          u2.get_username(),
                                          u2.get_id())){
        Friendship friendship(u1, u2);
        for(int i = 0; i < this->fr_service.size(); i++)
            if(this->fr_service.get_all()[i] == friendship)
                fr_service.get_all()[i].delete_message(mesaj);
    }
    else
        cout << "Nu se poate sterge mesajul deoarece cei doi utilizatori nu sunt prieteni" << endl;
}

void UI::ui_get_all_messages() {
    Utilizator u1, u2;
    cin >> u1;
    cin >> u2;
    if(this->fr_service.friendship_exists(u1.get_username(),
                                          u1.get_id(),
                                          u2.get_username(),
                                          u2.get_id())) {
        Friendship friendship(u1, u2);
        for(int a = 0; a < fr_service.size(); a++)
            if(fr_service.get_all()[a] == friendship) {
                for(int b = 0; b < fr_service.get_all()[a].size_messages(); b++)
                    if(b % 2 == 0){
                        cout << u1.get_username() << ": ";
                        cout << fr_service.get_all()[a].get_all_messages()[b] << endl;
                    }
                    else
                    {
                        cout << u2.get_username() << ": ";
                        cout << fr_service.get_all()[a].get_all_messages()[b] << endl;
                    }

            }
    }
    else
        cout << "Nu se pot recupera mesaje deoarece cei doi utilizatori nu sunt prieteni" << endl;
    cout << endl;
}

void UI::ui_add_event() {
    Event event;
    cin >> event;
    this->event_service.add_event(event.get_id(), event.get_nume_event());
}

void UI::ui_delete_event() {
    Event event;
    cin >> event;
    this->event_service.delete_event(event.get_id(), event.get_nume_event());
}

void UI::ui_update_event() {
    Event event1, event2;
    cin >> event1;
    cout << endl;
    cin >> event2;
    this->event_service.update_event(event1.get_id(), event1.get_nume_event(), event2.get_id(), event2.get_nume_event());
}

void UI::ui_get_all_events(Event *lista) {
    for(int i = 0; i < this->event_service.size(); i++)
        cout << "Event: ( " << lista[i].get_nume_event() << " , " << lista[i].get_id() << " )" << endl;
    cout << endl;
}

void UI::ui_add_participant() {
    Event event;
    cin >> event;
    if(this->event_service.event_exists(event.get_id(),
                                        event.get_nume_event())){
        Utilizator utilizator;
        cin >> utilizator;
        if(this->utilizator_service.exista_user(utilizator.get_id(),
                                                utilizator.get_username())){
            for(int i = 0; i < this->event_service.size(); i++)
                if(this->event_service.get_all()[i] == event){
                    this->event_service.get_all()[i].add_utilizator(utilizator);
                    i=this->event_service.size()+1;
                }

        }
        else
            cout << "Nu exista utilizatorul dat" << endl;
    }
    else
        cout << "Nu exista eventul dat" << endl;
    cout << endl;
}

void UI::ui_delete_participant() {
    Event event;
    cin >> event;
    if(this->event_service.event_exists(event.get_id(),
                                        event.get_nume_event())){
        Utilizator user;
        cin >> user;
        if(this->utilizator_service.exista_user(user.get_id(),
                                                user.get_username())){
            for(int i = 0; i < this->event_service.size(); i++)
                if(this->event_service.get_all()[i] == event){
                    this->event_service.get_all()[i].delete_utilizator(user);
                    i=this->event_service.size()+1;
                }

        }
        else
            cout << "Nu exista utilizatorul dat" << endl;
    }
    else
        cout << "Nu exista eventul dat" << endl;
    cout << endl;
}

void UI::ui_lista_participanti_event() {
    Event event;
    cin >> event;
    if(this->event_service.event_exists(event.get_id(),
                                        event.get_nume_event())){
        for(int a = 0; a < this->event_service.size(); a++)
            if(this->event_service.get_all()[a] == event)
                for(int b = 0; b < this->event_service.get_all()[a].get_nr_utilizatori(); b++)
                    cout << this->event_service.get_all()[a].get_lista_utilizatori()[b].get_id()
                    <<" "<<this->event_service.get_all()[a].get_lista_utilizatori()[b].get_username()<< endl;
    }
    else
        cout << "Eventul dat nu exista" << endl;
    cout << endl;
}

void UI::ui_run_menu() {
    while (true){
        cout << "1. Adauga utilizator: ";
        cout << "2. Sterge utilizator: ";
        cout << "3. Modifica utilizator: ";
        cout << "4. Afisare useri: ";
        cout << "5. Adauga prieten: ";
        cout << "6. Sterge prieten: ";
        cout << "7. Lista prietenii: ";
        cout << "8. Adauga mesaj: ";
        cout << "9. Sterge mesaj: ";
        cout << "10. Afiseaza mesaje: ";
        cout << "11. Adauga eveniment: ";
        cout << "12. Sterge eveniment: ";
        cout << "13. Modifica eveniment: ";
        cout << "14. Afiseaza evenimente: ";
        cout << "15. Adauga participant la eveniment: ";
        cout << "16. Sterge eveniment de la eveniment: ";
        cout << "17. Afiseaza lista participantilor de la eveniment: ";
        cout << "0. Iesire" << endl;
        cout << endl;

        int optiune;
        cout << "Dati optiune: ";
        cin >> optiune;
        cout << endl;

        try {
            if (optiune == 1)
                ui_add();
            else if (optiune == 2)
                ui_delete();
            else if (optiune == 3)
                ui_update();
            else if (optiune == 4)
                show_all(this->utilizator_service.get_all());
            else if (optiune == 5)
                ui_add_friend();
            else if (optiune == 6)
                ui_delete_friend();
            else if (optiune == 7)
                ui_get_all_friendships(fr_service.get_all());
            else if (optiune == 8)
                ui_add_message();
            else if (optiune == 9)
                ui_delete_message();
            else if (optiune == 10)
                ui_get_all_messages();
            else if (optiune == 11)
                ui_add_event();
            else if (optiune == 12)
                ui_delete_event();
            else if (optiune == 13)
                ui_update_event();
            else if (optiune == 14)
                ui_get_all_events(this->event_service.get_all());
            else if(optiune == 15)
                ui_add_participant();
            else if(optiune == 16)
                ui_delete_participant();
            else if(optiune == 17)
                ui_lista_participanti_event();
            else if (optiune == 0)
                break;
            else
                cout << "Optiune gresita!";
        }
        catch (UtilizatorRepoExceptii &exc1){
            cout << exc1 << endl;
        }
        catch (ExceptieValidator &exc2){
            cout << exc2 << endl;
        }
    }
}

void UI::default_users() {
    Utilizator u1("Mihnea", 1);
    Utilizator u2("Miruna", 2);
    Utilizator u3("Mihaela", 3);
    Utilizator u4("Marian", 4);
    Utilizator u5("Mircea", 5);
    Utilizator u6("Dan", 6);
    Utilizator u7("Stefan", 7);
    Utilizator u8("Alex", 8);
    Utilizator u9("Maria", 9);
    Utilizator u10("Andra", 10);
    Utilizator u11("Razvan", 11);
    Utilizator u12("Alexia", 12);
    Utilizator u13("Toto", 13);
    Utilizator u14("Rares", 14);
    Utilizator u15("Ronaldo", 15);

    utilizator_service.add_utilizator(u1.get_id(),
                                      u1.get_username());
    utilizator_service.add_utilizator(u2.get_id(),
                                      u2.get_username());
    utilizator_service.add_utilizator(u3.get_id(),
                                      u3.get_username());
    utilizator_service.add_utilizator(u4.get_id(),
                                      u4.get_username());
    utilizator_service.add_utilizator(u5.get_id(),
                                      u5.get_username());
    utilizator_service.add_utilizator(u6.get_id(),
                                      u6.get_username());
    utilizator_service.add_utilizator(u7.get_id(),
                                      u7.get_username());
    utilizator_service.add_utilizator(u8.get_id(),
                                      u8.get_username());
    utilizator_service.add_utilizator(u9.get_id(),
                                      u9.get_username());
    utilizator_service.add_utilizator(u10.get_id(),
                                      u10.get_username());
    utilizator_service.add_utilizator(u11.get_id(),
                                      u11.get_username());
    utilizator_service.add_utilizator(u12.get_id(),
                                      u12.get_username());
    utilizator_service.add_utilizator(u13.get_id(),
                                      u13.get_username());
    utilizator_service.add_utilizator(u14.get_id(),
                                      u14.get_username());
    utilizator_service.add_utilizator(u15.get_id(),
                                      u15.get_username());

    fr_service.add_friend(u1.get_username(),u1.get_id(),u2.get_username(),u2.get_id());
    fr_service.add_friend(u2.get_username(),u2.get_id(),u7.get_username(),u7.get_id());
    fr_service.add_friend(u3.get_username(),u3.get_id(),u9.get_username(),u9.get_id());
    fr_service.add_friend(u4.get_username(),u4.get_id(),u2.get_username(),u2.get_id());
    fr_service.add_friend(u5.get_username(),u5.get_id(),u14.get_username(),u14.get_id());
    fr_service.add_friend(u7.get_username(),u7.get_id(),u1.get_username(),u1.get_id());
    fr_service.add_friend(u8.get_username(),u8.get_id(),u10.get_username(),u10.get_id());
    fr_service.add_friend(u9.get_username(),u9.get_id(),u11.get_username(),u11.get_id());
    fr_service.add_friend(u10.get_username(),u10.get_id(),u12.get_username(),u12.get_id());
    fr_service.add_friend(u1.get_username(),u1.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u2.get_username(),u2.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u3.get_username(),u3.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u4.get_username(),u5.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u5.get_username(),u5.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u6.get_username(),u6.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u7.get_username(),u7.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u8.get_username(),u8.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u9.get_username(),u9.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u10.get_username(),u10.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u11.get_username(),u11.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u12.get_username(),u12.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u13.get_username(),u13.get_id(),u15.get_username(),u15.get_id());
    fr_service.add_friend(u14.get_username(),u14.get_id(),u15.get_username(),u15.get_id());
}

/*void UI::default_messages()
{
    fr_service.add_message("La multi ani!.","Mihnea",1,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Miruna",2,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Mihaela",3,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Marian",4,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Mircea",5,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Dan",6,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Stefan",7,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Alex",8,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Maria",9,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Andra",10,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Razvan",11,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Alexia",12,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Toto",13,"Ronaldo",15);
    fr_service.add_message("La multi ani!.","Rares",14,"Ronaldo",15);
};*/
