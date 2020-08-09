#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "QuestionData.h"

namespace MathWars
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data, PlayerDataRef player);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		PlayerDataRef _players;
		QuestionData _questions;

		void loadQuestions();
		void loadAnswers();
		void nextPlayer();

		int playerScore;
		sf::Font font;
		sf::Sprite _backround, _avatar, _startBtn, _confirmBtn;
		sf::Text _playerName, _questionText;
		sf::Text _playerText, _playerScore, _questionNumber;
		std::string str;
		sf::String text;
		std::map<std::string, std::string>::iterator it;
		std::map<std::string, std::string>  questions;
		std::vector<sf::Sprite> qSprites;
		int qCount;
	};
}
//