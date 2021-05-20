<<<<<<< HEAD
#include "GUI.h"
#include "TextBox.h"
#include "TextLabel.h"
#include <iostream>

GUI::GUI() : windowSize(sf::Vector2f(1200, 800)), margin(20) {

}

void GUI::display() {

    sf::RenderWindow window(sf::VideoMode((int)windowSize.x, (int)windowSize.y), "Crypto Wallet");

    float labelPosX = windowSize.x / (float)15;


    // Username GUI components
    TextLabel usernameLabel = TextLabel();
    usernameLabel.setText("Username");
    usernameLabel.setPos(sf::Vector2f(labelPosX, windowSize.y / 15));

    TextBox usernameTextbox = TextBox();
    usernameTextbox.setPos(sf::Vector2f(usernameLabel.getBounds().width + usernameLabel.getPos().x + margin, usernameLabel.getPos().y));
    usernameTextbox.setBoxSize(sf::Vector2f(windowSize.x / 2, windowSize.y / 15));



    // Recipient GUI components
    TextLabel recipientLabel = TextLabel();
    recipientLabel.setText("Recipient");
    recipientLabel.setPos(sf::Vector2f(labelPosX, windowSize.y / 4));

    TextBox recipientTextbox = TextBox();
    recipientTextbox.setPos(sf::Vector2f(recipientLabel.getBounds().width + recipientLabel.getPos().x + margin, recipientLabel.getPos().y));
    recipientTextbox.setBoxSize(sf::Vector2f(windowSize.x / 2, windowSize.y / 15));



    // Quantity GUI components
    TextLabel quantityLabel = TextLabel();
    quantityLabel.setText("Quantity");
    quantityLabel.setPos(sf::Vector2f(labelPosX, windowSize.y / (float)2.15));
   
    TextBox quantityTextbox = TextBox();
    quantityTextbox.setPos(sf::Vector2f(quantityLabel.getBounds().width + quantityLabel.getPos().x + margin, quantityLabel.getPos().y));
    quantityTextbox.setBoxSize(sf::Vector2f(windowSize.x / 2, windowSize.y / 15));
    quantityTextbox.setTextMargin(40);

    TextLabel dollarLabel = TextLabel();
    dollarLabel.setText("$");
    dollarLabel.setPos(sf::Vector2f(quantityTextbox.getPos().x + 10, quantityTextbox.getPos().y));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            usernameTextbox.addEventHandler(window, event);
            recipientTextbox.addEventHandler(window, event);
            quantityTextbox.addEventHandler(window, event);
        }

        usernameTextbox.update();
        recipientTextbox.update();
        quantityTextbox.update();

        window.clear();

        window.draw(usernameTextbox);
        window.draw(usernameLabel);

        window.draw(recipientLabel);
        window.draw(recipientTextbox);

        window.draw(quantityLabel);
        window.draw(quantityTextbox);
        window.draw(dollarLabel);

        window.display();
    }
=======
#include "GUI.h"
#include "TextBox.h"
#include "TextLabel.h"
#include <iostream>

GUI::GUI() : windowSize(sf::Vector2f(1200, 800)), margin(20) {

}

void GUI::display() {

    sf::RenderWindow window(sf::VideoMode((int)windowSize.x, (int)windowSize.y), "Crypto Wallet");

    float labelPosX = windowSize.x / (float)15;


    // Username GUI components
    TextLabel usernameLabel = TextLabel();
    usernameLabel.setText("Username");
    usernameLabel.setPos(sf::Vector2f(labelPosX, windowSize.y / 15));

    TextBox usernameTextbox = TextBox();
    usernameTextbox.setPos(sf::Vector2f(usernameLabel.getBounds().width + usernameLabel.getPos().x + margin, usernameLabel.getPos().y));
    usernameTextbox.setBoxSize(sf::Vector2f(windowSize.x / 2, windowSize.y / 15));



    // Recipient GUI components
    TextLabel recipientLabel = TextLabel();
    recipientLabel.setText("Recipient");
    recipientLabel.setPos(sf::Vector2f(labelPosX, windowSize.y / 4));

    TextBox recipientTextbox = TextBox();
    recipientTextbox.setPos(sf::Vector2f(recipientLabel.getBounds().width + recipientLabel.getPos().x + margin, recipientLabel.getPos().y));
    recipientTextbox.setBoxSize(sf::Vector2f(windowSize.x / 2, windowSize.y / 15));



    // Quantity GUI components
    TextLabel quantityLabel = TextLabel();
    quantityLabel.setText("Quantity");
    quantityLabel.setPos(sf::Vector2f(labelPosX, windowSize.y / (float)2.15));
   
    TextBox quantityTextbox = TextBox();
    quantityTextbox.setPos(sf::Vector2f(quantityLabel.getBounds().width + quantityLabel.getPos().x + margin, quantityLabel.getPos().y));
    quantityTextbox.setBoxSize(sf::Vector2f(windowSize.x / 2, windowSize.y / 15));
    quantityTextbox.setTextMargin(40);

    TextLabel dollarLabel = TextLabel();
    dollarLabel.setText("$");
    dollarLabel.setPos(sf::Vector2f(quantityTextbox.getPos().x + 10, quantityTextbox.getPos().y));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            usernameTextbox.addEventHandler(window, event);
            recipientTextbox.addEventHandler(window, event);
            quantityTextbox.addEventHandler(window, event);
        }

        usernameTextbox.update();
        recipientTextbox.update();
        quantityTextbox.update();

        window.clear();

        window.draw(usernameTextbox);
        window.draw(usernameLabel);

        window.draw(recipientLabel);
        window.draw(recipientTextbox);

        window.draw(quantityLabel);
        window.draw(quantityTextbox);
        window.draw(dollarLabel);

        window.display();
    }
>>>>>>> 5ffb06da6f3de529ca20d021369c8a15fbb79e87
}