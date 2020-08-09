#pragma once
#include "Definitions.h"
#include "PreGameState.h"
#include "GameState.h"
#include "MenuState.h"


namespace MathWars
{
	PreGameState::PreGameState(GameDataRef data, PlayerDataRef player) : _data(data) , _players(player)
	{

	}

	void PreGameState::Init()
	{
		//Initialize All Button Textures and Attributes
		//Backround
		this->_data->assets.LoadTexture("Game Background", cs_Background);
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_background.scale(0.60, 0.63);


		//Top Bar
		this->_data->assets.LoadTexture("Top Bar", Game_Screen_TopBar);
		_topBar.setTexture(this->_data->assets.GetTexture("Top Bar"));
		_topBar.scale(0.50, 0.50);
		this->_data->assets.LoadTexture("tbExtention", TopBar_Extention);
		_tbExt.setTexture(this->_data->assets.GetTexture("tbExtention"));
		_tbExt.setPosition(948, 1);
		_tbExt.scale(0.60, 0.50);

		this->_data->assets.LoadTexture("Home Button", Home_Button);
		_homeBtn.setTexture(this->_data->assets.GetTexture("Home Button"));
		_homeBtn.setPosition(1170, 17);
		_homeBtn.setScale(0.50, 0.50);


		//Hero 1
		this->_data->assets.LoadTexture("Hero 1", Hero_One);
		_h1.setTexture(this->_data->assets.GetTexture("Hero 1"));
		_h1.scale(0.60, 0.60);
		_h1.setPosition(180, 247);
		//Hero 2
		this->_data->assets.LoadTexture("Hero 2", Hero_Two);
		_h2.setTexture(this->_data->assets.GetTexture("Hero 2"));
		_h2.scale(0.60, 0.60);
		_h2.setPosition(430, 247);
		//Hero 3
		this->_data->assets.LoadTexture("Hero 3", Hero_Three);
		_h3.setTexture(this->_data->assets.GetTexture("Hero 3"));
		_h3.scale(0.60, 0.60);
		_h3.setPosition(680, 247);
		//Hero 4
		this->_data->assets.LoadTexture("Hero 4", Hero_Four);
		_h4.setTexture(this->_data->assets.GetTexture("Hero 4"));
		_h4.scale(0.60, 0.60);
		_h4.setPosition(940, 247);

		//Confirm Button
		this->_data->assets.LoadTexture("Select", Select);
		_confirmBtn.setTexture(this->_data->assets.GetTexture("Select"));
		_confirmBtn.scale(0.60f, 0.60f);
		_confirmBtn.setPosition(529, 547);

		//Load Font
		if (!font.loadFromFile("Assets/helsinki.ttf")) {
			std::cout << " asd";
		}

		//PLayer Input Font
		_playerText.setFont(font);
		_playerText.setString("");
		_playerText.setFillColor(sf::Color::Color(208, 74, 186, 255));
		_playerText.setPosition(2, 2);

		//Player Number;
		_pNumber.setFont(font);
		_pNumber.setString("Player " + std::to_string(this->_players->pSelected));
		_pNumber.setFillColor(sf::Color::Color(208, 74, 186, 255));
		_pNumber.setPosition(500, 150);
		_pNumber.setCharacterSize(50);

	}

	void PreGameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (this->_data->input.IsSpriteClicked(_homeBtn, sf::Mouse::Left, this->_data->window)) {
				this->_data->machine.AddState(StateRef(new MenuState(_data, _players)), true);
			}

			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(_h1, sf::Mouse::Left, this->_data->window)) {
				
				//_data->machine.AddState(StateRef(new GameState(_data, _players)), true);
			}

			//Confirm Button Clicked
			if (this->_data->input.IsSpriteClicked(_confirmBtn, sf::Mouse::Left, this->_data->window)) {
				//Save Player Details
				if (_selectedAvatar.isEmpty()) {
					_selectedAvatar = "Hero 1";
				}
				this->_players->playerData.at(this->_players->pSelected - 1).setAvatar(_selectedAvatar);



				if (str.empty()) {
					this->_players->playerData.at(this->_players->pSelected - 1).setName("Unknown Player");
				}
				else {
					this->_players->playerData.at(this->_players->pSelected - 1).setName(str);
				}	

				//Loop for Number of Selected Players
				this->_players->pSelected++;
				if (this->_players->pSelected <= this->_players->numPlayers) {
					
					//std::cout << this->_players->pSelected << " " << this->_players->numPlayers << std::endl;
					this->_data->machine.AddState(StateRef(new PreGameState(_data, _players)), true);
				}
				else {
					_data->machine.AddState(StateRef(new GameState(_data, _players)), true);
					this->_players->pSelected = 1;
				}

			}

			//Text Input 
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == '\b') {
					if(str.length() > 0)
						str.pop_back();
				}
				else if (event.text.unicode < 128){
					if (str.length() <= 14) {
						str += static_cast<char>(event.text.unicode);
					}
					
				}
				_playerText.setString(str);
				_playerText.setPosition(200, 576);
				
			}
		}
	}

	void PreGameState::Update(float dt)
	{
		
		//Characters Selected
		//Hero 1
		if (this->_data->input.IsSpriteClicked(_h1, sf::Mouse::Left, this->_data->window)) {
			this->_data->assets.LoadTexture("Hero 1H", Hero_One_Hover);
			_h1.setTexture(this->_data->assets.GetTexture("Hero 1H"));
			_h2.setTexture(this->_data->assets.GetTexture("Hero 2"));
			_h3.setTexture(this->_data->assets.GetTexture("Hero 3"));
			_h4.setTexture(this->_data->assets.GetTexture("Hero 4"));

			_selectedAvatar = "Hero 1";
		}
		//Hero 2
		if (this->_data->input.IsSpriteClicked(_h2, sf::Mouse::Left, this->_data->window)) {
			this->_data->assets.LoadTexture("Hero 2H", Hero_Two_Hover);
			_h2.setTexture(this->_data->assets.GetTexture("Hero 2H"));
			_h1.setTexture(this->_data->assets.GetTexture("Hero 1"));
			_h3.setTexture(this->_data->assets.GetTexture("Hero 3"));
			_h4.setTexture(this->_data->assets.GetTexture("Hero 4"));

			_selectedAvatar = "Hero 2";
		}
		//Hero 3
		if (this->_data->input.IsSpriteClicked(_h3, sf::Mouse::Left, this->_data->window)) {
			this->_data->assets.LoadTexture("Hero 3H", Hero_Three_Hover);
			_h3.setTexture(this->_data->assets.GetTexture("Hero 3H"));
			_h1.setTexture(this->_data->assets.GetTexture("Hero 1"));
			_h2.setTexture(this->_data->assets.GetTexture("Hero 2"));
			_h4.setTexture(this->_data->assets.GetTexture("Hero 4"));

			_selectedAvatar = "Hero 3";
		}
		//Hero 4
		if (this->_data->input.IsSpriteClicked(_h4, sf::Mouse::Left, this->_data->window)) {
			this->_data->assets.LoadTexture("Hero 4H", Hero_Four_Hover);
			_h4.setTexture(this->_data->assets.GetTexture("Hero 4H"));
			_h1.setTexture(this->_data->assets.GetTexture("Hero 1"));
			_h3.setTexture(this->_data->assets.GetTexture("Hero 3"));
			_h2.setTexture(this->_data->assets.GetTexture("Hero 2"));

			_selectedAvatar = "Hero 4";
		}

		this->_data->assets.LoadTexture("SelectC", Select);
		this->_data->assets.LoadTexture("Select", SelectC);
		if (this->_data->input.IsSpriteHovered(this->_confirmBtn, this->_data->window) == 1) {
			_confirmBtn.setTexture((this->_data->assets.GetTexture("SelectC")));
		}
		else {
			_confirmBtn.setTexture((this->_data->assets.GetTexture("Select")));
		}

		this->_data->assets.LoadTexture("CHome Button", CHome_Button);
		if (this->_data->input.IsSpriteHovered(this->_homeBtn, this->_data->window) == 1) {
			_homeBtn.setTexture(this->_data->assets.GetTexture("CHome Button"));
		}
		else {
			_homeBtn.setTexture(this->_data->assets.GetTexture("Home Button"));
		}

	}

	void PreGameState::Draw(float dt)
	{
		this->_data->window.clear();
		
		this->_data->window.draw(this->_background);

		this->_data->window.draw(this->_h1);
		this->_data->window.draw(this->_h2);
		this->_data->window.draw(this->_h3);
		this->_data->window.draw(this->_h4);
		this->_data->window.draw(this->_playerText);
		this->_data->window.draw(this->_confirmBtn);
		this->_data->window.draw(this->_pNumber);
		this->_data->window.draw(this->_homeBtn);

		this->_data->window.display();

	}
}
//