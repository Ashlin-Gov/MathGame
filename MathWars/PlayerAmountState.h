#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace MathWars
{
	class PlayerAmountState : public State
	{
	public:
		PlayerAmountState(GameDataRef data, PlayerDataRef player);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		PlayerDataRef _players;

		sf::Sprite _background, _oneBtn, _twoBtn, _threeBtn, _fourBtn, _confirmBtn; //-> ADD Whatever Sprites you need
	};
}
//
