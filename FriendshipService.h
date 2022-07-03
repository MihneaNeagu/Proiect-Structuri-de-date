//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_FRIENDSHIPSERVICE_H
#define PROIECT_SDA_FRIENDSHIPSERVICE_H
#include "FriendshipRepo.h"
#include "Friendship.h"

class FriendshipService {
private:
    FriendshipRepo frrepo;
public:
    FriendshipService();
    ~FriendshipService();
    void add_friend(char* username1, int id1, char* username2, int id2);
    void delete_friend(char* username1, int id1, char* username2, int id2);
    int size();
    Friendship* get_all();
    bool friendship_exists(char* username1, int id1, char* username2, int id2);
    void add_message(char* mesaj, char *username1, int id1, char *username2, int id2);
    void delete_message(char* mesaj, char *username1, int id1, char *username2, int id2);
    char** get_all_messages(char *username1, int id1, char *username2, int id2);
    int size_messages(char *username1, int id1, char *username2, int id2);
};


#endif //PROIECT_SDA_FRIENDSHIPSERVICE_H
