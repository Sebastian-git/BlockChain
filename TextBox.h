#pragma once
#include "GUIComponent.h"
#include <string>

class GUI;

class TextBox : public GUIComponent {

public:
	TextBox(GUI* gui);

	void setPos(sf::Vector2f pos);
	sf::Vector2f getPos();

	void setBoxSize(sf::Vector2f size);
	sf::Vector2f getBoxSize();

	void setBoxColor(sf::Color color);
	sf::Color getBoxColor();

	void setBoxThickness(float thickness);
	float getBoxThickness();

	void setTextSize(int size);
	int getTextSize();

	void setTextColor(sf::Color color);
	sf::Color getTextColor();

	void setText(std::string data);
	std::string getText();

	void setTextMargin(int margin);
	int getTextMargin();


	void update();
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

private:
	GUI* gui; // Pointer to GUI class to pass text data for transaction handler

	sf::Vector2f pos; // Position of all textbox components

	sf::RectangleShape box; // Box
	sf::Vector2f boxSize; // Box size
	sf::Color boxColor; // Box color
	float thickness; // Box thickness

	sf::Text text; // Text user types
	sf::Font font; // Text font
	sf::Color textColor; // Text color
	int textSize; // Text size
	int textMargin; // Margin between text and box
	bool isTyping; // Enabled when user types while textbox is selected

	sf::Text cursor; // Cursor that blinks when clicked
	sf::Clock timer; // Timer to tell cursor when to blink
	void blinkCursor(); // Called in update to blink cursor
	void pauseCursor(); // Pauses cursor blinking
	void resumeCursor(); // Resumes cursor blinking
	void enableCursor(); // Enables cursor
	void disableCursor(); // Disables cursor
	int cooldown; // Cool down between blinks in ms
	int prevTime; // Previous time saved so timer doesn't repeat time
	bool seeCursor; // True if cursor is visible
	bool doBlink; // Boolean to check if cursor should blink
	
};

