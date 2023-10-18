#include "opponent.h"

#include <iostream>
#include <vector>

#include "cpputils/graphics/image.h"
#include "game_element.h"

Opponent::Opponent() : Opponent(0, 0) {}
Opponent::Opponent(int x, int y) : GameElement(x, y, 50, 50) {}

void Opponent::Draw(graphics::Image& my_image) {
  // set dimensions for opponent
  graphics::Image opponent(50, 50);
  // graphics::Image gameboard(800, 600);
  opponent.Load("opponent.bmp");
  for (int x = 0; x < opponent.GetWidth(); x++) {
    for (int y = 0; y < opponent.GetHeight(); y++) {
      graphics::Color c = opponent.GetColor(x, y);
      const int nx = (this->GetX() + x) % my_image.GetWidth();
      const int ny = (this->GetY() + y) % my_image.GetHeight();

      my_image.SetColor(nx, ny, c);
    }
  }
}

void Opponent::Move(const graphics::Image& my_image) {
  if (!IsOutOfBounds(my_image)) {
    SetY(GetY() + 3);
    SetX(GetX() + 3);
  } else {
    SetIsActive(false);
  }
}

std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() {
  counter++;
  if (counter % 10) {
    return nullptr;
  } else {
    return std::make_unique<OpponentProjectile>(Opponent::GetX(),
                                                Opponent::GetY());
  }
}

///////////// CLASS 2 ///////////////
OpponentProjectile::OpponentProjectile() : OpponentProjectile(0, 0) {}
OpponentProjectile::OpponentProjectile(int x, int y)
    : GameElement(x, y, 5, 5) {}

void OpponentProjectile::Draw(graphics::Image& my_image) {
  // set dimensions for opponent projectile
  graphics::Image op_projectile(5, 5);
  op_projectile.Load("o_projectile.bmp");

  // drawing for opponent proj
  // op_projectile.DrawRectangle(0, 0, 5, 5, 255, 0, 0);
  for (int x = 0; x < op_projectile.GetWidth(); x++) {
    for (int y = 0; y < op_projectile.GetHeight(); y++) {
      graphics::Color c = op_projectile.GetColor(x, y);
      const int nx = (this->GetX() + x) % my_image.GetWidth();
      const int ny = (this->GetY() + y) % my_image.GetHeight();

      my_image.SetColor(nx, ny, c);
    }
  }
}

void OpponentProjectile::Move(const graphics::Image& my_image) {
  if (!IsOutOfBounds(my_image)) {
    SetY(GetY() + 3);
  } else {
    SetIsActive(false);
  }
}
