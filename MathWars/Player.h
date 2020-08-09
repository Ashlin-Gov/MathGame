#pragma once
#include <string>
#include <SFML/Graphics.hpp>
namespace MathWars{
	class Player
	{
	public:
		Player();
		Player(int id);
		//Player(std::string name);
		int getID();
		void setAvatar(std::string path);
		std::string getAvatar();
		void setScore(int score);
		int getScore();
		void setName(std::string name);
		std::string getName();
		void write();
		bool getSelected();
		void setSelected(bool selected);
		bool getPlayed();
		void addIncorrectQuestion(std::string q, std::string a);
		std::map<std::string, std::string>getIncorrectQuestions();


	private:
		int score;
		std::string avatar;
		int id;
		bool played;
		bool selected;
		std::string name;
		//std::map<std::string, std::string>::iterator it;
		std::map<std::string, std::string>  incorrectQuestions;
		//std::vector<int> queestions;
		//Add Character Portrait Stuff

	
	};
}
//
