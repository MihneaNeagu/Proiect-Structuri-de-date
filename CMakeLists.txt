cmake_minimum_required(VERSION 3.21)
project(PROIECT_SDA)

set(CMAKE_CXX_STANDARD 14)

add_executable(PROIECT_SDA main.cpp Utilizator.cpp Utilizator.h Array.h UtilizatorRepo.cpp UtilizatorRepo.h UtilizatorService.cpp UtilizatorService.h Validator.cpp Validator.h Dictionary.h Nod.h Friendship.cpp Friendship.h "../../PROIECTE OOP 2/PoiectSDA/cmake-build-debug/FriendshipRepo.h" FriendshipRepo.cpp FriendshipRepo.h FriendshipService.cpp FriendshipService.h Event.cpp Event.h EventRepo.cpp EventRepo.h EventService.cpp EventService.h UI.cpp UI.h)
