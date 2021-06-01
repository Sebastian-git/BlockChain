#include "Controller.h"

#include <iostream>
#include <string>


int main() {
    /*
    SHA256 sha;
    std::string target = sha("test");

    int nonce = 0;
    std::string arrowStr = "test2";
    std::string arrow = sha(arrowStr);

    while (arrow[0] != '0') {
        arrowStr += std::to_string(nonce);
        arrow = sha(arrowStr);
        std::cout << "Attempt " << nonce << " : " << arrow << "\n";
        nonce++;
    }

    std::cout << "\n\n SECOND TRY \n\n";
    
    std::string prev;

    while (arrow[0] != '0' || arrow[1] != '0') {
        arrowStr += std::to_string(nonce);
        arrow = sha(arrowStr);
        std::cout << "Attempt " << nonce << ": "  << arrow << "\n";
        nonce++;
    }

    /*
    while (arrow[0] != '0' || arrow[1] != '0' || arrow[2] != '0' || arrow[3] != '0') {
        arrowStr += std::to_string(nonce);
        arrow = sha(arrowStr);
        std::cout << "Attempt " << nonce << ": " << arrow << "\n";
        nonce++;
    }
    */
    
    Controller controller;

    if (controller.startConnection()) {
        controller.startGUI();
    }

    return 0;
}