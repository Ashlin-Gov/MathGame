#pragma once
#include "SettingState.h"
#include <sstream>
#include "Definitions.h"
#include "ScoreboardState.h"

#include <iostream>
namespace MathWars{
	SettingState::SettingState(GameDataRef data, PlayerDataRef player) : _data(data), _players(player){

	}

	void SettingState::Init(){
		this->_data->assets.LoadTexture("P1Background", Background_P1);
		this->_data->assets.LoadTexture("P2Background", Background_P2);
		this->_data->assets.LoadTexture("DrawBackground", Background_Draw);
		std::cout << this->_players->playerData.at(0).getScore() << " " << this->_players->playerData.at(1).getScore();
		if (this->_players->playerData.at(0).getScore() > this->_players->playerData.at(1).getScore()) {
			_background.setTexture(this->_data->assets.GetTexture("P1Background"));
		}
		else if (this->_players->playerData.at(0).getScore() < this->_players->playerData.at(1).getScore()) {
			_background.setTexture(this->_data->assets.GetTexture("P2Background"));
		}
		else {
			_background.setTexture(this->_data->assets.GetTexture("DrawBackground"));
		}
		_background.setScale(0.43, 0.40);

		this->_data->assets.LoadTexture("BtnNExt", Btn_Next);
		_homeBtn.setTexture(this->_data->assets.GetTexture("BtnNExt"));
		_homeBtn.setPosition(1072, 239);
		_homeBtn.setScale(0.50, 0.50);

	}

	void SettingState::HandleInput(){
		sf::Event event;

		while (this->_data->window.pollEvent(event)){
			if (sf::Event::Closed == event.type){
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(_homeBtn, sf::Mouse::Left, this->_data->window)) {
				_data->machine.AddState(StateRef(new ScoreboardState(_data, _players)), true);
			}
		}
	}

	void SettingState::Update(float dt){

	}

	void SettingState::Draw(float dt){
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(_background);
		this->_data->window.draw(_homeBtn);
		this->_data->window.display();
	}
}
//