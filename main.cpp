#include <iostream>
#include "Array.h"
#include "FriendshipService.h"
#include "UtilizatorService.h"
#include "EventService.h"
#include "UI.h"
int main() {
    UI userinterface;
    userinterface.default_users();
    //userinterface.default_messages();
    userinterface.ui_run_menu();

    return 0;
}
