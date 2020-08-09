#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "Player.h"
//Dont Touch
namespace MathWars {
	//Create Struct
	struct PlayerData {
		//Manages Players Data
		int numPlayers;
		int pSelected = 1;
		std::vector<Player> playerData;
		std::string difficulty = "E";
	};
	struct GameData {
		//Manages Game Data
		StateMachine machine;
		sf::RenderWindow window;
		InputManager input;
		AssetManager assets;
		sf::Music music;
		int soundSwitch = 1;
	};


	//Rename GameData to GameDataReference
	typedef std::shared_ptr<GameData> GameDataRef;
	typedef std::shared_ptr<PlayerData> PlayerDataRef;
	
	class Game {
	public:
		Game(int width, int height, std::string title);
	private:
		//Declare Variables
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;
		//
		GameDataRef _data = std::make_shared<GameData>();
		PlayerDataRef _players = std::make_shared<PlayerData>();
		//int numPlayers = 0;

		void Run();
	};
}
//