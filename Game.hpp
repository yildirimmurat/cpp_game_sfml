#pragma once
#include "Window.hpp"
#include "EventManager.hpp"
#include "StateManager.hpp"
#include "SharedContext.hpp"
#include <iostream>

class Game{
public:
	Game();
	~Game();

	void Update();
	void Render();
	void LateUpdate();

	sf::Time GetElapsed();

	Window* GetWindow();
private:
	SharedContext m_context;
	Window m_window;
	StateManager m_stateManager;
	sf::Clock m_clock;
	sf::Time m_elapsed;
	void RestartClock();
};