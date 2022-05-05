#include "game.h"
#include <stdio.h>
#include "cpputils/graphics/image_event.h"

graphics::Image &Game::GetGameScreen() { return GameScreen_; }

std::vector<std::unique_ptr<Opponent>> &Game::GetOpponents() {
  return Opponent_;
}

std::vector<std::unique_ptr<OpponentProjectile>>
    &Game::GetOpponentProjectiles() {
  return OpponentProjectile_;
}

std::vector<std::unique_ptr<PlayerProjectile>> &Game::GetPlayerProjectiles() {
  return PlayerProjectile_;
}

Player &Game::GetPlayer() { return Player_; }

void Game::CreateOpponents() {
  // creates opponnents at random location on top of screen
  int x = rand() % 600;
  Opponent_.push_back(std::make_unique<Opponent>(x, 0));
}

void Game::Init() {
  Player_.SetX(100);
  Player_.SetY(100);

  GameScreen_.AddMouseEventListener(*this);

  GameScreen_.AddAnimationEventListener(*this);
}
void Game::UpdateScreen() {
  GetGameScreen().DrawRectangle(0, 0, 800, 600, 255, 255, 255);

  if (Player_.GetIsActive() == true) {
    Player_.Draw(GameScreen_);
  }

  for (int i = 0; i < Opponent_.size(); i++) {
    if (GetOpponents().at(i)->GetIsActive() == true) {
      GetOpponents().at(i)->Draw(GameScreen_);
    }
  }

  for (int i = 0; i < OpponentProjectile_.size(); i++) {
    if (GetOpponentProjectiles().at(i)->GetIsActive() == true) {
      GetOpponentProjectiles().at(i)->Draw(GameScreen_);
    }
  }

  for (int i = 0; i < PlayerProjectile_.size(); i++) {
    if (GetPlayerProjectiles().at(i)->GetIsActive() == true) {
      GetPlayerProjectiles().at(i)->Draw(GameScreen_);
    }
  }

  std::string score_title = "Score: " + std::to_string(GetScore());

  GameScreen_.DrawText(0, 0, score_title, 30, 0, 0, 0);

  std::string GameOver = "Game Over";

  if (WinOrLose_ == true) {
    GameScreen_.DrawText(300, 250, GameOver, 50, 0, 0, 0);
  }
}

void Game::Start() { GameScreen_.ShowUntilClosed("Display", 60); }

void Game::MoveGameElements() {
  for (int i = 0; i < Opponent_.size(); i++) {
    if (GetOpponents().at(i)->GetIsActive() == true) {
      GetOpponents().at(i)->Move(GameScreen_);
    }
  }

  for (int i = 0; i < OpponentProjectile_.size(); i++) {
    if (GetOpponentProjectiles().at(i)->GetIsActive() == true) {
      GetOpponentProjectiles().at(i)->Move(GameScreen_);
    }
  }

  for (int i = 0; i < PlayerProjectile_.size(); i++) {
    if (GetPlayerProjectiles().at(i)->GetIsActive() == true) {
      GetPlayerProjectiles().at(i)->Move(GameScreen_);
    }
  }
}

void Game::LaunchProjectiles() {
  for (int i = 0; i < Opponent_.size(); i++) {
    if (GetOpponents().at(i)->LaunchProjectile() != nullptr) {
      OpponentProjectile_.push_back(
          std::move(std::make_unique<OpponentProjectile>(
              Opponent_[i]->GetX(), Opponent_[i]->GetY())));
    }
  }
}
void Game::FilterIntersections() {
  for (int i = 0; i < Opponent_.size(); i++) {
    if (Player_.IntersectsWith(GetOpponents().at(i).get()) == false) {
      Player_.SetIsActive(false);
      GetOpponents().at(i)->SetIsActive(false);
      WinOrLose_ = true;
    }
  }

  for (int i = 0; i < Opponent_.size(); i++) {
    for (int j = 0; j < PlayerProjectile_.size(); j++) {
      if (GetOpponents().at(i)->IntersectsWith(
              GetPlayerProjectiles().at(j).get()) == false) {
        GetOpponents().at(i)->SetIsActive(false);
        GetPlayerProjectiles().at(j)->SetIsActive(false);
        if (Player_.GetIsActive() == true) {
          score_++;
        }
      }
    }
  }

  for (int i = 0; i < OpponentProjectile_.size(); i++) {
    if (Player_.IntersectsWith(GetOpponentProjectiles().at(i).get()) == false) {
      GetPlayer().SetIsActive(false);
      GetOpponentProjectiles().at(i)->SetIsActive(false);
      WinOrLose_ = true;
    }
  }
}

void Game::OnAnimationStep() {
  if (GetOpponents().size() == 0) {
    CreateOpponents();
  }

  MoveGameElements();

  LaunchProjectiles();
  FilterIntersections();
  RemoveInactive();

  UpdateScreen();
  GameScreen_.Flush();
}

void Game::OnMouseEvent(const graphics::MouseEvent &mouse_event) {
  if ((mouse_event.GetMouseAction() == graphics::MouseAction::kMoved) ||
      (mouse_event.GetMouseAction() == graphics::MouseAction::kDragged)) {
    if (mouse_event.GetX() > GameScreen_.GetWidth() ||
        mouse_event.GetY() > GameScreen_.GetHeight() ||
        mouse_event.GetX() < 0 || mouse_event.GetY() < 0) {
      Player_.SetX(Player_.GetX());
      Player_.SetY(Player_.GetY());
    } else {
      Player_.SetX(mouse_event.GetX() - (Player_.GetWidth() / 2));
      Player_.SetY(mouse_event.GetY() - (Player_.GetHeight() / 2));
    }
  }

  if ((mouse_event.GetMouseAction() == graphics::MouseAction::kPressed) ||
      (mouse_event.GetMouseAction() == graphics::MouseAction::kDragged)) {
    std::unique_ptr<PlayerProjectile> proj;

    proj = std::make_unique<PlayerProjectile>(Player_.GetX(), Player_.GetY());

    PlayerProjectile_.push_back(std::move(proj));
  }
}

int Game::GetScore() { return score_; }

bool Game::HasLost() {
  if (WinOrLose_ == true) {
    return true;
  } else {
    return false;
  }
}

void Game::RemoveInactive() {
  for (int i = Opponent_.size() - 1; i >= 0; i--) {
    if (Opponent_.at(i)->GetIsActive() == false) {
      Opponent_.erase(Opponent_.begin() + i);
    }
  }

  for (int i = OpponentProjectile_.size() - 1; i >= 0; i--) {
    if (OpponentProjectile_.at(i)->GetIsActive() == false) {
      OpponentProjectile_.erase(OpponentProjectile_.begin() + i);
    }
  }

  for (int i = PlayerProjectile_.size() - 1; i >= 0; i--) {
    if (PlayerProjectile_.at(i)->GetIsActive() == false) {
      PlayerProjectile_.erase(PlayerProjectile_.begin() + i);
    }
  }
}
