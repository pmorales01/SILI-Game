#include "player.h"

void Player::Draw(graphics::Image &player) {
  std::vector<int> body = {
      x_ + 11, y_ + 11, x_ + 11, y_ + 17, x_ + 10, y_ + 17, x_ + 10, y_ + 19,
      x_ + 8,  y_ + 19, x_ + 8,  y_ + 21, x_ + 7,  y_ + 21, x_ + 7,  y_ + 23,
      x_ + 6,  y_ + 23, x_ + 6,  y_ + 25, x_ + 5,  y_ + 25, x_ + 5,  y_ + 27,
      x_ + 4,  y_ + 27, x_ + 4,  y_ + 31, x_ + 5,  y_ + 31, x_ + 5,  y_ + 33,
      x_ + 9,  y_ + 33, x_ + 9,  y_ + 35, x_ + 14, y_ + 35, x_ + 14, y_ + 49,
      x_ + 15, y_ + 49, x_ + 15, y_ + 51, x_ + 16, y_ + 51, x_ + 16, y_ + 53,
      x_ + 27, y_ + 53, x_ + 27, y_ + 55, x_ + 28, y_ + 55, x_ + 29, y_ + 47,
      x_ + 30, y_ + 47, x_ + 30, y_ + 44, x_ + 31, y_ + 44, x_ + 31, y_ + 42,
      x_ + 29, y_ + 42, x_ + 29, y_ + 32, x_ + 28, y_ + 32, x_ + 28, y_ + 24,
      x_ + 27, y_ + 24, x_ + 27, y_ + 20, x_ + 27, y_ + 20, x_ + 28, y_ + 15,
      x_ + 27, y_ + 15, x_ + 27, y_ + 13, x_ + 26, y_ + 13, x_ + 26, y_ + 11,
      x_ + 23, y_ + 11, x_ + 23, y_ + 9,  x_ + 24, y_ + 9};

  player.DrawPolygon(body, 241, 159, 229);

  std::vector<int> left_ear = {
      x_ + 7,  y_ + 1, x_ + 7,  y_ + 3,  x_ + 9,  y_ + 3,  x_ + 9,  y_ + 5,
      x_ + 15, y_ + 5, x_ + 15, y_ + 7,  x_ + 13, y_ + 7,  x_ + 13, y_ + 9,
      x_ + 11, y_ + 9, x_ + 11, y_ + 11, x_ + 14, y_ + 11, x_ + 14, y_ + 9,
      x_ + 16, y_ + 9, x_ + 16, y_ + 3,  x_ + 15, y_ + 3,  x_ + 15, y_ + 1};

  player.DrawPolygon(left_ear, 0, 0, 0);

  player.DrawRectangle(x_ + 10, y_ + 1, 4, 2, 185, 84, 25);

  std::vector<int> right_ear = {
      x_ + 20, y_ + 9,  x_ + 20, y_ + 11, x_ + 24, y_ + 11, x_ + 24,
      y_ + 9,  x_ + 25, y_ + 9,  x_ + 25, y_ + 11, x_ + 32, y_ + 11,
      x_ + 32, y_ + 9,  x_ + 26, y_ + 9,  x_ + 26, y_ + 7,  x_ + 25,
      y_ + 7,  x_ + 25, y_ + 5,  x_ + 23, y_ + 5,  x_ + 23, y_ + 9};

  player.DrawPolygon(right_ear, 0, 0, 0);

  std::vector<int> brown_ear = {
      x_ + 25, y_ + 5, x_ + 25, y_ + 7, x_ + 26, y_ + 7, x_ + 26, y_ + 9,
      x_ + 32, y_ + 9, x_ + 32, y_ + 7, x_ + 27, y_ + 7, x_ + 27, y_ + 5};

  player.DrawPolygon(brown_ear, 185, 84, 25);

  std::vector<int> left_eye = {x_ + 12, y_ + 11, x_ + 12, y_ + 21, x_ + 13,
                               y_ + 21, x_ + 13, y_ + 23, x_ + 14, y_ + 23,
                               x_ + 14, y_ + 21, x_ + 15, y_ + 21, x_ + 15,
                               y_ + 9,  x_ + 14, y_ + 9,  x_ + 14, y_ + 11};

  player.DrawPolygon(left_eye, 255, 255, 255);

  std::vector<int> right_eye = {
      x_ + 16, y_ + 11, x_ + 16, y_ + 23, x_ + 17, y_ + 23, x_ + 17,
      y_ + 25, x_ + 19, y_ + 25, x_ + 19, y_ + 23, x_ + 20, y_ + 23,
      x_ + 20, y_ + 13, x_ + 19, y_ + 13, x_ + 19, y_ + 11, x_ + 18,
      y_ + 11, x_ + 18, y_ + 9,  x_ + 17, y_ + 9,  x_ + 17, y_ + 11};

  player.DrawPolygon(right_eye, 255, 255, 255);

  player.DrawRectangle(x_ + 13, y_ + 15, 1, 4, 0, 0, 0);

  player.DrawRectangle(x_ + 17, y_ + 15, 1, 4, 0, 0, 0);

  player.DrawRectangle(x_ + 15, y_ + 9, 1, 14, 241, 159, 229);

  std::vector<int> brown_nose = {
      x_ + 6,  y_ + 23, x_ + 6,  y_ + 24, x_ + 8,  y_ + 24, x_ + 8,  y_ + 26,
      x_ + 9,  y_ + 26, x_ + 9,  y_ + 28, x_ + 14, y_ + 28, x_ + 14, y_ + 26,
      x_ + 15, y_ + 26, x_ + 15, y_ + 24, x_ + 13, y_ + 24, x_ + 13, y_ + 23};

  player.DrawPolygon(brown_nose, 185, 84, 25);

  std::vector<int> black_nose = {
      x_ + 6,  y_ + 23, x_ + 6,  y_ + 25, x_ + 7,  y_ + 25, x_ + 7,  y_ + 29,
      x_ + 8,  y_ + 29, x_ + 8,  y_ + 31, x_ + 9,  y_ + 31, x_ + 9,  y_ + 33,
      x_ + 11, y_ + 33, x_ + 11, y_ + 31, x_ + 13, y_ + 31, x_ + 13, y_ + 29,
      x_ + 15, y_ + 29, x_ + 15, y_ + 25, x_ + 14, y_ + 25, x_ + 14, y_ + 27,
      x_ + 9,  y_ + 27, x_ + 9,  y_ + 25, x_ + 8,  y_ + 25, x_ + 8,  y_ + 23};

  player.DrawPolygon(black_nose, 0, 0, 0);
  // left leg
  player.DrawRectangle(x_ + 16, y_ + 53, 2, 6, 241, 159, 229);

  player.DrawRectangle(x_ + 14, y_ + 55, 6, 2, 241, 159, 229);

  // right leg
  player.DrawRectangle(x_ + 27, y_ + 53, 2, 6, 241, 159, 229);

  player.DrawRectangle(x_ + 25, y_ + 55, 6, 2, 241, 159, 229);

  std::vector<int> spot = {
      x_ + 26, y_ + 30, x_ + 26, y_ + 35, x_ + 27, y_ + 35, x_ + 27, y_ + 38,
      x_ + 26, y_ + 38, x_ + 26, y_ + 43, x_ + 27, y_ + 43, x_ + 27, y_ + 39,
      x_ + 28, y_ + 39, x_ + 28, y_ + 34, x_ + 27, y_ + 34, x_ + 27, y_ + 30};

  player.DrawPolygon(spot, 0, 0, 0);

  std::vector<int> arm = {x_ + 13, y_ + 38, x_ + 11, y_ + 38, x_ + 11, y_ + 40,
                          x_ + 10, y_ + 40, x_ + 10, y_ + 44, x_ + 9,  y_ + 44,
                          x_ + 9,  y_ + 46, x_ + 10, y_ + 46, x_ + 10, y_ + 48,
                          x_ + 11, y_ + 48, x_ + 11, y_ + 46, x_ + 12, y_ + 46,
                          x_ + 12, y_ + 44, x_ + 11, y_ + 44, x_ + 11, y_ + 42,
                          x_ + 12, y_ + 42, x_ + 12, y_ + 40, x_ + 13, y_ + 40};

  player.DrawPolygon(arm, 241, 159, 229);

  // draws mouth
  player.DrawRectangle(x_ + 16, y_ + 35, 2, 2, 0, 0, 0);
  player.DrawRectangle(x_ + 17, y_ + 33, 1, 2, 0, 0, 0);
  player.DrawRectangle(x_ + 19, y_ + 29, 1, 4, 0, 0, 0);
  player.DrawRectangle(x_ + 20, y_ + 27, 1, 2, 0, 0, 0);
}

void Player::Move(const graphics::Image &image) {}

void PlayerProjectile::Draw(graphics::Image &player_proj) {
  player_proj.DrawCircle(x_ + 2, y_ + 4, 2, 223, 95, 54);

  player_proj.DrawCircle(x_ + 2, y_ + 4, 1, 91, 17, 109);

  player_proj.DrawLine(x_ + 2, y_ + 2, x_ + 2, y_ + 0, 0, 0, 0, 1);

  player_proj.DrawLine(x_ + 2, y_ + 0, x_ + 5, y_ + 0, 0, 0, 0, 1);

  player_proj.DrawLine(x_ + 5, y_ + 0, x_ + 5, y_ + 1, 0, 0, 0, 1);

  player_proj.DrawRectangle(x_ + 4, y_ + 2, 1, 1, 0, 0, 0);
  player_proj.DrawRectangle(x_ + 6, y_ + 2, 1, 1, 0, 0, 0);
  player_proj.DrawRectangle(x_ + 5, y_ + 3, 1, 1, 0, 0, 0);
}

void PlayerProjectile::Move(const graphics::Image &image) {
  y_ -= 10;

  if (IsOutOfBounds(image) == true) {
    SetIsActive(false);
  }
}
