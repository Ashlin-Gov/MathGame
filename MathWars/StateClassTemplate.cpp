#pragma once
#include "StateClassTemplate.h" // Change to Class Header
#include <sstream>
#include "Definitions.h"
#include <iostream>
namespace MathWars
{
	StateClassTemplate::StateClassTemplate(GameDataRef data, PlayerDataRef player) : _data(data), _players(player) {

	}

	void StateClassTemplate::Init(){
		//Initialize All Assets
		this->_data->assets.LoadTexture("Game Background", Game_Screen_Background);
	}

	void StateClassTemplate::HandleInput(){
		//Input
		sf::Event event;

		while (this->_data->window.pollEvent(event)){
			if (sf::Event::Closed == event.type){
				this->_data->window.close();
			}
		}
	}

	void StateClassTemplate::Update(float dt){
	}

	void StateClassTemplate::Draw(float dt){
		//Game Loop
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.display();

	}
}
//