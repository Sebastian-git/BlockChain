#pragma once
#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "TextLabel.h"
#include <vector>
#include <string>

class Controller;

class GUI {

public:
	GUI(Controller* controller);

	void display();

	void handleTransaction();

private:
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

	std::vector<std::string> data; // Contains all data stored in textboxes

	sf::Vector2f windowSize;
	int margin;
};