#include "opponent.h"
#include <stdio.h>
#include <memory>
void Opponent::Draw(graphics::Image &opponent) {
  std::vector<int> monitor_body = {x_ + 7,  y_ + 5,  x_ + 11, y_ + 26,
                                   x_ + 36, y_ + 26, x_ + 40, y_ + 5};

  opponent.DrawPolygon(monitor_body, 245, 245, 189);

  opponent.DrawLine(x_ + 6, y_ + 5, x_ + 10, y_ + 26, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 10, y_ + 26, x_ + 38, y_ + 26, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 37, y_ + 26, x_ + 41, y_ + 5, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 6, y_ + 5, x_ + 41, y_ + 5, 0, 0, 0, 1);

  std::vector<int> screen = {x_ + 10, y_ + 7,  x_ + 37, y_ + 7,
                             x_ + 34, y_ + 23, x_ + 13, y_ + 23};

  opponent.DrawPolygon(screen, 0, 200, 163);

  std::vector<int> computer_body = {
      x_ + 18, y_ + 27, x_ + 18, y_ + 29, x_ + 9,  y_ + 29, x_ + 5,
      y_ + 32, x_ + 5,  y_ + 44, x_ + 44, y_ + 44, x_ + 44, y_ + 32,
      x_ + 40, y_ + 29, x_ + 29, y_ + 29, x_ + 29, y_ + 27};

  opponent.DrawPolygon(computer_body, 245, 245, 189);
  // monitor stand
  opponent.DrawLine(x_ + 18, y_ + 27, x_ + 18, y_ + 29, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 15, y_ + 29, x_ + 18, y_ + 29, 0, 0, 0, 1);

  opponent.DrawRectangle(x_ + 16, y_ + 31, 2, 1, 0, 0, 0);
  opponent.DrawRectangle(x_ + 17, y_ + 32, 1, 1, 0, 0, 0);
  opponent.DrawRectangle(x_ + 15, y_ + 30, 1, 1, 0, 0, 0);

  opponent.DrawLine(x_ + 18, y_ + 33, x_ + 29, y_ + 33, 0, 0, 0, 1);

  opponent.DrawLine(x_ + 29, y_ + 27, x_ + 29, y_ + 29, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 29, y_ + 29, x_ + 32, y_ + 29, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 32, y_ + 29, x_ + 32, y_ + 30, 0, 0, 0, 1);

  opponent.DrawRectangle(x_ + 30, y_ + 31, 2, 1, 0, 0, 0);
  opponent.DrawRectangle(x_ + 30, y_ + 32, 1, 1, 0, 0, 0);

  opponent.DrawCircle(x_ + 36, y_ + 33, 1, 255, 0, 0);

  opponent.DrawLine(x_ + 5, y_ + 39, x_ + 9, y_ + 35, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 5, y_ + 39, x_ + 5, y_ + 44, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 5, y_ + 44, x_ + 44, y_ + 44, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 44, y_ + 44, x_ + 44, y_ + 39, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 44, y_ + 44, x_ + 44, y_ + 39, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 44, y_ + 39, x_ + 39, y_ + 35, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 9, y_ + 35, x_ + 39, y_ + 35, 0, 0, 0, 1);

  opponent.DrawLine(x_ + 9, y_ + 29, x_ + 15, y_ + 29, 0, 0, 0, 1);

  opponent.DrawLine(x_ + 9, y_ + 29, x_ + 5, y_ + 32, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 5, y_ + 32, x_ + 5, y_ + 39, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 29, y_ + 29, x_ + 40, y_ + 29, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 40, y_ + 29, x_ + 44, y_ + 32, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 44, y_ + 32, x_ + 44, y_ + 39, 0, 0, 0, 1);

  opponent.DrawLine(x_ + 11, y_ + 37, x_ + 8, y_ + 42, 0, 0, 0, 1);

  opponent.DrawLine(x_ + 8, y_ + 42, x_ + 41, y_ + 42, 0, 0, 0, 1);

  opponent.DrawLine(x_ + 41, y_ + 42, x_ + 38, y_ + 37, 0, 0, 0, 1);
  opponent.DrawLine(x_ + 11, y_ + 37, x_ + 38, y_ + 37, 0, 0, 0, 1);

  std::string first_line = "YOU";

  std::string second_line = "TWIT";

  opponent.DrawText(x_ + 16, y_ + 7, first_line, 8, 250, 236, 10);

  opponent.DrawText(x_ + 14, y_ + 15, second_line, 8, 250, 236, 10);
}

void Opponent::Move(const graphics::Image &image) {
  int cases = rand() % 5;
  x_ += 5;
  y_ += 5;

  switch (cases) {
    case 1:
      // moves to the right only
      x_ += 5;
      break;
    case 2:
      // moves to the left only
      x_ -= 5;
      break;
    case 3:
      // moves down only
      y_ += 5;
      break;
    case 4:
      // moves up only
      y_ -= 5;
      break;
  }

  if (IsOutOfBounds(image) == true) {
    SetIsActive(false);
  }
}

void OpponentProjectile::Draw(graphics::Image &opponent_proj) {
  opponent_proj.DrawLine(x_ + 1, y_ + 0, x_ + 1, y_ + 3, 0, 184, 44, 1);
  opponent_proj.DrawLine(x_ + 0, y_ + 3, x_ + 2, y_ + 3, 0, 184, 44, 1);
  opponent_proj.DrawLine(x_ + 0, y_ + 1, x_ + 1, y_ + 1, 0, 184, 44, 1);
  opponent_proj.DrawLine(x_ + 4, y_ + 0, x_ + 4, y_ + 3, 0, 184, 44, 1);
  opponent_proj.DrawLine(x_ + 4, y_ + 3, x_ + 6, y_ + 3, 0, 184, 44, 1);
  opponent_proj.DrawLine(x_ + 6, y_ + 0, x_ + 6, y_ + 3, 0, 184, 44, 1);
  opponent_proj.DrawLine(x_ + 4, y_ + 0, x_ + 6, y_ + 0, 0, 184, 44, 1);
}

void OpponentProjectile::Move(const graphics::Image &image) {
  x_ += 25;

  y_ += 25;

  if (IsOutOfBounds(image) == true) {
    SetIsActive(false);
  }
}

std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() {
  std::unique_ptr<OpponentProjectile> opponent_proj = nullptr;
  if (counter_ % 3 == 0) {
    opponent_proj = std::make_unique<OpponentProjectile>();
    counter_++;
    return opponent_proj;
  }

  counter_++;
  return opponent_proj;
}
