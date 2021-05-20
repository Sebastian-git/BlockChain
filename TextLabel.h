#pragma once
#include "GUIComponent.h"
#include <string>

class TextLabel : public GUIComponent {

public:
	TextLabel();

	void setPos(sf::Vector2f pos);
	sf::Vector2f getPos();

	void setTextSize(int size);
	int getTextSize();

	void setTextColor(sf::Color color);
	sf::Color getTextColor();

	void setText(std::string data);
	std::string getText();

	sf::FloatRect getBounds();



	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

private:
	sf::Vector2f pos;

	sf::Text text;
	sf::Font font;
	int textSize;
	sf::Color color;
};