#pragma once

#include "InputManager.h"
#include <iostream>

namespace MathWars
{
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		//sf::Event event;
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (playButtonRect.contains(GetMousePosition(window)))
			{
				return true;
			}

		}

		return false;
	}

	bool InputManager::IsSpriteHovered(sf::Sprite object, sf::RenderWindow& window)
	{
		sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height - 5);
	
		if(playButtonRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
	{
		return sf::Mouse::getPosition(window);
	}

	bool InputManager::KeyEntered(sf::Keyboard::Key key)
	{
		if (sf::Keyboard::isKeyPressed(key)) {
			
			return true;
		}
		else return false;
	}


	
}
//