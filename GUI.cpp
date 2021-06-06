#include "GUI.h"
#include "Controller.h"
#include <iostream>
#include <ctime>

#include <boost/random.hpp>

GUI::GUI(Controller* controller) : windowSize(sf::Vector2f(1200, 800)), margin(20), usernameLabel(), usernameTextbox(this), passwordLabel(), passwordTextbox(this), recipientLabel(), recipientTextbox(this), quantityLabel(), quantityTextbox(this), dollarLabel(), controller(controller), submitButton(this), state(true), toggleButton(this), primeOne(), primeTwo(), startButton(this), rsaThread() {}

GUI::~GUI() {
    rsaThread.detach();
}

void GUI::handleTransaction() {
    data.push_back(usernameTextbox.getText());
    data.push_back(passwordTextbox.getText());
    data.push_back(recipientTextbox.getText());
    data.push_back(quantityTextbox.getText());
    controller->handleTransaction(data);
    data.clear();
}

void GUI::toggleState() {
    state = !state;
}

void GUI::display() {
    generator.seed(time(0));

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

    // Submit button GUI components
    submitButton.setText("Submit");
    submitButton.setBoxSize(sf::Vector2f(165, 50));
    sf::Vector2f prevPos = quantityLabel.getPos();
    submitButton.setPos(sf::Vector2f(labelPosX, prevPos.y + 150));

    // Transaction button GUI components
    toggleButton.setText("Toggle");
    toggleButton.setBoxSize(sf::Vector2f(150, 50));
    prevPos = submitButton.getPos();
    toggleButton.setPos(sf::Vector2f(prevPos.x + submitButton.getBoxSize().x * 1.5f, quantityLabel.getPos().y + 150));



    // RSA random prime 1 (P) GUI component 
    primeOne.setPos(sf::Vector2f(labelPosX, windowSize.y / 15));

    // RSA random prime 2 (Q) GUI component 
    primeTwo.setPos(sf::Vector2f(primeOne.getPos().x + 100, primeOne.getPos().y));

    // Start RSA explanation button GUI component
    startButton.setText("Start");
    startButton.setBoxSize(sf::Vector2f(120, 50));
    prevPos = quantityLabel.getPos();
    startButton.setPos(sf::Vector2f(labelPosX, prevPos.y + 150));


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
            submitButton.addEventHandler(window, event);
            toggleButton.addEventHandler(window, event);
            startButton.addEventHandler(window, event);
        }

        usernameTextbox.update();
        passwordTextbox.update();
        recipientTextbox.update();
        quantityTextbox.update();

        window.clear();

        if (state) { 

            window.draw(usernameTextbox);
            window.draw(usernameLabel);

            window.draw(passwordTextbox);
            window.draw(passwordLabel);

            window.draw(recipientLabel);
            window.draw(recipientTextbox);

            window.draw(quantityLabel);
            window.draw(quantityTextbox);
            window.draw(dollarLabel);

            window.draw(submitButton);
        }
        else {
            window.draw(primeOne);
            window.draw(primeTwo);

            window.draw(startButton);

        }

        window.draw(toggleButton);


        window.display();
    }
}

void GUI::RSAExplanation() {

    rsaThread = std::thread(&GUI::RSACalculations, this);
    
}

void GUI::RSACalculations() {
    namespace bmp = boost::multiprecision;

    bmp::int1024_t two = 2;

    bmp::int1024_t max = bmp::pow(two, 1023) - 1;
    bmp::int1024_t min = bmp::pow(two, 1022) + 1;

    bmp::int1024_t randNum;

    int guessNum = 0;

    while (true) {
        randNum = (generator() % (max - min) + min) | 1;

        if (randNum.str()[randNum.str().size() - 1] == '5') {
            continue;
        }

        if (isPrime(randNum, 5)) {
            std::cout << randNum << " is prime\n";
            std::cout << "It only took " << guessNum << " guesses\n";
            break;
        }
        std::cout << randNum << " is not prime\n\n";
        ++guessNum;
        primeOne.setText(randNum.str());
    }
}

bool GUI::millerTest(boost::multiprecision::int1024_t d, boost::multiprecision::int1024_t n) {

    boost::multiprecision::int1024_t a = 2 + rand() % (n - 4);

    boost::multiprecision::int1024_t x = boost::multiprecision::powm(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)      return false;
        if (x == n - 1)    return true;
    }

    return false;
}

bool GUI::isPrime(boost::multiprecision::int1024_t n, int k) {

    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    boost::multiprecision::int1024_t d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return false;

    return true;
}