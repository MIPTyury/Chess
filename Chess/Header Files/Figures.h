#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Figure {
private:
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Figure() {
      image.loadFromFile("..//Images/white_pawn.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    virtual void set_pos (int x, int y) {
      sprite.setPosition(x, y);
    }

    virtual void black_bishop () {
      image.loadFromFile("../Images/black_bishop.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }
};
