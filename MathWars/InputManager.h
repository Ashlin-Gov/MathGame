#pragma once

#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

namespace MathWars
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);
		bool IsSpriteHovered(sf::Sprite object, sf::RenderWindow& window);
		sf::Vector2i GetMousePosition(sf::RenderWindow& window);
		bool KeyEntered(sf::Keyboard::Key key);
	};
}
//