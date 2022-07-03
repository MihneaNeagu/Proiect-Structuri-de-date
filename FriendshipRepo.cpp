//
// Created by mihne on 6/27/2022.
//

#include "FriendshipRepo.h"


FriendshipRepo::FriendshipRepo() {

}

FriendshipRepo::~FriendshipRepo() {

}

void FriendshipRepo::add_friendship(Utilizator &u1, Utilizator &u2) {
    Friendship f(u1, u2);
    this->friendships.add(f);
}

void FriendshipRepo::delete_friendship(Utilizator &u1, Utilizator &u2) {
    Friendship f(u1, u2);
    this->friendships.remove(f);
}

int FriendshipRepo::friendships_size() {
    return this->friendships.size();
}

Friendship *FriendshipRepo::get_all_friendships() {
    return this->friendships.get_array();
}

bool FriendshipRepo::friendship_exists(Utilizator &u1, Utilizator &u2) {
    Friendship f(u1, u2);
    for(int i = 0; i < friendships_size(); i++)
        if(f == get_all_friendships()[i])
            return true;
    return false;
}