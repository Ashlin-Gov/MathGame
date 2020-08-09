#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "SFML\Audio.hpp"

namespace MathWars
{
	class MenuState : public State
	{
	public:
		MenuState(GameDataRef data, PlayerDataRef player);

		void Init();

		void playMusic();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		PlayerDataRef _players;
		sf::Sprite _background, _title, _multiPBtn, _singlePBtn, _exitBtn, _settingBtn, _audioBtn, _statBtn;
		
		//int soundSwitch;
		void UpdateBtn();
		
	};
}
//
