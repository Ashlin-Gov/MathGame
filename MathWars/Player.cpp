#include "Player.h"
namespace MathWars {
	Player::Player()
	{
	}
	Player::Player(int id)
	{
		this->id = id;
	}

	int Player::getID()
	{
		return this->id;
	}

	void Player::setAvatar(std::string path)
	{
		avatar = path;
	}



	std::string Player::getAvatar()
	{
		return this->avatar;
	}

	void MathWars::Player::setScore(int score){
		this->score = score;
	}

	int Player::getScore()
	{
		return score;
	}

	void Player::setName(std::string name){
		this->name = name;
	}

	std::string Player::getName(){
		return this->name;
	}

	void MathWars::Player::write(){

	}
	bool Player::getSelected()
	{
		return selected;
	}
	void Player::setSelected(bool selected)
	{
		this->selected = selected;
	}
	bool Player::getPlayed()
	{
		return this->played;
	}
	void Player::addIncorrectQuestion(std::string q, std::string a){
		incorrectQuestions[q] = a;
	}
	std::map<std::string, std::string> Player::getIncorrectQuestions()
	{
		return incorrectQuestions;
	}
}
//