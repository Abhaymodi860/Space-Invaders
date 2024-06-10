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
        //-------------------
        // Draw circle
        sf::CircleShape circle(50);  // radius 50
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(400, 300); // set position (x, y)
        window->draw(circle);

        // Create a rectangle shape
        sf::RectangleShape rectangle(sf::Vector2f(100, 100));

        // Set the position of the rectangle
        rectangle.setPosition(10, 10);

        rectangle.setFillColor(sf::Color::Red);

        rectangle.setOutlineColor(sf::Color::Magenta);
        rectangle.setOutlineThickness(5);
        window->draw(rectangle);

        sf::CircleShape Triangle(50, 3);  // radius 50
        Triangle.setFillColor(sf::Color::Black);
        Triangle.setPosition(700, 300); // set position (x, y)
        window->draw(Triangle);

        // displaying an image
        sf::Texture outscal_texture;
        outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

        sf::Sprite outscal_sprite;
        outscal_sprite.setTexture(outscal_texture);

        outscal_sprite.setPosition(200, 100);
        outscal_sprite.setRotation(45);
        outscal_sprite.setScale(0.5, 0.5);
       
        window->draw(outscal_sprite);

        // displaying text
        sf::Font font;
        font.loadFromFile("assets/fonts/OpenSans.ttf");
        sf::Text text("SFML is awesome!", font, 50);
        text.setFillColor(sf::Color::Red);
        text.setPosition(300, 200);
        window->draw(text);

        // ------------------
     
        //displat the content
        window->display();
    }

    return 0;
}