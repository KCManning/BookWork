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
#include <string>

#include <iostream>//*** Included during testing.

enum class GameState
{PLAY,EXIT};

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
// 
//		  Private Methods:
//		   void initSystems() -- initializes the different functions required for operation
//			void gameLoop() -- Main loop for calling and using game logic
//			void processInput() -- Handles user interaction with window
//
//        Private Properties
//          SDL_Window* _window -- handle for the SDL Window
//			int _screenWidth -- Width of window to be created
//			int _screenHeight -- Height of window to be created
//			GameState _gamestate -- Used to determine if game is running or not
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
	//Constructors
	MainGame();

	~MainGame();
	
	//Methods
	void run();

private:
	//Methods
	void initSystems();
	void gameLoop();
	void processInput();

	void drawGame();

	//Properties
	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gamestate;
};

