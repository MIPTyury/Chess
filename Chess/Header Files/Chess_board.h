#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Chess_cell {
private:
    sf::Vector2f cell_size;
    sf::RectangleShape cell;
    sf::Color color;

public:
    Chess_cell() {
      cell_size.x = 75;
      cell_size.y = 75;
      cell.setSize(cell_size);
      cell.setFillColor(color);
      set_pos(0, 0);
    }

    void black() {
      color = sf::Color::Black;
      cell.setFillColor(color);
    }

    void white() {
      color = sf::Color::White;
      cell.setFillColor(color);
    }

    void draw(sf::RenderWindow &window) {
      window.draw(cell);
    }

    void set_pos(int x, int y) {
      cell.setPosition(x, y);
    }
};

class Board_marker {
private:
    sf::Vector2f board_marker_size;
    sf::RectangleShape board_marker;
    sf::Color color;

public:
    Board_marker() {
      board_marker_size.x = 75;
      board_marker_size.y = 75;
      board_marker.setSize(board_marker_size);
      board_marker.setFillColor(sf::Color::Cyan);
      set_pos(0, 0);
    }

    void draw(sf::RenderWindow &window) {
      window.draw(board_marker);
    }

    void set_pos(int x, int y) {
      board_marker.setPosition(x, y);
    }

    void set_size_left() {
      board_marker_size.x = 30;
      board_marker_size.y = 75;
      board_marker.setSize(board_marker_size);
    }

    void set_size_below() {
      board_marker_size.x = 75;
      board_marker_size.y = 30;
      board_marker.setSize(board_marker_size);
    }
};

void board_init(sf::RenderWindow &window) {

  sf::Font font;
  if (!font.loadFromFile("../Fonts/Times New Roman.ttf")) {
    return;
  }

  sf::Text board_marker_text;
  char row = 'a' - 1;
  char column = '9';
  board_marker_text.setFont(font);
  board_marker_text.setCharacterSize(48);
  board_marker_text.setString(row);
  board_marker_text.setFillColor(sf::Color::Black);
  board_marker_text.setPosition(20, 160);

  Chess_cell cells[8][8];
  Board_marker board_markers[16];

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cells[i][j].set_pos(50 + 75 * j, 160 + 75 * i);
      if ((i + j) % 2 == 0) {
        cells[i][j].white();
      } else if (i + j % 2 != 0) {
        cells[i][j].black();
      }
      cells[i][j].draw(window);
    }
  }

  for (int i = 0; i < 8; i++) {
    column--;
    board_marker_text.setPosition(20, 160 + 75 * i + 10);
    board_marker_text.setString(column);
    window.draw(board_marker_text);
  }

  for (int i = 8; i < 16; i++) {
    row++;
    board_marker_text.setPosition(50 + 75 * (i - 8) + 20, 160 + 75 * 8 - 10);
    board_marker_text.setString(row);
    window.draw(board_marker_text);
  }
}

