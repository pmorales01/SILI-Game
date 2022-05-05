#include "game_element.h"

int GameElement::GetX() const { return x_; }

int GameElement::SetX(int x) {
  x_ = x;
  return x_;
}

int GameElement::GetY() const { return y_; }

int GameElement::SetY(int y) {
  y_ = y;
  return y_;
}

int GameElement::GetWidth() const { return width_; }

int GameElement::GetHeight() const { return height_; }

bool GameElement::GetIsActive() const { return is_active; }

bool GameElement::SetIsActive(bool status) {
  is_active = status;
  return is_active;
}

bool GameElement::IntersectsWith(GameElement *game_element) {
  if ((game_element->GetX() == x_) || (game_element->GetY() == y_)) {
    return true;
  }

  if (game_element->GetX() + game_element->GetWidth() < x_ ||
      game_element->GetY() + game_element->GetHeight() < y_ ||
      x_ + width_ < game_element->GetX() ||
      y_ + height_ < game_element->GetY()) {
    return true;
  }
  return false;
}

bool GameElement::IsOutOfBounds(const graphics::Image &image) {
  if (GetX() > image.GetWidth() || GetX() < 0) {
    return true;
  } else if (GetY() > image.GetHeight() || GetY() < 0) {
    return true;
  }
  return false;
}
