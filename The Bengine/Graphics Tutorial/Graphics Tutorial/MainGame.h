//-------------------------------------------------------------------------------------------------
//	File: MainGame.h
//
//	Class: MainGame
//
//	Functions:
//	MainGame()
//	~MainGame()
//	run()
//	initSystems()
//-------------------------------------------------------------------------------------------------
#pragma once

#include <Windows.h>
#include <SDL/SDL.h>
#include <GLEW/glew.h>

//-------------------------------------------------------------------------------------------------
//   Title: Main Game Class
//   Description: The base class for the core portions of the game
//
//   Programmer(s): 
//	 Kevin Manning
//	 (Based on Tutorial Series by Ben Arnold - https://www.youtube.com/user/makinggameswithben/)
// 
//   Date: 8/25/2015
//   Version: 0.01
//
//	Testing Environment: 
//		Hardware: Lenovo y50
//
//		Software: Windows 8.1
//		Visual Studio 2015 Community Edition
//
//   class list:
//
//     Properties:
//       none
//
//     Methods:
//       inline: 
//         ~MainGame() -- destructor
//
//       non-inline:
//         MainGame() -- constructs the base game window
//		   void run() -- calls each of the necessary functions to run the game
//		   void initSystems() -- initializes the different functions required for operation
// 
//        Private Properties
//          SDL_Window* _window -- handle for the SDL Window
//			int _screenWidth -- Width of window to be created
//			int _screenHeight -- Height of window to be created
//
//    Public Nested Structures:
//      none
//
//        properties:
//          n/a
//        constructor:
//          n/a
//
//
//  History Log:
//	8/18/14 - BA - Uploaded Tutorial to Youtube
//	8/25/15 - KM - Created inital structure of class
//-------------------------------------------------------------------------------------------------
class MainGame
{
public:
	MainGame();
	~MainGame();


	void run();

	void initSystems();

private:
	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
};

