//-------------------------------------------------------------------------------------------------
//	File: MainGame.cpp
//
//	Class: MainGame
//
//	Functions:
//	MainGame()
//	run()
//	initSystems()
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
//	Calls: initSystems()
//
//	History Log: 
//	8/18/14 - BA - Uploaded Tutorial to Youtube
//	8/25/15 - KM - Created inital structure of function
// 
//-------------------------------------------------------------------------------------------------
void MainGame::run()
{
	initSystems();
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