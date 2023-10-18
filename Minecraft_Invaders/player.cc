#include "player.h"

#include <iostream>
#include <vector>

#include "cpputils/graphics/image.h"
#include "game_element.h"

Player::Player() {}
Player::Player(int x, int y) : GameElement::GameElement(x, y, 50, 50) {}

void Player::Draw(graphics::Image& my_image) {
  graphics::Image player;
  player.Load("player.bmp");

  for (int x = 0; x < player.GetWidth(); x++) {
    for (int y = 0; y < player.GetHeight(); y++) {
      graphics::Color c = player.GetColor(x, y);
      const int nx = (this->GetX() + x) % my_image.GetWidth();
      const int ny = (this->GetY() + y) % my_image.GetHeight();

      my_image.SetColor(nx, ny, c);
    }
  }
}
/* removed based from README
bool Player::IntersectsWith(Opponent& opponent) {
  return !(GetX() > opponent.GetX() + opponent.GetWidth() ||
           opponent.GetX() > GetX() + GetWidth() ||
           GetY() > opponent.GetY() + opponent.GetHeight() ||
           opponent.GetY() > GetY() + GetHeight());
}

bool Player::IntersectsWith(OpponentProjectile& projectile) {
  return !(GetX() > projectile.GetX() + projectile.GetWidth() ||
           projectile.GetX() > GetX() + GetWidth() ||
           GetY() > projectile.GetY() + projectile.GetHeight() ||
           projectile.GetY() > GetY() + GetHeight());
}
*/

// keep empty, per read me
void Player::Move(const graphics::Image& my_image) {}

PlayerProjectile::PlayerProjectile() {}
PlayerProjectile::PlayerProjectile(int x, int y)
    : GameElement::GameElement(x, y, 5, 5) {}

void PlayerProjectile::Draw(graphics::Image& my_image) {
  graphics::Image p_projectile;
  p_projectile.Load("p_projectile.bmp");
  // p_projectile.DrawRectangle(0, 0, 5, 5, 0, 0, 255);
  for (int x = 0; x < p_projectile.GetWidth(); x++) {
    for (int y = 0; y < p_projectile.GetHeight(); y++) {
      graphics::Color c = p_projectile.GetColor(x, y);
      const int nx = (this->GetX() + x) % my_image.GetWidth();
      const int ny = (this->GetY() + y) % my_image.GetHeight();

      my_image.SetColor(nx, ny, c);
    }
  }
}
/*
bool PlayerProjectile::IntersectsWith(Opponent& opponent) {
  return !(GetX() > opponent.GetX() + opponent.GetWidth() ||
           opponent.GetX() > GetX() + GetWidth() ||
           GetY() > opponent.GetY() + opponent.GetHeight() ||
           opponent.GetY() > GetY() + GetHeight());
}
*/

// implemented from game element virtual public funct
void PlayerProjectile::Move(const graphics::Image& my_image) {
  if (!IsOutOfBounds(my_image)) {
    SetY(GetY() - 3);
  } else {
    SetIsActive(false);
  }
}
