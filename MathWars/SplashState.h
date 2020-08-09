#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace MathWars {
	class SplashState : public State {
	public:
		SplashState(GameDataRef data, PlayerDataRef player);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		PlayerDataRef _players;
		sf::Clock _clock;
		sf::Texture _backroundTexture;
		sf::Sprite _backround;
	};
}
//


