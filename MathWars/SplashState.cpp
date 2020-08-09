#pragma once
#include <sstream>
#include "SplashState.h"
#include "Definitions.h"
#include <iostream>
#include "MenuState.h"

namespace MathWars {
	SplashState::SplashState(GameDataRef data, PlayerDataRef player) : _data(data), _players(player)
	{

	}

	void SplashState::Init() {
		this->_data->assets.LoadTexture("SplashStateBackround", sState_Backround);
		_backround.setTexture(this->_data->assets.GetTexture("SplashStateBackround"));

	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt){
		if (this->_clock.getElapsedTime().asSeconds() > sState_Time){
			// Switch To Main Menu
			_data->machine.AddState(StateRef(new MenuState(_data, _players)), true);
		}
	}

	void SplashState::Draw(float dt) {
		_data->window.clear();
		_data->window.draw(this->_backround);
		_data->window.display();
	}
}
//