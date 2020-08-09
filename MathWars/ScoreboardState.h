#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace MathWars
{
	class ScoreboardState : public State
	{
	public:
		ScoreboardState(GameDataRef data, PlayerDataRef player);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		PlayerDataRef _players;
		sf::Sprite _background, _homeBtn; //-> ADD Whatever Sprites you need
		int s1, s2;
		sf::Font font;
		sf::Text score1, score2;
		std::vector<sf::Text> p1, p2;
		std::map<std::string, std::string>::iterator it;
		std::map<std::string, std::string>  Qp1;
		std::map<std::string, std::string>  Qp2;

		void UpdateBtn();
	};
}
//