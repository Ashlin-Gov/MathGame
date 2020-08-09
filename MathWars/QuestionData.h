#pragma once
#include <iostream>
#include <fstream>

#include "Game.h"

namespace MathWars {
	struct Easy {
		const int l = 0;
		const int h = 100;
	};
	struct Medium {
		const int l = 101;
		const int h = 150;
	};
	struct Hard {
		const int l = 151;
		const int h = 200;
	};

	class QuestionData{
	public:
		QuestionData(PlayerDataRef player);
		void loadQuestions(std::string path);
		void selectRanQuestions();
		void resetQuestions();
		std::map<std::string, std::string> getQuestions();

	private:
		//Questions for Each Operation
		std::vector<std::string> Addition;
		std::vector<std::string> addAns;

		std::vector<std::string> Subtracton;
		std::vector<std::string> subAns;

		std::vector<std::string> Multiplication;
		std::vector<std::string> mulAns;

		std::vector<std::string> Division;
		std::vector<std::string> divAns;

		Easy e;
		Medium m;
		Hard h;

		//All ops put togethor
		std::map<std::string, std::string> Questions;

		//
		PlayerDataRef _players;


	};
}
//
