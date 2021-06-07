#include "Button.h"
#include "GUI.h"
#include <iostream>

Button::Button(GUI* gui) : gui(gui), box(), text(), font(), textColor(sf::Color::White), boxColor(), boxThickness(), pos(sf::Vector2f(0, 0)), textSize(), boxSize(), margin(10) {

	setPos(sf::Vector2f(0, 0));

	setTextSize(40);
	setTextColor(sf::Color::White);
	if (!this->font.loadFromFile("OpenSans-Bold.ttf")) {
		std::cout << "Font not found";
	}
	text.setFont(font);

	setBoxThickness(3);
	setBoxSize(sf::Vector2f(200, 200));
	setBoxColor(sf::Color::White);
	box.setFillColor(sf::Color::Transparent);

}

void Button::setFont(sf::Font newFont) {
	font = newFont;
	text.setFont(font);
}

void Button::setText(std::string newText) {
	text.setString(newText);
}
std::string Button::getText() const {
	return text.getString().toAnsiString();
}

void Button::setTextColor(sf::Color newColor) {
	textColor = newColor;
	//text.setColor(textColor);
}
sf::Color Button::getTextColor() const {
	return textColor;
}

void Button::setBoxColor(sf::Color newColor) {
	boxColor = newColor;
	box.setOutlineColor(boxColor);
}
sf::Color Button::getBoxColor() const {
	return box.getOutlineColor();
}

void Button::setBoxThickness(int newThickness) {
	boxThickness = newThickness;
	box.setOutlineThickness((float) boxThickness);
}
int Button::getBoxThickness() const {
	return boxThickness;
}

void Button::setPos(sf::Vector2f newPos) {
	newPos.x = newPos.x + boxThickness;
	newPos.y = newPos.y + boxThickness;
	pos = newPos;
	box.setPosition(newPos);
	text.setPosition(sf::Vector2f((newPos.x + margin), newPos.y));
}
sf::Vector2f Button::getPos() const {
	return pos;
}

void Button::setTextSize(int newSize) {
	textSize = newSize;
	text.setCharacterSize(textSize);
}
int Button::getTextSize() const {
	return textSize;
}

void Button::setBoxSize(sf::Vector2f newSize) {
	boxSize = newSize;
	box.setSize(boxSize);
}
sf::Vector2f Button::getBoxSize() const {
	return boxSize;
}



void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const {
	window.draw(text);
	window.draw(box);
}
void Button::addEventHandler(sf::RenderWindow& window, sf::Event event) {
	sf::FloatRect bounds = box.getGlobalBounds();
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	// When user clicks
	if (event.type == sf::Event::MouseButtonPressed) {
		if (mousePos.x > bounds.left && mousePos.x < bounds.width + bounds.left && mousePos.y > bounds.top && mousePos.y < bounds.height + bounds.top) {
			if (text.getString().toAnsiString() == "Submit") {
				gui->handleTransaction();
			}
			else if (text.getString().toAnsiString() == "Toggle") {
				gui->toggleState();
			} 
			else if (text.getString().toAnsiString() == "Start" && !gui->state && !gui->isPresenting) {
				gui->RSAExplanation();
			}
		}
		else {
		}
	}
}