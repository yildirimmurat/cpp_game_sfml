#include "Game.hpp"

Game::Game(): m_window("added event manager", sf::Vector2u(800, 600))
{
    RestartClock();
    srand(time(nullptr));
    
    m_texture.loadFromFile("mushroom.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setOrigin(m_texture.getSize().x/2, m_texture.getSize().y/2);
    m_sprite.setPosition(m_texture.getSize().x/2, m_texture.getSize().y/2);

    m_window.GetEventManager()->AddCallback("Move", &Game::MoveSprite, this);
}
Game::~Game(){}

void Game::Update()
{
    m_window.Update();
}
void Game::Render()
{
    m_window.BeginDraw();
    m_window.GetRenderWindow()->draw(m_sprite);
    m_window.EndDraw();
}

sf::Time Game::GetElapsed()
{
    return Clock.getElapsedTime();
}
void Game::RestartClock()
{
    Clock.restart();
}

void Game::MoveSprite(EventDetails* l_details)
{
    sf::Vector2i mousepos = m_window.GetEventManager()->GetMousePos(m_window.GetRenderWindow());
    m_sprite.setPosition(mousepos.x, mousepos.y);
    std::cout << "Moving sprite to: " << mousepos.x << ":" << mousepos.y << std::endl; 
}

Window* Game::GetWindow()
{
    return &m_window;
}