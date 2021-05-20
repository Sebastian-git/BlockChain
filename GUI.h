#pragma once
#include <SFML/Graphics.hpp>

class GUI {

public:
	GUI();

	void display();

private:
	sf::Vector2f windowSize;
	int margin;

};

