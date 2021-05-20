<<<<<<< HEAD
#pragma once
#include <SFML/Graphics.hpp>

class GUIComponent : public sf::Drawable, public sf::Transformable {

	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
	virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
=======
#pragma once
#include <SFML/Graphics.hpp>

class GUIComponent : public sf::Drawable, public sf::Transformable {

	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
	virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
>>>>>>> 5ffb06da6f3de529ca20d021369c8a15fbb79e87
};