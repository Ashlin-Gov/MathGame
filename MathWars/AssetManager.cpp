#include "AssetManager.h"

namespace MathWars {
	void AssetManager::LoadTexture(std::string name, std::string filename) {
		sf::Texture texture;
		if (texture.loadFromFile(filename)) {
			texture.setSmooth(true);
			this->_texture[name] = texture;
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name) {
		return this->_texture.at(name);
	}
	void AssetManager::loadSound(std::string name, std::string path)
	{
		sf::SoundBuffer buffer;
		if (!buffer.loadFromFile(path)) {
			
		}
		sf::Sound sound;
		sound.setBuffer(buffer);
		this->_sounds[name] = sound;
	}
}
//