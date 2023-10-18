#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"

class Player : public GameElement {
 public:
  Player();
  Player(int x, int y);
  void Draw(graphics::Image& my_image) override;
  void Move(const graphics::Image& my_image) override;
};

class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile();
  PlayerProjectile(int x, int y);
  void Draw(graphics::Image& my_image) override;
  // bool IntersectsWith(Opponent& opponent);
  void Move(const graphics::Image& my_image) override;
};
#endif
