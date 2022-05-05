#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H
#include "cpputils/graphics/image.h"
class GameElement {
 public:
  GameElement() : x_(0), y_(0), width_(50), height_(50) {}

  GameElement(int x, int y, int width, int height) {
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
  }

  int GetX() const;

  int SetX(int x);

  int GetY() const;

  int SetY(int y);

  int GetWidth() const;

  int GetHeight() const;

  virtual void Draw(graphics::Image &image) = 0;

  bool GetIsActive() const;

  bool SetIsActive(bool status);

  virtual void Move(const graphics::Image &image) = 0;

  bool IntersectsWith(GameElement *game_element);

  bool IsOutOfBounds(const graphics::Image &image);

 protected:
  int x_;
  int y_;
  int width_;
  int height_;
  bool is_active = true;
};

#endif
