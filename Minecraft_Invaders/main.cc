#include <iostream>
#include <memory>
#include <string>

#include "cpputils/graphics/image.h"
#include "game.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"

using graphics::Image;
using std::endl;

int main() {
  graphics::Image background_;
  background_.Initialize(800, 600);
  Game Game1;
  Game1.Init();
  Game1.UpdateScreen();
  Game1.Start();
}
