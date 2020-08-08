# CPPND: Capstone Pong Game

This is a basic game of pong. The game supports two players on the same key board. The left paddle is controlled by the up and down arrow to move the paddle up and down. The right paddle is controlled by the w and s keys where w moves the paddle up and s moves the paddle down. The ball begins by move toward the left. If the ball hits the paddle, it is reflected and head towards the right and vice versa. If the ball leaves the screen, the player corresponding to the left or right side of the screen scores a point. The score is displayed at the top of the window. When the players exit

## Basic Structure
Paddle.cpp --> Stores the x, y coordinates, the dimensions, and the y velocity of a paddle. Contains helper functions to draw and update position of ball.

Ball.cpp --> Stores the x, y coordinates, the dimensions, and the x, y velocity of the ball. Contains helper functions to draw and update position of ball.

renderer.cpp --> Creates window and renders paddles, ball, and net to the screen.

controller.cpp --> Handles player input for each paddle.

game.cpp --> Contains game loop. Each loop it calls the handle input function from the controller object, updates the location of the paddles based on the input, and 
renders based on the updated coordinates of the paddle and ball. It also checks if there is a collision between the paddle and ball and resets the ball and updates the score when the ball leaves the screen.

main.cpp --> Runs the game.

## Rubric points
1. The project uses Object Oriented Programming techniques. See Ball.cpp, Paddle.cpp
2. Classes use appropriate access specifiers for class members. See Ball.cpp, Paddle.cpp
3. The project demonstrates an understanding of C++ functions and control structures. 
4. The project accepts user input and processes the input. See controller.cpp 
5. Class constructors utilize member initialization lists. See Game.cpp line 5
6. The project makes use of references in function declarations. See controller.cpp line 18
## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PongGame`.