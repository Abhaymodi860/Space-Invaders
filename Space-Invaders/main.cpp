#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
  private: 
      // private properties
      int health = 3;
      sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
      int player_score = 0;
      int movement_speed = 5;

  public:
      // public properties
      sf::Texture player_texture;
      sf::Sprite player_sprite;

      // public set and get function
      void move(float offsetX)
      {
          position.x += offsetX;
      }

      int getMoveSpeed()
      {
          return movement_speed;
      }

      sf::Vector2f getPosition() 
      {
          return position;
      }

      
};

int main()
{
    // define the video mode (with dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    //create window object with specific dimensions and title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "Space Invaders");
    
    // Player object
    Player player;

    // load player ship texture
    player.player_texture.loadFromFile("assets/textures/player_ship.png");

    // set the player sprite
    player.player_sprite.setTexture(player.player_texture);

    // game loop
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            // check for window close
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // handling keyboard inputs
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.move(-0.01f * player.getMoveSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player.move(0.01f * player.getMoveSpeed());
        }

        // clear window
        window->clear(sf::Color::Blue);

        // setting position of player sprite
        player.player_sprite.setPosition(player.getPosition());

        // Draw Content here
        //-------------------
        window->draw(player.player_sprite);

        // ------------------
     
        //displat the content
        window->display();

       
        //std::cout << "\nPlayer Score: " << player.getScore() << "\n";

        //player.setScore(100);

        //std::cout << "Player modified score: " << player.getScore() << "\n";
    }

    return 0;
}