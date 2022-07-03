//
// Created by mihne on 6/27/2022.
//

#include "FriendshipService.h"


FriendshipService::FriendshipService() {

}

FriendshipService::~FriendshipService() {

}

void FriendshipService::add_friend(char* username1, int id1, char* username2, int id2) {
    Utilizator u1(username1, id1);
    Utilizator u2(username2, id2);
    this->frrepo.add_friendship(u1, u2);
}

bool FriendshipService::friendship_exists(char *username1, int id1, char *username2, int id2) {
    Utilizator u1(username1, id1);
    Utilizator u2(username2, id2);
    return this->frrepo.friendship_exists(u1, u2);
}

void FriendshipService::add_message(char* mesaj, char *username1, int id1, char *username2, int id2) {
    Utilizator u1(username1, id1);
    Utilizator u2(username2, id2);
    Friendship f(u1, u2);
    f.add_message(mesaj);
}

void FriendshipService::delete_message(char* mesaj, char *username1, int id1, char *username2, int id2) {
    Utilizator u1(username1, id1);
    Utilizator u2(username2, id2);
    Friendship f(u1, u2);
    f.delete_message(mesaj);
}

void FriendshipService::delete_friend(char *username1, int id1, char *username2, int id2) {
    Utilizator u1(username1, id1);
    Utilizator u2(username2, id2);
    this->frrepo.delete_friendship(u1, u2);
}

int FriendshipService::size() {
    return this->frrepo.friendships_size();
}

Friendship* FriendshipService::get_all() {
    return this->frrepo.get_all_friendships();
}

char** FriendshipService::get_all_messages(char *username1, int id1, char *username2, int id2) {
    Utilizator u1(username1, id1);
    Utilizator u2(username2, id2);
    Friendship f(u1, u2);
    return f.get_all_messages();
}

int FriendshipService::size_messages(char *username1, int id1, char *username2, int id2) {
    Utilizator u1(username1, id1);
    Utilizator u2(username2, id2);
    Friendship f(u1, u2);
    return f.size_messages();
}