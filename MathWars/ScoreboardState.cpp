#pragma once
#include "ScoreboardState.h" // Change to Class Header
#include "MenuState.h"
#include <sstream>
#include "Definitions.h"

#include <iostream>
namespace MathWars
{
	ScoreboardState::ScoreboardState(GameDataRef data, PlayerDataRef player) : _data(data), _players(player)
	{

	}

	void ScoreboardState::Init()
	{
		//Backround
		this->_data->assets.LoadTexture("ResBackground", Background_Res);
		_background.setTexture(this->_data->assets.GetTexture("ResBackground"));
		_background.scale(0.30, 0.35);

		//Home Buttone
		this->_data->assets.LoadTexture("Home Button", Home_Button);
		_homeBtn.setTexture(this->_data->assets.GetTexture("Home Button"));
		_homeBtn.setPosition(1170, 17);
		_homeBtn.setScale(0.50, 0.50);

		if (!font.loadFromFile("Assets/helsinki.ttf")) {
			std::cout << " Font Not Loaded";
		}

		int y = 200;
		if (this->_players->playerData.size() == 1) {
			Qp1 = this->_players->playerData.at(0).getIncorrectQuestions();
			
			for (it = Qp1.begin(); it != Qp1.end(); it++) {
				sf::Text temp;
				temp.setFont(font);
				temp.setString(it->first + " = " + it->second);
				temp.setCharacterSize(24);
				temp.setPosition(160, y);
				p1.push_back(temp);
				y += 25;
			}
		}
		else {
			Qp1 = this->_players->playerData.at(0).getIncorrectQuestions();
			Qp2 = this->_players->playerData.at(1).getIncorrectQuestions();

			for (it = Qp1.begin(); it != Qp1.end(); it++) {
				sf::Text temp;
				temp.setFont(font);
				temp.setString(it->first + " = " + it->second);
				temp.setCharacterSize(24);
				temp.setPosition(160,y);
				p1.push_back(temp);
				y += 25;
			}
			y = 200;
			for (it = Qp2.begin(); it != Qp2.end(); it++) {
				sf::Text temp;
				temp.setFont(font);
				temp.setString(it->first + "= " + it->second);
				temp.setCharacterSize(24);
				temp.setPosition(900, y);
				p2.push_back(temp);
				y += 25;
			}
		}

		s1 = 19 - Qp1.size();
		s2 = 19 - Qp2.size();

		score1.setFont(font);
		score1.setCharacterSize(32);
		score1.setString("Score : " + std::to_string(s1));
		score1.setPosition(160, 680);
		score1.setFillColor(sf::Color::Color(208, 74, 186, 255));

		score2.setFont(font);
		score2.setCharacterSize(32);
		score2.setString("Score : " + std::to_string(s2));
		score2.setPosition(900, 680);
		score2.setFillColor(sf::Color::Color(208, 74, 186, 255));
		

	}

	void ScoreboardState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(_homeBtn,sf::Mouse::Left, this->_data->window)) {
				this->_data->machine.AddState(StateRef(new MenuState(_data, _players)), true);
			}
		}
	}

	void ScoreboardState::Update(float dt)
	{
		UpdateBtn();
	}

	void ScoreboardState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_homeBtn);

		for (int i = 0; i < p1.size(); i++) {
			this->_data->window.draw(this->p1.at(i));
		}
		this->_data->window.draw(this->score1);

		if (this->_players->playerData.size() > 1) {
			for (int i = 0; i < p2.size(); i++) {
				this->_data->window.draw(this->p2.at(i));
			}
			this->_data->window.draw(this->score2);
		}

		this->_data->window.display();
	}
	void ScoreboardState::UpdateBtn()
	{
		this->_data->assets.LoadTexture("CHome Button", CHome_Button);

		if (this->_data->input.IsSpriteHovered(_homeBtn,this->_data->window)) {
			this->_homeBtn.setTexture(this->_data->assets.GetTexture("CHome Button"));
		}
	}
}
//