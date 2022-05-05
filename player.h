#ifndef PLAYER_H
#define PLAYER_H
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"
class Player : public GameElement {
 public:
  Player() {
    x_ = 0;
    y_ = 0;
    width_ = 50;
    height_ = 60;
  }

  Player(int x, int y) : GameElement(x, y, 50, 60) {}

  void Draw(graphics::Image &image) override;

  void Move(const graphics::Image &image) override;
};

class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile() {
    x_ = 0;
    y_ = 0;
    width_ = 7;
    height_ = 7;
  }

  PlayerProjectile(int x, int y) : GameElement(x, y, 7, 7) {}

  void Draw(graphics::Image &image) override;

  void Move(const graphics::Image &image) override;
};

#endif
