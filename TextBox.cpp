#include "TextBox.h"
#include "GUI.h"
#include <iostream>

TextBox::TextBox(GUI* gui) : gui(gui), pos(), box(), boxSize(), boxColor(), thickness(3), text(), textColor(), textSize(40), textMargin(10), doBlink(false), seeCursor(false), cooldown(250), prevTime(0) {
	setBoxThickness(3);
	setBoxSize(sf::Vector2f(200, 200));
	setPos(sf::Vector2f(0, 0));
	setBoxColor(sf::Color::White);
	box.setFillColor(sf::Color::Transparent);

	setTextSize(40);
	setTextColor(sf::Color::White);
	setText("");
	if (!this->font.loadFromFile("OpenSans-Bold.ttf")) {
		std::cout << "Font not found";
	}
	text.setFont(font);
	cursor.setFont(font);
}

void TextBox::setBoxSize(sf::Vector2f size) {
	this->boxSize = size;
	box.setSize(size);
}

sf::Vector2f TextBox::getBoxSize() {
	return boxSize;
}

void TextBox::setPos(sf::Vector2f pos) {
	this->pos = pos;
	box.setPosition({ (pos.x + thickness), (pos.y + thickness) });
	text.setPosition({ (pos.x + thickness + textMargin), (pos.y) });
	cursor.setPosition({ (pos.x + thickness + textMargin), (pos.y) });
}

sf::Vector2f TextBox::getPos() {
	return pos;
}

void TextBox::setBoxColor(sf::Color color) {
	this->boxColor = color;
	box.setOutlineColor(color);
}

sf::Color TextBox::getBoxColor() {
	return boxColor;
}

void TextBox::setBoxThickness(float thickness) {
	this->thickness = thickness;
	box.setOutlineThickness(thickness);
}

float TextBox::getBoxThickness() {
	return thickness;
}

void TextBox::setTextSize(int size) {
	this->textSize = size;
	text.setCharacterSize(size);
	cursor.setCharacterSize(size);
}

int TextBox::getTextSize() {
	return textSize;
}

void TextBox::setTextColor(sf::Color color) {
	this->textColor = color;
	text.setFillColor(color);
	cursor.setFillColor(color);
}
sf::Color TextBox::getTextColor() {
	return textColor;
}

void TextBox::setText(std::string data) {
	text.setString(data);
}

std::string TextBox::getText() {
	return text.getString().toAnsiString();
}

void TextBox::setTextMargin(int margin) {
	textMargin = margin;
	setPos(pos);
}

int TextBox::getTextMargin() {
	return textMargin;
}

void TextBox::blinkCursor() {
	if (doBlink) {

		if ((int)timer.getElapsedTime().asMilliseconds() % cooldown == 0 && (int)timer.getElapsedTime().asMilliseconds() != prevTime) {

			prevTime = (int)timer.getElapsedTime().asMilliseconds();
			
			if (!seeCursor) {
				cursor.setString("");
				seeCursor = true;
			}
			else if (seeCursor) {
				cursor.setPosition({ (text.getLocalBounds().width + text.getPosition().x), cursor.getPosition().y });
				cursor.setString("|");
				seeCursor = false;
			}
		}
	}
}

void TextBox::enableCursor() {
	doBlink = true;
	sf::Time start = timer.getElapsedTime();
	blinkCursor();
}

void TextBox::disableCursor() {
	timer.restart();
	doBlink = false;
	seeCursor = false;
	prevTime = 0;
	cursor.setString("");
}

void TextBox::pauseCursor() {
	cooldown = (int)1e6;
	cursor.setPosition({ (text.getLocalBounds().width + text.getPosition().x), cursor.getPosition().y });
	cursor.setString("|");
}

void TextBox::resumeCursor() {
	cooldown = 500;
	cursor.setPosition({ (text.getLocalBounds().width + text.getPosition().x), cursor.getPosition().y });
	cursor.setString("|");
}

void TextBox::update() {
	blinkCursor();
}



void TextBox::draw(sf::RenderTarget& window, sf::RenderStates states) const {
	window.draw(box);
	window.draw(text);
	window.draw(cursor);
}

void TextBox::addEventHandler(sf::RenderWindow& window, sf::Event event) {
	sf::FloatRect bounds = box.getGlobalBounds();
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	// When user clicks
	if (event.type == sf::Event::MouseButtonPressed) {
		if (mousePos.x > bounds.left && mousePos.x < bounds.width + bounds.left && mousePos.y > bounds.top && mousePos.y < bounds.height + bounds.top) {
			enableCursor();
		}
		else {
			disableCursor();
		}
	}

	// When user types
	if (doBlink && event.type == sf::Event::TextEntered) {
		if (event.text.unicode == 13) { // If user types enter
			gui->handleTransaction();
		} else if (event.text.unicode == 8) { // If user types backspace
			text.setString(text.getString().substring(0, text.getString().getSize() - 1));
		}
		else { // Normal keys
			pauseCursor();
			text.setString(text.getString() + static_cast<char>(event.text.unicode));
			resumeCursor();
		}

	}
}