#include <iostream>
#include "Controller.h"

int main() {

    std::cout << "S for server, C for client: ";
    char mode;
    std::cin >> mode;
    
    Controller controller;
    controller.startConnection(mode);
    controller.startGUI();

    return 0;
}