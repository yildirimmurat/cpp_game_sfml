#pragma once
#include "Window.hpp"
#include "EventManager.hpp"
struct SharedContext{
	SharedContext()
		:m_wind(nullptr),
		m_eventManager(nullptr){}
	Window* m_wind;
	EventManager* m_eventManager;
};