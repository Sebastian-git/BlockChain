#include "Controller.h"

#include <iostream>
#include <string>

#include "Block.h"


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


    Block block;

    std::vector<std::string> data;
    data.push_back("name");
    data.push_back("pswd");
    data.push_back("rec");
    data.push_back("amount");

    block.generateBlock(data, "");

    /*
    controller.handleTransaction(data);

    if (controller.startConnection()) {
        controller.startGUI();
    }
    */
    return 0;
}