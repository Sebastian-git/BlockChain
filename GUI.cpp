#include "GUI.h"
#include "Controller.h"
#include <iostream>
#include <ctime>

#include <boost/random.hpp>

namespace bmp = boost::multiprecision;

GUI::GUI(Controller* controller) : windowSize(sf::Vector2f(1300, 800)), margin(20), usernameLabel(), usernameTextbox(this), passwordLabel(), passwordTextbox(this), recipientLabel(), recipientTextbox(this), quantityLabel(), quantityTextbox(this), dollarLabel(), controller(controller), submitButton(this), state(true), toggleButton(this), rsaExplanation(), primeOne(), primeTwo(), guessCountOne(), guessCountTwo(), startButton(this), rsaThreadP(), rsaThreadQ(), explanationThread(), n(), rsaThreadN(), clock(), delay(5), keysLabel(), rsaThreadKeys(), keysLabel2(), isPresenting(false) {}

GUI::~GUI() {
    explanationThread.detach();
    rsaThreadP.detach();
    rsaThreadQ.detach();
    rsaThreadN.detach();
    rsaThreadKeys.detach();
    std::exit(0);
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



    // RSA description of each step GUI component
    rsaExplanation.setPos(sf::Vector2f(300, windowSize.y / 10));

    // RSA random prime 1 (P) GUI component 
    primeOne.setPos(sf::Vector2f(20, windowSize.y / 15));
    primeOne.setTextSize(20);

    // RSA random prime 2 (Q) GUI component 
    primeTwo.setPos(sf::Vector2f(windowSize.x - 510, windowSize.y / 15));
    primeTwo.setTextSize(20);

    // RSA guess count of prime 1 (P)
    guessCountOne.setPos(sf::Vector2f(20, windowSize.y / 20));
    guessCountOne.setTextSize(30);

    // RSA guess count of prime 2 (Q)
    guessCountTwo.setPos(sf::Vector2f(windowSize.x - 510, windowSize.y / 20));
    guessCountTwo.setTextSize(30);

    // RSA n and phi_n labels
    n.setPos(sf::Vector2f(50, 50));
    n.setTextSize(20);

    // RSA key generation explanation
    keysLabel.setPos(sf::Vector2f(50, 50));
    keysLabel.setTextSize(30);
    keysLabel2.setPos(sf::Vector2f(50, 200));
    keysLabel2.setTextSize(30);

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

            window.draw(rsaExplanation);

            window.draw(primeOne);
            window.draw(primeTwo);
            
            window.draw(guessCountOne);
            window.draw(guessCountTwo);

            window.draw(n);

            window.draw(keysLabel);
            window.draw(keysLabel2);

            window.draw(startButton);

        }

        window.draw(toggleButton);


        window.display();
    }
}

void GUI::RSAExplanation() {

    isPresenting = true;

    explanationThread = std::thread(&GUI::explanation, this);
}

void GUI::explanation() {

    bmp::int1024_t two = 2;

    bmp::int1024_t max = bmp::pow(two, 1023) - 1;
    bmp::int1024_t min = bmp::pow(two, 1022) + 1;

    bmp::int1024_t P;
    bmp::int1024_t Q;
    bmp::int1024_t phiN;
    bmp::int1024_t e;
    bmp::int1024_t d;

    bmp::int1024_t randNum;

    // Step 1 explanation
    rsaExplanation.setText("The first step in RSA is to generate\ntwo random large prime numbers");
    clock.restart();
    while (clock.getElapsedTime().asSeconds() != delay) { }
    rsaExplanation.setText("");

    // Generate random primes
    rsaThreadP = std::thread(&GUI::randPrime, this, max, min, randNum, &primeOne, &guessCountOne, &P);
    rsaThreadQ = std::thread(&GUI::randPrime, this, max, min, randNum, &primeTwo, &guessCountTwo, &Q);

    rsaThreadP.join();
    rsaThreadQ.join();

    clock.restart();
    while (clock.getElapsedTime().asSeconds() != delay) {}
    primeOne.setText("");
    primeTwo.setText("");
    guessCountOne.setText("");
    guessCountTwo.setText("");

    // Step 2 explanation
    rsaExplanation.setText("The second step in RSA is to\ncalculate \"n\" and \"phi_n\"");
    clock.restart();
    while (clock.getElapsedTime().asSeconds() != delay) {}
    rsaExplanation.setText("");

    // Generate n and phi_n
    rsaThreadN = std::thread(&GUI::phi_n, this, P, Q, &phiN);
    rsaThreadN.join();

    // Step 3 explanation
    rsaExplanation.setPos(sf::Vector2f(100, windowSize.y / 10));
    rsaExplanation.setText("");
    rsaExplanation.setText("The third step is to find public and private keys\n");
    clock.restart();
    while (clock.getElapsedTime().asSeconds() != delay) {}
    rsaExplanation.setText("");

    // Generate keys
    rsaThreadKeys = std::thread(&GUI::keys, this, phiN, &e, &d);
    isPresenting = false;
}

void GUI::randPrime(boost::multiprecision::int1024_t max, boost::multiprecision::int1024_t min, boost::multiprecision::int1024_t randNum, TextLabel* prime, TextLabel* guessCount, bmp::int1024_t* val) {
    int i = 0;
    while (true) {
        randNum = (generator() % (max - min) + min) | 1;

        if (randNum.str()[randNum.str().size() - 1] == '5') {
            continue;
        }

        if (isPrime(randNum, 5)) {
            break;
        }

        std::string randNumStr = randNum.str();
        for (int i = 0; i < randNumStr.size(); i++) {
            if (i % 45 == 0) {
                randNumStr.insert(i, "\n");
            }
        }
        ++i;
        prime->setText(randNumStr);
        guessCount->setText(std::to_string(i));

    }
    *val = randNum;
}

bool GUI::millerTest(bmp::int1024_t d, bmp::int1024_t n) {

    bmp::int1024_t a = 2 + rand() % (n - 4);

    bmp::int1024_t x = bmp::powm(a, d, n);

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

bool GUI::isPrime(bmp::int1024_t n, int k) {

    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    bmp::int1024_t d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!millerTest(d, n))
            return false;

    return true;
}

void GUI::phi_n(bmp::int1024_t P, bmp::int1024_t Q, bmp::int1024_t* phiN) {

    std::string PQ = (P * Q).str();
    for (int i = 0; i < PQ.size(); i++) {
        if (i % 30 == 0) {
            PQ.insert(i, "\n");
        }
    }

    n.setText("N = P * Q = \n" + PQ);
    clock.restart();
    while (clock.getElapsedTime().asSeconds() != delay) { }

    *phiN = (P - 1) * (Q - 1);
    std::string phi_nStr = (*phiN).str();

    for (int i = 0; i < phi_nStr.size(); i++) {
        if (i % 60 == 0) {
            phi_nStr.insert(i, "\n");
        }
    }

    n.setPos(sf::Vector2f(100, 200));
    n.setTextSize(30);
    n.setText("phi_n is calculated using the simple formula:   phi_n = (p - 1)(q - 1)\n=" + phi_nStr);
    clock.restart();
    while (clock.getElapsedTime().asSeconds() != delay) {}
    n.setText("");
}

void GUI::keys(bmp::int1024_t phiN, bmp::int1024_t* e, bmp::int1024_t* d) {

    keysLabel.setText("The first key is a value between 1 and phi_n - 1,\nthat also doesn't share any common factors with phi_n.\n");
    
    bmp::int1024_t i = 2;//generator() / (2 * rand() % 1000);
    bmp::int1024_t publicKey;

    while (gcd(i, phiN) != 1) {
        i++;
    }
    
    publicKey = i;
    std::string publicKeyStr = publicKey.str();
    for (int i = 0; i < publicKeyStr.size(); i++) {
        if (i % 50 == 0) {
            publicKeyStr.insert(i, "\n");
        }
    }

    keysLabel2.setPos(sf::Vector2f(50, 300));
    keysLabel2.setText("Your public key is now:\n" + publicKeyStr);

    clock.restart();
    while (clock.getElapsedTime().asSeconds() != delay) {}

    keysLabel2.setText("");
    keysLabel2.setPos(sf::Vector2f(50, 300));
    keysLabel.setText("The private key (d) is more difficult to find. \nIt is calculated such that (e * d)^phi_n = 1, or the formula\nd = (k * phi_n + 1) / e\nWhere k is a number that starts from one and increases\nuntil the right value is found.\n");

    clock.restart();
    while (clock.getElapsedTime().asSeconds() != delay) {}

    bmp::int1024_t k = 1;
    bmp::int1024_t privateKey;

    while ((k * phiN + 1) % publicKey != 0) {
        k++;
    }

    privateKey = (k * phiN + 1) / publicKey;

    std::string privateKeyStr = privateKey.str();

    for (int i = 0; i < privateKeyStr.size(); i++) {
        if (i % 70 == 0) {
            privateKeyStr.insert(i, "\n");
        }
    }

    keysLabel2.setText("Private key:\n" + privateKeyStr);

    clock.restart();
    while (clock.getElapsedTime().asSeconds() != delay) {}

    keysLabel.setText("");
    keysLabel2.setText("");
}

bmp::int1024_t GUI::gcd(bmp::int1024_t a, bmp::int1024_t b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}