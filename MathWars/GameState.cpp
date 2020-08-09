#include "Definitions.h"
#include "GameState.h"
#include "SettingState.h"
#include "ScoreboardState.h"
#include <iostream>
#include <fstream>
namespace MathWars
{
	GameState::GameState(GameDataRef data, PlayerDataRef player) : _data(data), _players(player),_questions(player) {
		
	}

	void GameState::Init() {
		this->_data->assets.LoadTexture("Game Background", Game_Screen_Background);
		_backround.setTexture(this->_data->assets.GetTexture("Game Background"));
		_backround.setScale(1.030, 1.075);

		//
		this->_data->assets.LoadTexture("Submit", Submit);
		_confirmBtn.setTexture(this->_data->assets.GetTexture("Submit"));
		_confirmBtn.setScale(0.40f, 0.40f);
		_confirmBtn.setPosition(535, 615);

		//Load Font 
		if (!font.loadFromFile("Assets/helsinki.ttf")) {
			std::cout << " Font Not Loaded";
		}

		//Avatar + Name Display
		_avatar.setTexture(this->_data->assets.GetTexture(this->_players->playerData.at(this->_players->pSelected - 1).getAvatar()));
		_avatar.setScale(0.40f, 0.35f);
		_avatar.setPosition(70, 160);

		_playerName.setFont(font);
		_playerName.setString(this->_players->playerData.at(this->_players->pSelected - 1).getName());
		_playerName.scale(0.5f, 0.5f);
		_playerName.setPosition(70 + (_avatar.getGlobalBounds().width / 2) - (_playerName.getGlobalBounds().width / 2), 310);

		//INIT P1 Data
		playerScore = 0;
		this->_players->playerData.at(0).setSelected(true);

		//Score Text
		_playerScore.setFont(font);
		_playerScore.setString("Score: 0");
		_playerScore.setPosition(790, 110);
		_playerScore.setCharacterSize(50);
		_playerScore.setFillColor(sf::Color::Color(208, 74, 186, 255));
		_playerScore.setOutlineColor(sf::Color::Black);
		_playerScore.setOutlineThickness(2);
		
		//Questions Count
		qCount = 0;
		
		//QuestionCount Text
		_questionNumber.setFont(font);
		_questionNumber.setString("Question: 1");
		_questionNumber.setPosition(250, 110);
		_questionNumber.setCharacterSize(50);
		_questionNumber.setFillColor(sf::Color::Color(208, 74, 186, 255));
		_questionNumber.setOutlineColor(sf::Color::Black);
		_questionNumber.setOutlineThickness(2);

		//Questions Loaded int Map
		_questions.selectRanQuestions();
		questions = _questions.getQuestions();
		it = questions.begin();

		//Question and Answer Text
		this->_data->assets.LoadTexture("1", T_ONE);
		this->_data->assets.LoadTexture("2", T_TWO);
		this->_data->assets.LoadTexture("3", T_THREE);
		this->_data->assets.LoadTexture("4", T_FOUR);
		this->_data->assets.LoadTexture("5", T_FIVE);
		this->_data->assets.LoadTexture("6", T_SIX);
		this->_data->assets.LoadTexture("7", T_SEVEN);
		this->_data->assets.LoadTexture("8", T_EIGHT);
		this->_data->assets.LoadTexture("9", T_NINE);
		this->_data->assets.LoadTexture("0", T_ZERO);
		this->_data->assets.LoadTexture("div", T_DIV);
		this->_data->assets.LoadTexture("-", T_MINUS);
		this->_data->assets.LoadTexture("+", T_PLUS);
		this->_data->assets.LoadTexture("mul", T_MUL);
		
		loadQuestions();
		
		//Answer Text
		_playerText.setFont(font);
		_playerText.setPosition(510, 515);
		_playerText.setCharacterSize(64);
		_playerText.setFillColor(sf::Color::Color(208,74,186,255));
		_playerText.setOutlineColor(sf::Color::Black);
		_playerText.setOutlineThickness(2);
		
	}

	void GameState::HandleInput() {
		sf::Event event;

		while (this->_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}

			//Answer Entered
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == '\b') {
					if (str.length() > 0)
						str.pop_back();
				}
				else if (event.text.unicode < 58 && event.text.unicode > 47 || event.text.unicode == 45) {//Numbers Only
					if (str.length() < 5) {
						str += static_cast<char>(event.text.unicode);
					}
				}
				_playerText.setString(str);
			}
			//Check if Answer Correct  (this->_data->input.KeyEntered(sf::Keyboard::Enter))
			if (this->_data->input.IsSpriteClicked(this->_confirmBtn, sf::Mouse::Left, this->_data->window) || (event.type == sf::Event::KeyReleased &&event.key.code == sf:: Keyboard::Enter)){
				qCount++;//Keep Counter Here
				
				if (qCount < 20) {
					_questionNumber.setString("Question: " + std::to_string(qCount + 1));
					if (_playerText.getString() != it->second) {
						this->_players->playerData.at(this->_players->pSelected - 1).addIncorrectQuestion(it->first, it->second);
					}
					else {
						playerScore += 1;
						_playerScore.setString("Score: " + std::to_string(playerScore));
					}
					it++;
					loadQuestions();
				}
			}
			if (qCount == 19) {
				if (this->_players->playerData.size() == 1) {
					_data->machine.AddState(StateRef(new ScoreboardState(_data, _players)), true);
				}
				else {
					if (this->_players->playerData.at(0).getSelected() == true && this->_players->playerData.at(1).getSelected() == true) {
						_data->machine.AddState(StateRef(new SettingState(_data, _players)), true);
					}
					nextPlayer();
				}
			}
			
		}
	}

	void GameState::Update(float dt) {
		_questionText.setString(it->first);
		this->_data->assets.LoadTexture("SubmitC", SubmitC);
		if (this->_data->input.IsSpriteHovered(this->_confirmBtn, this->_data->window) == 1) {
			_confirmBtn.setTexture(this->_data->assets.GetTexture("SubmitC"));
		}
		else {
			_confirmBtn.setTexture(this->_data->assets.GetTexture("Submit"));
		}
	}

	void GameState::loadQuestions() {
		str = "";
		_playerText.setString("");
		std::string q = it->first;
		std::vector<std::string> question;
		question.clear();
		for (int i = 0; i < q.length(); i++) {
			question.push_back(std::string(1, q.at(i)));
		}
		qSprites.clear();
		for (int i = 0; i < question.size(); i++) {
			if (question.at(i) == "/") {
				question.at(i) = "div";
			}
			else if (question.at(i) == "*") {
				question.at(i) = "mul";
			}

			sf::Sprite temp;
			temp.setTexture(this->_data->assets.GetTexture(question.at(i)));
			qSprites.push_back(temp);
		}
		int pos = 300;
		if (qSprites.size() == 4) {
			pos = 425;
		}
		else if (qSprites.size() == 5) {
			pos = 350;
		}
		else if (qSprites.size() == 3) {
			pos = 460;
		}
		for (int i = 0; i < qSprites.size(); i++) {
			
			qSprites.at(i).setPosition(pos, 270);
			qSprites.at(i).setScale(1.2, 1.2);

			pos += qSprites.at(i).getGlobalBounds().width;
		}
	}

	void GameState::loadAnswers(){

	}

	void GameState::nextPlayer()
	{
		//qCount = 0;
		this->_players->playerData.at(this->_players->pSelected - 1).setScore(playerScore);
		playerScore = 0;
		if (this->_players->pSelected < this->_players->numPlayers) {
			this->_players->pSelected++;
			this->_players->playerData.at(this->_players->pSelected - 1).setSelected(true);
			_data->machine.AddState(StateRef(new GameState(_data, _players)), true);
		}
	}



	void GameState::Draw(float dt) {
		this->_data->window.clear(sf::Color::White);

		this->_data->window.draw(_backround);
		this->_data->window.draw(this->_avatar);
		this->_data->window.draw(this->_playerName);
		
		this->_data->window.draw(this->_playerText);
		this->_data->window.draw(this->_confirmBtn);

		//Question Data
		this->_data->window.draw(this->_questionNumber);
		this->_data->window.draw(this->_questionText);

		//PLayer Data
		this->_data->window.draw(this->_playerScore);
		for (int i = 0; i < qSprites.size(); i++) {
			this->_data->window.draw(this->qSprites.at(i));
		}

		this->_data->window.display();

	}
}
//