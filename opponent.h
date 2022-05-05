#ifndef OPPONENT_H
#define OPPONENT_H
#include "cpputils/graphics/image.h"
#include "game_element.h"

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() {
    x_ = 0;
    y_ = 0;
    width_ = 7;
    height_ = 5;
  }

  OpponentProjectile(int x, int y) : GameElement(x, y, 7, 5) {}

  void Draw(graphics::Image &image) override;

  void Move(const graphics::Image &image) override;
};

class Opponent : public GameElement {
 public:
  Opponent() {
    x_ = 0;
    y_ = 0;
    width_ = 50;
    height_ = 50;
  }

  Opponent(int x, int y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image &image) override;

  void Move(const graphics::Image &image) override;

  std::unique_ptr<OpponentProjectile> LaunchProjectile();

 private:
  int counter_ = 0;
};

#endif
