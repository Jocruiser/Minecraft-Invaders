#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>

#include "opponent.h"
#include "player.h"
// added in Game class but need to fix protected values
#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"

class Game : public graphics::MouseEventListener,
             public graphics::AnimationEventListener {
 private:
  graphics::Image background_;
  Player player_;
  std::vector<std::unique_ptr<PlayerProjectile>> player_projectiles_;
  std::vector<std::unique_ptr<Opponent>> opponents_;
  std::vector<std::unique_ptr<OpponentProjectile>> opponent_projectiles_;
  int width_;
  int height_;
  bool lost_ = false;
  int score_ = 0;

 public:
  Game();
  Game(int width, int height);

  graphics::Image& GetGameScreen();
  Player& GetPlayer();

  std::vector<std::unique_ptr<Opponent>>& GetOpponents();
  std::vector<std::unique_ptr<PlayerProjectile>>& GetPlayerProjectiles();
  std::vector<std::unique_ptr<OpponentProjectile>>& GetOpponentProjectiles();

  void LaunchProjectiles();
  void CreateOpponents();
  // void CreateOpponentProjectiles();
  // void CreatePlayerProjectiles();
  void Init();
  void UpdateScreen();
  void RemoveInactive();
  void Start();
  void MoveGameElements();
  void FilterIntersections();

  void OnAnimationStep() override;
  void OnMouseEvent(const graphics::MouseEvent& event) override;

  int GetScore() const;
  bool HasLost();
};
#endif
