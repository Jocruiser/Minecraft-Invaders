#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H
#include <iostream>
#include <string>

#include "cpputils/graphics/image.h"

class GameElement {
 public:
  GameElement();
  GameElement(int x, int y, int width, int height);
  int x;
  int y;
  void SetX(int x_);
  void SetY(int y_);
  int GetX() const;
  int GetY() const;
  int GetWidth();
  int GetHeight();
  // changed draw funct into virtual, set equal to 0
  virtual void Draw(graphics::Image& my_image) = 0;

  // create a pure virtual funct
  virtual void Move(const graphics::Image& my_image) = 0;

  // added setter and getter for priv variable IsActive
  void SetIsActive(bool active);
  bool GetIsActive() const;

  // added intersects member function
  bool IntersectsWith(GameElement* game_element);
  bool IsOutOfBounds(const graphics::Image& my_image);

 protected:
  int x_;  // data members for all player and opp
  int y_;
  int width_;
  int height_;
  bool Active_ = true;
};
#endif
