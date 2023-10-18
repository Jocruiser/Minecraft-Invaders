#include <iostream>
#include <string>

#include "cpputils/graphics/image.h"
#include "game_element.h"

#ifndef OPPONENT_H
#define OPPONENT_H

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile();
  OpponentProjectile(int x, int y);

  void Draw(graphics::Image& my_image) override;
  void Move(const graphics::Image& my_image) override;
};

class Opponent : public GameElement {
 private:
  int counter;

 public:
  Opponent();
  Opponent(int x, int y);

  void Draw(graphics::Image& my_image) override;
  void Move(const graphics::Image& my_image) override;
  std::unique_ptr<OpponentProjectile> LaunchProjectile();
};

#endif
