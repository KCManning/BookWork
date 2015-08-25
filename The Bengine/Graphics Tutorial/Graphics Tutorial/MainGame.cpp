//-------------------------------------------------------------------------------------------------
//	File: MainGame.cpp
//
//	Class: MainGame
//
//	Functions:
//	MainGame()
//	run()
//	initSystems()
//	gameLoop()
//	processInput()
//-------------------------------------------------------------------------------------------------
#include "MainGame.h"

//-------------------------------------------------------------------------------------------------
//	Function: MainGame()
//
//	Title: Default Constuctor
//
//	Description: 
//	fill the MainGame object with data and sets pointers to null
//
//	Programmer(s):
//	Kevin Manning
//	(Based on Tutorial Series by Ben Arnold - https://www.youtube.com/user/makinggameswithben/)
//
//	Date: 8/25/2015
//
//	Version: 0.01
//
//	Testing Environment: 
//		Hardware: Lenovo y50
//
//		Software: Windows 8.1
//		Visual Studio 2015 Community Edition
//
//	Input: none
//
//	Output: none
//
//	Parameters:
//	none
// 
//
//	Returns:
//	none
// 
// 
//	Called By: main()
// 
//	Calls: none
//
//	History Log: 
//	8/18/14 - BA - Uploaded Tutorial to Youtube
//	8/25/15 - KM - Created inital structure of function
// 
//-------------------------------------------------------------------------------------------------
MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gamestate = GameState::PLAY;
}

//-------------------------------------------------------------------------------------------------
//	Function: ~MainGame()
//
//	Title: Default Deconstuctor
//
//	Description: 
//	Frees the memory used by MainGame object
//
//	Programmer(s):
//	Kevin Manning
//	(Based on Tutorial Series by Ben Arnold - https://www.youtube.com/user/makinggameswithben/)
//
//	Date: 8/25/2015
//
//	Version: 0.01
//
//	Testing Environment: 
//		Hardware: Lenovo y50
//
//		Software: Windows 8.1
//		Visual Studio 2015 Community Edition
//
//	Input: none
//
//	Output: none
//
//	Parameters:
//	none
// 
//
//	Returns:
//	none
// 
// 
//	Called By: none
// 
//	Calls: none
//
//	History Log: 
//	8/18/14 - BA - Uploaded Tutorial to Youtube
//	8/25/15 - KM - Created inital structure of function
// 
//-------------------------------------------------------------------------------------------------
MainGame::~MainGame()
{
}

//-------------------------------------------------------------------------------------------------
//	Function: run()
//
//	Title: Run
//
//	Description: 
//	Calls components required to run gam
//
//	Programmer(s):
//	Kevin Manning
//	(Based on Tutorial Series by Ben Arnold - https://www.youtube.com/user/makinggameswithben/)
//
//	Date: 8/25/2015
//
//	Version: 0.01
//
//	Testing Environment: 
//		Hardware: Lenovo y50
//
//		Software: Windows 8.1
//		Visual Studio 2015 Community Edition
//
//	Input: none
//
//	Output: none
//
//	Parameters:
//	none
// 
//
//	Returns:
//	none
// 
// 
//	Called By: main()
// 
//	Calls:
//		initSystems()
//		gameLoop()
//
//	History Log: 
//	8/18/14 - BA - Uploaded Tutorial to Youtube
//	8/25/15 - KM - Created inital structure of function
// 
//-------------------------------------------------------------------------------------------------
void MainGame::run()
{
	initSystems();

	gameLoop();
}

//-------------------------------------------------------------------------------------------------
//	Function: initSystem
//
//	Title: System Initalizer
//
//	Description: 
//	Initializes SDL and Window creation paramters.
//
//	Programmer(s):
//	Kevin Manning
//	(Based on Tutorial Series by Ben Arnold - https://www.youtube.com/user/makinggameswithben/)
//
//	Date: 8/25/2015
//
//	Version: 0.01
//
//	Testing Environment: 
//		Hardware: Lenovo y50
//
//		Software: Windows 8.1
//		Visual Studio 2015 Community Edition
//
//	Input: none
//
//	Output: none
//
//	Parameters:
//	none
// 
//
//	Returns:
//	none
// 
// 
//	Called By: run()
// 
//	Calls: none
//
//	History Log: 
//	8/18/14 - BA - Uploaded Tutorial to Youtube
//	8/25/15 - KM - Created inital structure of function
// 
//-------------------------------------------------------------------------------------------------
void MainGame::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);//initialize SDL

	_window = SDL_CreateWindow("Bengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
}

//-------------------------------------------------------------------------------------------------
//	Function: gameLoop
//
//	Title: Primary Game Loop
//
//	Description: 
//	Handles game logic so long as game is running
//
//	Programmer(s):
//	Kevin Manning
//	(Based on Tutorial Series by Ben Arnold - https://www.youtube.com/user/makinggameswithben/)
//
//	Date: 8/25/2015
//
//	Version: 0.01
//
//	Testing Environment: 
//		Hardware: Lenovo y50
//
//		Software: Windows 8.1
//		Visual Studio 2015 Community Edition
//
//	Input: none
//
//	Output: none
//
//	Parameters:
//	none
// 
//
//	Returns:
//	none
// 
// 
//	Called By: run()
// 
//	Calls:
//		processInput()
//
//	History Log: 
//	8/22/14 - BA - Uploaded Tutorial to Youtube
//	8/25/15 - KM - Created inital structure of function
// 
//-------------------------------------------------------------------------------------------------
void MainGame::gameLoop()
{
	while (_gamestate != GameState::EXIT)
	{
		processInput();
	}
}

//-------------------------------------------------------------------------------------------------
//	Function: processInput
//
//	Title: Event Handling
//
//	Description: 
//	Accepts user input and processes it into useable commands by the program
//
//	Programmer(s):
//	Kevin Manning
//	(Based on Tutorial Series by Ben Arnold - https://www.youtube.com/user/makinggameswithben/)
//
//	Date: 8/25/2015
//
//	Version: 0.01
//
//	Testing Environment: 
//		Hardware: Lenovo y50
//
//		Software: Windows 8.1
//		Visual Studio 2015 Community Edition
//
//	Input:
//		User Commands:
//			SDL_QUIT -- The user elects to press the "X" to close the program
//			SDL_MOUSEMOTION -- Tracks the movement of the user's mouse
//
//	Output:
//		(during testing) cout -- displays commands to user console
//
//	Parameters:
//	none
// 
//
//	Returns:
//	none
// 
// 
//	Called By: gameLoop()
// 
//	Calls:
//
//
//	History Log: 
//	8/22/14 - BA - Uploaded Tutorial to Youtube
//	8/25/15 - KM - Created inital structure of function
// 
//-------------------------------------------------------------------------------------------------
void MainGame::processInput()
{
	SDL_Event evnt;//Creates the event handler. Terrible name :-(

	while (SDL_PollEvent(&evnt))//Verifies an event has occurred
	{
		switch (evnt.type)//Uses the enum'd event to determine the next step
		{
		case SDL_QUIT:
			_gamestate = GameState::EXIT;
			break;

		case SDL_MOUSEMOTION:
			std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
			break;

		}
	}
}