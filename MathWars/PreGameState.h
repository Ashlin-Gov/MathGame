#pragma once

#include <sstream>
#include<iostream>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace MathWars
{
	class PreGameState : public State
	{
	public:
		PreGameState(GameDataRef data, PlayerDataRef player);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		PlayerDataRef _players;
		sf::Clock _clock;
		sf::Sprite _background, _ppButton, _topBar, _confirmBtn, _homeBtn;
		sf::Sprite _tbExt, _h1, _h2, _h3, _h4, _textBorder;
		sf::String _playerInput, _selectedAvatar;
		sf::Font font;
		sf::Text _playerText;
		std::string str;
		sf::String text;

		sf::Text _pNumber;
	};
}
//