#include "GUI.h"
#include "Controller.h"
#include <iostream>

GUI::GUI(Controller* controller) : windowSize(sf::Vector2f(1200, 800)), margin(20), usernameLabel(), usernameTextbox(this), passwordLabel(), passwordTextbox(this), recipientLabel(), recipientTextbox(this), quantityLabel(), quantityTextbox(this), dollarLabel(), controller(controller) {}

void GUI::handleTransaction() {
    data.push_back(usernameTextbox.getText());
    data.push_back(passwordTextbox.getText());
    data.push_back(recipientTextbox.getText());
    data.push_back(quantityTextbox.getText());
    controller->handleTransaction(data);
    data.clear();
}

void GUI::display() {

    sf::RenderWindow window(sf::VideoMode((int)windowSize.x, (int)windowSize.y), "Crypto Wallet");

    float labelPosX = windowSize.x / (float)15;

    float boxSizeX = windowSize.x / 2;
    float boxSizeY = windowSize.y / (float)15;



    // Username GUI components
    usernameLabel.setText("Username");
    usernameLabel.setPos(sf::Vector2f(labelPosX, windowSize.y / 15));

    usernameTextbox.setPos(sf::Vector2f(usernameLabel.getBounds().width + usernameLabel.getPos().x + margin, usernameLabel.getPos().y));
    usernameTextbox.setBoxSize(sf::Vector2f(boxSizeX, boxSizeY));



    // Password GUI components
    passwordLabel.setText("Password");
    passwordLabel.setPos(sf::Vector2f(labelPosX, windowSize.y / 4));

    passwordTextbox.setPos(sf::Vector2f(passwordLabel.getBounds().width + passwordLabel.getPos().x + margin, passwordLabel.getPos().y));
    passwordTextbox.setBoxSize(sf::Vector2f(boxSizeX, boxSizeY));



    // Recipient GUI components
    recipientLabel.setText("Recipient");
    recipientLabel.setPos(sf::Vector2f(labelPosX, windowSize.y / 2.4f));

    recipientTextbox.setPos(sf::Vector2f(recipientLabel.getBounds().width + recipientLabel.getPos().x + margin, recipientLabel.getPos().y));
    recipientTextbox.setBoxSize(sf::Vector2f(boxSizeX, boxSizeY));



    // Quantity GUI components
    quantityLabel.setText("Quantity");
    quantityLabel.setPos(sf::Vector2f(labelPosX, windowSize.y / 1.7f));
   
    quantityTextbox.setPos(sf::Vector2f(quantityLabel.getBounds().width + quantityLabel.getPos().x + margin, quantityLabel.getPos().y));
    quantityTextbox.setBoxSize(sf::Vector2f(boxSizeX, windowSize.y / 15));
    quantityTextbox.setTextMargin(40);

    dollarLabel.setText("$");
    dollarLabel.setPos(sf::Vector2f(quantityTextbox.getPos().x + 10, quantityTextbox.getPos().y));



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            usernameTextbox.addEventHandler(window, event);
            passwordTextbox.addEventHandler(window, event);
            recipientTextbox.addEventHandler(window, event);
            quantityTextbox.addEventHandler(window, event);
        }

        usernameTextbox.update();
        passwordTextbox.update();
        recipientTextbox.update();
        quantityTextbox.update();

        window.clear();

        window.draw(usernameTextbox);
        window.draw(usernameLabel);

        window.draw(passwordTextbox);
        window.draw(passwordLabel);

        window.draw(recipientLabel);
        window.draw(recipientTextbox);

        window.draw(quantityLabel);
        window.draw(quantityTextbox);
        window.draw(dollarLabel);

        window.display();
    }
}