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
      int getScore()
      {
          return player_score;
      }

      void setScore(int newScore)
      {
          player_score = newScore;
      }

      void takeDamage() {};
      void move() {};
      void shootBullets() {};
};

int main()
{
    // define the video mode (with dimensions)
    sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    //create window object with specific dimensions and title
    sf::RenderWindow* window = new sf::RenderWindow(videoMode, "Space Invaders");

    // game loop
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            // check for window close
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // clear window
        window->clear(sf::Color::Blue);

        // Draw Content here
        //-------------------


        // ------------------
     
        //displat the content
        window->display();

        Player player;
        std::cout << "\nPlayer Score: " << player.getScore() << "\n";

        player.setScore(100);

        std::cout << "Player modified score: " << player.getScore() << "\n";
    }

    return 0;
}