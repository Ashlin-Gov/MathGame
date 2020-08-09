#include "QuestionData.h"

MathWars::QuestionData::QuestionData(PlayerDataRef player) : _players(player){
	loadQuestions("Questions/Addition.txt");
	loadQuestions("Questions/Subtraction.txt");
	loadQuestions("Questions/Multiplication.txt");
	loadQuestions("Questions/Division.txt");
	
}

void MathWars::QuestionData::loadQuestions(std::string path){
	std::ifstream file(path);
	std::string q, a;
	if (file.is_open()) {
		while (file >> q >> a) {
			if (path.find("Addition") != std::string::npos) {
				this->Addition.push_back(q);
				this->addAns.push_back(a);
			}
			else if (path.find("Subtraction") != std::string::npos) {
					this->Subtracton.push_back(q);
					this->subAns.push_back(a);
			}
			else if (path.find("Multiplication") != std::string::npos) {
					this->Multiplication.push_back(q);
					this->mulAns.push_back(a);
			}
			else if (path.find("Division") != std::string::npos) {
					this->Division.push_back(q);
					this->divAns.push_back(a);
			}
		}
	}
}

void MathWars::QuestionData::selectRanQuestions(){
	resetQuestions();
	if (this->_players->difficulty.compare("E") == 0) {
		//Change to numQuesitons
		int count = 0;
		
		srand((unsigned)time(0));
		int index;

		//Addition
		while (count < 5) {
			index = (rand() % 100) + 1;
			
			if (Questions.count(Addition.at(index)) == 0) {
				Questions[Addition.at(index)] = addAns.at(index);
				count++;
			}
		}
		count = 0;
		//Subtraction
		while (count < 5) {
			index = rand() % (e.h + 1);
			if (Questions.count(Subtracton.at(index)) == 0) {
				Questions[Subtracton.at(index)] = subAns.at(index);
				count++;
			}
		}
		count = 0;
		//Multiplication
		while (count < 5) {
			index = rand() % (e.h) + 1;
			if (Questions.count(Multiplication.at(index)) == 0) {
				Questions[Multiplication.at(index)] = mulAns.at(index);
				count++;
			}
		}
		count = 0;
		//Division
		while (count < 5) {
			index = rand() % (e.h) + 1;
			if (Questions.count(Division.at(index)) == 0) {
				Questions[Division.at(index)] = divAns.at(index);
				count++;
			}
		}
		count = 0;

	}
	else if (this->_players->difficulty.compare("M") == 0) {
		for (int i = 0; i < 5; i++) {
			int index = rand() % (m.h + 1) + m.l;
			Questions[Addition.at(index)] = addAns.at(index);
		}
		//Subtraction
		for (int i = 0; i < 5; i++) {
			int index = rand() % (m.h + 1) + m.l;
			Questions[Subtracton.at(index)] = subAns.at(index);
		}
		//Multiplication
		for (int i = 0; i < 5; i++) {
			int index = rand() % (m.h + 1) + m.l;
			Questions[Multiplication.at(index)] = mulAns.at(index);
		}
		//Division
		for (int i = 0; i < 5; i++) {
			int index = rand() % (m.h + 1) + m.l;
			Questions[Division.at(index)] = divAns.at(index);
		}
	}
	else if (this->_players->difficulty.compare("H") == 0) {
		for (int i = 0; i < 5; i++) {
			int index = rand() % (h.h + 1) + h.l;
			Questions[Addition.at(index)] = addAns.at(index);
		}
		//Subtraction
		for (int i = 0; i < 5; i++) {
			int index = rand() % (h.h + 1) + h.l;
			Questions[Subtracton.at(index)] = subAns.at(index);
		}
		//Multiplication
		for (int i = 0; i < 5; i++) {
			int index = rand() % (h.h + 1) + h.l;
			Questions[Multiplication.at(index)] = mulAns.at(index);
		}
		//Division
		for (int i = 0; i < 5; i++) {
			int index = rand() % (h.h + 1) + h.l;
			Questions[Division.at(index)] = divAns.at(index);
		}
	}
}

void MathWars::QuestionData::resetQuestions(){
	this->Questions.clear();
}

std::map<std::string, std::string> MathWars::QuestionData::getQuestions(){
	return Questions;
}
//