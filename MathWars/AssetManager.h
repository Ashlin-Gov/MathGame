#pragma once	
#include <map>
#include "SFML\Audio.hpp"
#include <SFML/Graphics.hpp>

namespace MathWars {
	class AssetManager {
	public:
		AssetManager() {}
		~AssetManager() {}

		void LoadTexture(std::string name, std::string filename);
		sf::Texture& GetTexture(std::string name);
		void loadSound(std::string name,std::string path);
		sf::Music getMusic(std::string path);

	private:
		std::map<std::string, sf::Texture> _texture;
		std::map<std::string, sf::Sound> _sounds;
	};
}
//