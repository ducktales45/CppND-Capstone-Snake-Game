#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "paddle.h"

class Controller {
 public:
  void HandleInput(bool &running, Paddle &paddle1, Paddle &Paddle2) const;

 private:
  void ChangeDirection(Paddle &paddle, Paddle::Direction input) const;
};

#endif