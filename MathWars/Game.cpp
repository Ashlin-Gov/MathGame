#include "Game.h"
#include "SplashState.h"

namespace MathWars {
	Game::Game(int w, int h, std::string t) {
		_data->window.create(sf::VideoMode(w, h), t, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(this->_data,_players)));
		this->Run();
	}

	void Game::Run() {
		float newTime, frameTime, insert;

		float cTime = this->_clock.getElapsedTime().asSeconds();
		float Sum = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - cTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			cTime = newTime;
			Sum += frameTime;

			while (Sum >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);
				

				Sum -= dt;
			}

			insert = Sum / dt;
			this->_data->machine.GetActiveState()->Draw(insert);
		}
	}
}
//