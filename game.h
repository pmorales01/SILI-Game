#ifndef GAME_H
#define GAME_H
#include <vector>
#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"
#include "opponent.h"
#include "player.h"
class Game : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 public:
  Game() { GameScreen_.Initialize(800, 600); }

  Game(int width, int height) { GameScreen_.Initialize(width, height); }

  graphics::Image &GetGameScreen();

  std::vector<std::unique_ptr<Opponent>> &GetOpponents();

  std::vector<std::unique_ptr<OpponentProjectile>> &GetOpponentProjectiles();

  std::vector<std::unique_ptr<PlayerProjectile>> &GetPlayerProjectiles();

  Player &GetPlayer();

  void CreateOpponents();

  void Init();

  void UpdateScreen();

  void Start();

  void MoveGameElements();

  void FilterIntersections();

  void OnAnimationStep();

  void OnMouseEvent(const graphics::MouseEvent &mouse_event);

  int GetScore();

  bool HasLost();

  void RemoveInactive();

  void LaunchProjectiles();

 private:
  graphics::Image GameScreen_;

  std::vector<std::unique_ptr<Opponent>> Opponent_;

  std::vector<std::unique_ptr<OpponentProjectile>> OpponentProjectile_;

  std::vector<std::unique_ptr<PlayerProjectile>> PlayerProjectile_;

  Player Player_;

  int score_ = 0;

  bool WinOrLose_;
};

#endif
