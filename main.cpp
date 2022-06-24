#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow 
        window(sf::VideoMode(640, 480), "Bounchin mushroom");

    sf::Texture mushroomTexture;

    mushroomTexture.loadFromFile("mushroom.png");

    sf::Sprite mushroom(mushroomTexture);
    sf::Vector2u size =
        mushroomTexture.getSize();
    mushroom.setOrigin(size.x/2, size.y/2);
    sf::Vector2f increment(0.4f, 0.4f);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if((mushroom.getPosition().x + (size.x / 2) >
        window.getSize().x && increment.x > 0) ||
        (mushroom.getPosition().x - (size.x / 2) < 0 &&
        increment.x < 0))
        {
            // Reverse the direction on X axis.
            increment.x = -increment.x;
        }
        if((mushroom.getPosition().y + (size.y / 2) >
        window.getSize().y && increment.y > 0) ||
        (mushroom.getPosition().y - (size.y / 2) < 0 &&
        increment.y < 0))
        {
            // Reverse the direction on Y axis.
            increment.y = -increment.y;
        }
        mushroom.setPosition(mushroom.getPosition() + increment);
        mushroom.setColor(sf::Color(255, 0, 0, 255));
        window.clear(sf::Color(16,16,16,255));
        window.draw(mushroom); // Render our shape.
        window.display();
    }

    return 0;
}