#pragma once

#include <sstream>
#include "DEFINITIONS.h"
#include "MenuState.h"
#include "PlayerAmountState.h"
#include "SettingState.h"
#include "PreGameState.h"
#include "ScoreboardState.h"
#include <iostream>

namespace MathWars
{
	MenuState::MenuState(GameDataRef data, PlayerDataRef player) : _data(data), _players(player)
	{

	}

	void MenuState::Init()
	{
		this->_players->playerData.clear();
		this->_players->pSelected = 1;


		//Initial Picture
		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND);
		this->_data->assets.LoadTexture("Game Title", GAME_TITLE);
		this->_data->assets.LoadTexture("Play Button", Singleplayer);
		this->_data->assets.LoadTexture("Multiplayer", Multiplayer);
		this->_data->assets.LoadTexture("Exit Button", Exit_BUTTON);
		this->_data->assets.LoadTexture("Stat Button", Stat_BUTTON);
		this->_data->assets.LoadTexture("Setting Button", Setting_BUTTON);
		this->_data->assets.LoadTexture("Audio Button", Audio_BUTTON);
		
		//Backround Image
		_background.setTexture((this->_data->assets.GetTexture("Main Menu Background")));
		_background.scale(sf::Vector2f(0.43f, 0.41f));
		
		//Title Image
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_title.scale(sf::Vector2f(0.60f, 0.50f));
		_title.setPosition(231, 44);
		
		
		//MultiPlayer
		_multiPBtn.setTexture(this->_data->assets.GetTexture("Play Button"));
		_multiPBtn.scale(0.45f, 0.45f);
		_multiPBtn.setPosition(497, 435);
	
		//SinglePlayer Button
		_singlePBtn.setTexture(this->_data->assets.GetTexture("Multiplayer"));
		_singlePBtn.scale(0.45f, 0.45f);
		_singlePBtn.setPosition(497, 350);

		//Exit Button
		_exitBtn.setTexture(this->_data->assets.GetTexture("Play Button"));
		_exitBtn.scale(0.45f, 0.45f);
		_exitBtn.setPosition(497, 520);

		//Music Button
		_audioBtn.setTexture(this->_data->assets.GetTexture("Audio Button"));
		_audioBtn.scale(0.40f, 0.40f);
		_audioBtn.setPosition(1050, 350);

		//soundSwitch = 1;
		if (!this->_data->music.openFromFile("Assets/Sounds/MenuMusic.ogg")) {
			std::cout << "Cant get File";
		}
		
		playMusic();
		
		
	}

	void MenuState::playMusic() {
		this->_data->music.setPlayingOffset(sf::seconds(9.f));
		this->_data->music.setLoop(true);
		this->_data->music.play();
		this->_data->music.setVolume(3.f);
	}


	void MenuState::HandleInput(){
		sf::Event event;

		while (this->_data->window.pollEvent(event)){
			if (sf::Event::Closed == event.type){
				this->_data->window.close();
			}
			//Single Player Button
			if (this->_data->input.IsSpriteClicked(this->_singlePBtn, sf::Mouse::Left, this->_data->window)) {
				this->_players->numPlayers = 1;
				this->_data->machine.AddState(StateRef(new PreGameState(_data, _players)), true);
				for (int i = 1; i < this->_players->numPlayers + 1; i++) {
					Player temp(i);
					this->_players->playerData.push_back(temp);
				}
			}
			//MultiPlayer Button
			if (this->_data->input.IsSpriteClicked(this->_multiPBtn, sf::Mouse::Left, this->_data->window)){
				this->_players->numPlayers = 2;
				this->_data->machine.AddState(StateRef(new PreGameState(_data, _players)), true);
				for (int i = 1; i < this->_players->numPlayers + 1; i++) {
					Player temp(i);
					this->_players->playerData.push_back(temp);
				}
			}
			//Exit Button
			if ((this->_data->input.IsSpriteClicked(this->_exitBtn, sf::Mouse::Left, this->_data->window))) {
				//music.stop();
				this->_data->window.close();
			}
			////Setting Button
			if (this->_data->input.IsSpriteClicked(this->_audioBtn, sf::Mouse::Left, this->_data->window)) {
				
				if (this->_data->soundSwitch == 1){
					this->_data->music.stop();
					_audioBtn.setTexture((this->_data->assets.GetTexture("CAudio Button")));
					this->_data->soundSwitch = 0;
				}
				else {
					playMusic();
					_audioBtn.setTexture((this->_data->assets.GetTexture("Audio Button")));
					this->_data->soundSwitch = 1;
				}
					
			}

		}
	}

	void MenuState::Update(float dt)
	{
		UpdateBtn();
	}

	void MenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_multiPBtn);
		this->_data->window.draw(this->_singlePBtn);
		this->_data->window.draw(this->_audioBtn);
		this->_data->window.draw(this->_settingBtn);
		this->_data->window.draw(this->_statBtn);
		this->_data->window.draw(this->_exitBtn);
		this->_data->window.display();

		
	}
	void MenuState::UpdateBtn(){
		//Hover Picture
		this->_data->assets.LoadTexture("CPlay Button", CPLAY_BUTTON);
		this->_data->assets.LoadTexture("CExit Button", CExit_BUTTON);
		this->_data->assets.LoadTexture("CStat Button", CStat_BUTTON);
		this->_data->assets.LoadTexture("SingleC", SingleC);
		this->_data->assets.LoadTexture("CAudio Button", CAudio_BUTTON);
		
		//Play Button
		if (this->_data->input.IsSpriteHovered(this->_multiPBtn, this->_data->window) == 1) {
			_multiPBtn.setTexture((this->_data->assets.GetTexture("CPlay Button")));
		}
		else {
			_multiPBtn.setTexture((this->_data->assets.GetTexture("Multiplayer")));
		}

		//Play Button
		if (this->_data->input.IsSpriteHovered(this->_singlePBtn, this->_data->window) == 1) {
			_singlePBtn.setTexture((this->_data->assets.GetTexture("SingleC")));
		}
		else {
			_singlePBtn.setTexture((this->_data->assets.GetTexture("Play Button")));
		}
		
		//Exit Button;
		if (this->_data->input.IsSpriteHovered(this->_exitBtn, this->_data->window) == 1){
			_exitBtn.setTexture((this->_data->assets.GetTexture("CExit Button")));
		}
		else {
			_exitBtn.setTexture((this->_data->assets.GetTexture("Exit Button")));
		}

	}
}
//