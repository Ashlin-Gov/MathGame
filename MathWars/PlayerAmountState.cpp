#pragma once
#include "PlayerAmountState.h" // Change to Class Header
#include <sstream>
#include "Definitions.h"
#include "PreGameState.h"

#include <iostream>
#include <Windows.h>
namespace MathWars
{
	PlayerAmountState::PlayerAmountState(GameDataRef data, PlayerDataRef player) : _data(data), _players(player)
	{

	}

	void PlayerAmountState::Init()
	{
		//Initialize All Button Textures and Attributes
		//Backround
		this->_data->assets.LoadTexture("PA Background", Player_Amount_Background);
		_background.setTexture(this->_data->assets.GetTexture("PA Background"));
		_background.scale(0.60f, 0.62f);

		//ConfirmBtn
		this->_data->assets.LoadTexture("ConfrimBtn", Confirm_Button);
		_confirmBtn.setTexture(this->_data->assets.GetTexture("ConfrimBtn"));
		_confirmBtn.scale(0.60f, 0.60f);

		//Button 1
		_oneBtn.setTexture(this->_data->assets.GetTexture("ConfrimBtn"));
		_oneBtn.scale(0.60f, 0.60f);
		_oneBtn.setPosition(100,200);
		//Button 2
		_twoBtn.setTexture(this->_data->assets.GetTexture("ConfrimBtn"));
		_twoBtn.scale(0.60f, 0.60f);
		_twoBtn.setPosition(100, 300);

	}

	void PlayerAmountState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(_confirmBtn,sf::Mouse::Left, this->_data->window)) {
				if (this->_players->numPlayers == 0) {
					MessageBox(NULL, L"Please select the number players", L"Error", MB_OK);
				}
				else
				{
					this->_data->machine.AddState(StateRef(new PreGameState(_data, _players)), true);
					for (int i = 1; i < this->_players->numPlayers + 1; i++) {
						Player temp(i);
						this->_players->playerData.push_back(temp);
					}
				}

				
			}

			if (this->_data->input.IsSpriteClicked(_oneBtn, sf::Mouse::Left, this->_data->window)) {
				this->_players->numPlayers = 1;
			}
			else if (this->_data->input.IsSpriteClicked(_twoBtn, sf::Mouse::Left, this->_data->window)) {
				this->_players->numPlayers = 2;
			}
		}
	}

	void PlayerAmountState::Update(float dt)
	{

	}

	void PlayerAmountState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(_background);
		this->_data->window.draw(_confirmBtn);
		this->_data->window.draw(_oneBtn);
		this->_data->window.draw(_twoBtn);
		this->_data->window.draw(_threeBtn);
		this->_data->window.draw(_fourBtn);

		this->_data->window.display();
	}
}
//