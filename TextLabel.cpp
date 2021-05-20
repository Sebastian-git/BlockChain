<<<<<<< HEAD
#include "TextLabel.h"
#include <iostream>

TextLabel::TextLabel() : pos(), font(), textSize(), color(), text() {
	setPosition(sf::Vector2f(0, 0));
	setTextSize(40);
	setTextColor(sf::Color::White);
	setText("");
	if (!this->font.loadFromFile("OpenSans-Bold.ttf")) {
		std::cout << "Font not found";
	}
	text.setFont(font);
}

void TextLabel::setPos(sf::Vector2f pos) {
	this->pos = pos;
	text.setPosition(pos);
}
sf::Vector2f TextLabel::getPos() {
	return pos;
}
void TextLabel::setTextSize(int size) {
	this->textSize = size;
	text.setCharacterSize(size);
}
int TextLabel::getTextSize() {
	return textSize;
}
void TextLabel::setTextColor(sf::Color color) {
	this->color = color;
	text.setFillColor(color);
}
sf::Color TextLabel::getTextColor() {
	return color;
}
void TextLabel::setText(std::string data) {
	text.setString(data);
}
std::string TextLabel::getText() {
	return text.getString().toAnsiString();
}
sf::FloatRect TextLabel::getBounds() {
	return text.getLocalBounds();
}



void TextLabel::draw(sf::RenderTarget& window, sf::RenderStates states) const {
	window.draw(text);
}
void TextLabel::addEventHandler(sf::RenderWindow& window, sf::Event event) {

=======
#include "TextLabel.h"
#include <iostream>

TextLabel::TextLabel() : pos(), font(), textSize(), color(), text() {
	setPosition(sf::Vector2f(0, 0));
	setTextSize(40);
	setTextColor(sf::Color::White);
	setText("");
	if (!this->font.loadFromFile("OpenSans-Bold.ttf")) {
		std::cout << "Font not found";
	}
	text.setFont(font);
}

void TextLabel::setPos(sf::Vector2f pos) {
	this->pos = pos;
	text.setPosition(pos);
}
sf::Vector2f TextLabel::getPos() {
	return pos;
}
void TextLabel::setTextSize(int size) {
	this->textSize = size;
	text.setCharacterSize(size);
}
int TextLabel::getTextSize() {
	return textSize;
}
void TextLabel::setTextColor(sf::Color color) {
	this->color = color;
	text.setFillColor(color);
}
sf::Color TextLabel::getTextColor() {
	return color;
}
void TextLabel::setText(std::string data) {
	text.setString(data);
}
std::string TextLabel::getText() {
	return text.getString().toAnsiString();
}
sf::FloatRect TextLabel::getBounds() {
	return text.getLocalBounds();
}



void TextLabel::draw(sf::RenderTarget& window, sf::RenderStates states) const {
	window.draw(text);
}
void TextLabel::addEventHandler(sf::RenderWindow& window, sf::Event event) {

>>>>>>> 5ffb06da6f3de529ca20d021369c8a15fbb79e87
}