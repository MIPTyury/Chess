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
      sprite.setPosition(0, 0);
    }

    void set_pos (int x, int y) {
      sprite.setPosition(x, y);
    }

    void draw (sf::RenderWindow& window) {
      window.draw(sprite);
    }

    void black_bishop () {
      image.loadFromFile("../Images/black_bishop.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    void black_king () {
      image.loadFromFile("../Images/black_king.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    void black_knight () {
      image.loadFromFile("../Images/black_knight.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    void black_pawn () {
      image.loadFromFile("../Images/black_pawn.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    void black_queen () {
      image.loadFromFile("../Images/black_queen.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    void black_rook () {
      image.loadFromFile("../Images/black_rook.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    void white_bishop () {
      image.loadFromFile("../Images/white_bishop.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }
    void white_king () {
      image.loadFromFile("../Images/white_king.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    void white_knight () {
      image.loadFromFile("../Images/white_knight.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    void white_pawn () {
      image.loadFromFile("../Images/white_pawn.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    void white_queen () {
      image.loadFromFile("../Images/white_queen.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }

    void white_rook () {
      image.loadFromFile("../Images/white_rook.png");
      texture.loadFromImage(image);
      texture.setSmooth(true);
      sprite.setTexture(texture);
    }
};

Figure white_pawns[8];
Figure black_pawns[8];
Figure white_king;
Figure black_king;
Figure white_queen;
Figure black_queen;
Figure white_bishop[2];
Figure black_bishop[2];
Figure white_knight[2];
Figure black_knight[2];
Figure white_rook[2];
Figure black_rook[2];


