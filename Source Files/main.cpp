#include "../Header Files/Figures.h"

int main()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 16;
  int modeHeight = 1080;
  int modeWidth = 1920;
  sf::RenderWindow window(sf::VideoMode(modeWidth, modeHeight), "Chess", sf::Style::Default);

  sf::Image logo;
  if (!logo.loadFromFile("../Images/Logo.jpg")) {
    return -1;
  }
  window.setIcon(416, 416, logo.getPixelsPtr());

  // run the program as long as the window is open
  while (window.isOpen())
  {
    window.clear(sf::Color::Green);
    board_init(window);
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.display();
  }

  return 0;
}