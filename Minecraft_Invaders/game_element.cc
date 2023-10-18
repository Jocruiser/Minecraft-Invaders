#include "game_element.h"

#include <iostream>

#include "cpputils/graphics/image.h"

GameElement::GameElement() {
  this->x_ = 0;
  this->y_ = 0;
  this->width_ = 50;
  this->height_ = 50;
  this->Active_ = true;
}
GameElement::GameElement(int x, int y, int width, int height) {
  this->x_ = x;
  this->y_ = y;
  this->width_ = width;
  this->height_ = height;
}

void GameElement::SetX(int x) { this->x_ = x; }
void GameElement::SetY(int y) { this->y_ = y; }
int GameElement::GetX() const { return x_; }
int GameElement::GetY() const { return y_; }

void GameElement::SetIsActive(bool active) { this->Active_ = active; }
bool GameElement::GetIsActive() const { return Active_; }

int GameElement::GetWidth() { return width_; }
int GameElement::GetHeight() { return height_; }

bool GameElement::IntersectsWith(GameElement* game_element) {
  return !(GetX() > game_element->GetX() + game_element->GetWidth() ||
           game_element->GetX() > GetX() + GetWidth() ||
           GetY() > game_element->GetY() + game_element->GetHeight() ||
           game_element->GetY() > GetY() + GetHeight());
}

bool GameElement::IsOutOfBounds(const graphics::Image& my_image) {
  if (GetX() + GetWidth() > my_image.GetWidth() ||
      GetY() + GetHeight() > my_image.GetHeight() || GetX() < 0 || GetY() < 0) {
    return true;
  } else {
    return false;
  }
}
