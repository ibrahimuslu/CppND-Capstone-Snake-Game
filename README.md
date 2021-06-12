# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Game Extensions 
1. Classic snake game extended with 2 other objects other than "Food": "Trap" and "Wall".
2. When you hit the "Trap", you will loose one score and the body will shrink one unit. 
3. When you hit the "Wall", you will loose all scores and snake will die and Game will over. 
4. "Space" key will pause the game and make run after pause.
5. When the game over you can continue by pressing "Space" key.
6. "Esc" key will close the window and finish the game. 
7. Games will be logged into "gameLog.txt" in the same level directory of the game started. 
8. There is two level of difficulty "easy" and "hard". 
9. You can start the game with command line argument as the following
```
./SnakeGame hard
```
9. "easy" is the default difficulty and has 8 foods and 1 trap and 1 wall
10. "hard" has 1 food 8 traps and 4 walls


## Project Criteria

### Loops, Functions, I/O
| _Criteria_ | _Comments_ | 
|---------|-----------|
| The project demonstrates an understanding of C++ functions and control structures. | The title changes according to the state of the game and the update of the game according to the objects hit are done in functions of the objects |
| The project reads data from a file and process the data, or the program writes data to a file.	| Program logs the game results and duration to the gameLog.txt file  |
| The project accepts user input and processes the input.	|  The difficulty set via the command line arguments.  |

## Object Oriented Programming

| _Criteria_ | _Comments_ | 
|---------|-----------|
| The project uses Object Oriented Programming techniques.| The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks. | 
| Classes use appropriate access specifiers for class members. | All class data members are explicitly specified as public, protected, or private. |
| Classes abstract implementation details from their interfaces. | The Food, Wall, and Trap objects are derived from the Object abstract class|
| Classes follow an appropriate inheritance hierarchy. | Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified. |
| Derived class functions override virtual base class functions.| Objects derived from abstract classes virtual functions |  

## Memory Management

| _Criteria_ | _Comments_ | 
|---------|-----------|
| The project makes use of references in function declarations. | At least two variables are defined as references, or two functions use pass-by-reference in the project code. |
| The project uses destructors appropriately. | At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor. |
| The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | All the derived objects meet the rule of five and RAII |
| The project follows the Rule of 5. | All the derived objects meet the rule of five and RAII | 
| The project uses smart pointers instead of raw pointers. | The Objects are used with unique pointer in the Game | 

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
