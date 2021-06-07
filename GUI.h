#pragma once
#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "TextLabel.h"
#include "Button.h"
#include <vector>
#include <string>
#include <thread>
#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>

class Controller;

class GUI {

public:
	
	GUI(Controller* controller);
	~GUI();

	void display();

	void handleTransaction();
	void toggleState();

	void RSAExplanation();

	bool state; // True if showing transaction options, false if showing transaction list

private:

	std::thread explanationThread;
	std::thread rsaThreadP;
	std::thread rsaThreadQ;

	void explanation();

	void randPrime(boost::multiprecision::int1024_t max, boost::multiprecision::int1024_t min, boost::multiprecision::int1024_t randNum, TextLabel* prime, TextLabel* guessCount);

	bool isPrime(boost::multiprecision::int1024_t n, int k);

	bool millerTest(boost::multiprecision::int1024_t d, boost::multiprecision::int1024_t n);

	boost::random::independent_bits_engine<boost::random::mt19937, 1024, boost::multiprecision::int1024_t> generator;

	Controller* controller; // Pointer to controller class

	TextLabel usernameLabel;
	TextBox usernameTextbox;

	TextLabel passwordLabel;
	TextBox passwordTextbox;

	TextLabel recipientLabel;
	TextBox recipientTextbox;

	TextLabel quantityLabel;
	TextBox quantityTextbox;
	TextLabel dollarLabel;

	Button submitButton;
	Button toggleButton;
	Button startButton;


	TextLabel rsaExplanation;

	TextLabel primeOne;
	TextLabel primeTwo;

	TextLabel guessCountOne;
	TextLabel guessCountTwo;

	std::vector<std::string> data; // Contains all data stored in textboxes

	sf::Vector2f windowSize;
	int margin;

};