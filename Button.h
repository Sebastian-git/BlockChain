#pragma once
#include "GUIComponent.h"
#include <string>

class GUI;

class Button : public GUIComponent {

public:

	Button(GUI* gui);

	void setFont(sf::Font newFont);

	void setText(std::string newText);
	std::string getText() const;

	void setTextColor(sf::Color newColor);
	sf::Color getTextColor() const;

	void setBoxColor(sf::Color newColor);
	sf::Color getBoxColor() const;

	void setBoxThickness(int newThickness);
	int getBoxThickness() const;

	void setPos(sf::Vector2f newPos);
	sf::Vector2f getPos() const;

	void setTextSize(int newSize);
	int getTextSize() const;

	void setBoxSize(sf::Vector2f newSize);
	sf::Vector2f getBoxSize() const;



	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

private:

	GUI* gui;
	sf::RectangleShape box;
	sf::Text text; 
	sf::Font font; 

	int margin;

	sf::Color textColor;
	sf::Color boxColor;

	int boxThickness;

	sf::Vector2f pos;

	int textSize;
	sf::Vector2f boxSize;

};