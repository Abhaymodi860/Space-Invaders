#include <SFML/Graphics.hpp>

int main()
{
    // define the video mode (with dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    //create window object with specific dimensions and title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");

    // game loop
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            // check for window close
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // clear window
        window->clear(sf::Color::Yellow);

        // Draw Content here

        //displat the content
        window->display();
    }

    return 0;
}