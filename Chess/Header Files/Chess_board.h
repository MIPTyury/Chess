#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Figures.h"

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
      color = sf::Color::Red;
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

void figures_positions_init () {
  for (int i = 0; i < 8; i++) {
    white_pawns[i].white_pawn();
    white_pawns[i].set_pos(50 + 75 * i, 160 + 75 * 6);

    black_pawns[i].black_pawn();
    black_pawns[i].set_pos(50 + 75 * i, 160 + 75 * 1);
  }
  white_queen.white_queen();
  white_queen.set_pos(50 + 75 * 3, 160 + 75 * 7);

  white_king.white_king();
  white_king.set_pos(50 + 75 * 4, 160 + 75 * 7);

  black_king.black_king();
  black_king.set_pos(50 + 75 * 3, 160);

  black_queen.black_queen();
  black_queen.set_pos(50 + 75 * 4, 160);

  for (int i = 0; i < 2; i++) {
    white_bishop[i].white_bishop();
    white_knight[i].white_knight();
    white_rook[i].white_rook();

    black_bishop[i].black_bishop();
    black_knight[i].black_knight();
    black_rook[i].black_rook();
  }
  white_bishop[0].set_pos(50 + 75 * 2, 160 + 75 * 7);
  white_bishop[1].set_pos(50 + 75 * 5, 160 + 75 * 7);
  white_knight[0].set_pos(50 + 75 * 1, 160 + 75 * 7);
  white_knight[1].set_pos(50 + 75 * 6, 160 + 75 * 7);
  white_rook[0].set_pos(50 + 75 * 0, 160 + 75 * 7);
  white_rook[1].set_pos(50 + 75 * 7, 160 + 75 * 7);

  black_bishop[0].set_pos(50 + 75 * 2, 160);
  black_bishop[1].set_pos(50 + 75 * 5, 160);
  black_knight[0].set_pos(50 + 75 * 1, 160);
  black_knight[1].set_pos(50 + 75 * 6, 160);
  black_rook[0].set_pos(50 + 75 * 0, 160);
  black_rook[1].set_pos(50 + 75 * 7, 160);

}

void board_draw(sf::RenderWindow &window) {

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

  figures_positions_init();

  for (int i = 0; i < 8; i++) {
    white_pawns[i].draw(window);
    black_pawns[i].draw(window);
  }

  white_queen.draw(window);
  white_king.draw(window);

  black_queen.draw(window);
  black_king.draw(window);

  for (int i = 0; i < 2; i++) {
    white_rook[i].draw(window);
    white_knight[i].draw(window);
    white_bishop[i].draw(window);

    black_rook[i].draw(window);
    black_knight[i].draw(window);
    black_bishop[i].draw(window);
  }
}

