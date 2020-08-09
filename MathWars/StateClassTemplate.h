#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace MathWars
{
	class StateClassTemplate : public State
	{
	public:
		StateClassTemplate(GameDataRef data, PlayerDataRef player);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		PlayerDataRef _players;

		//sf::Sprite _background; -> ADD Whatever Sprites you need
	};
}
//