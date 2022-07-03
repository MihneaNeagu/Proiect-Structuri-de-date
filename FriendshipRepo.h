//
// Created by mihne on 6/27/2022.
//

#ifndef PROIECT_SDA_FRIENDSHIPREPO_H
#define PROIECT_SDA_FRIENDSHIPREPO_H
#include "Friendship.h"
#include "Utilizator.h"
using namespace std;

class FriendshipRepo {
private:
    Array<Friendship> friendships;
public:
    FriendshipRepo();
    ~FriendshipRepo();
    void add_friendship(Utilizator &u1, Utilizator &u2);
    void delete_friendship(Utilizator &u1, Utilizator &u2);
    int friendships_size();
    Friendship* get_all_friendships();
    bool friendship_exists(Utilizator &u1, Utilizator &u2);
};


#endif //PROIECT_SDA_FRIENDSHIPREPO_H
