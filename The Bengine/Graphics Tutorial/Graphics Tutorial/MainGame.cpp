//-------------------------------------------------------------------------------------------------
//	File: MainGame.cpp
//
//	Class: MainGame
//
//	Functions:
//	fatalError()
//	MainGame()
//	run()
//	initSystems()
//	gameLoop()
//	processInput()
//	drawGame()
//
//-------------------------------------------------------------------------------------------------
#include "MainGame.h"

//-------------------------------------------------------------------------------------------------
//	Function: fatalError()
//
//	Title: Fatal Error
//
//	Description: 
//	Displays the errors from various calls
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
//	Input: cin.get() -- user presses <Enter> to continue process (and thus exit)
//
//	Output: cout -- prints message to the console for user
//
//	Parameters:
//	std::string errorString -- The error message to be displayed
// 
//
//	Returns:
//	none
// 
// 
//	Called By: initSystems()
// 
//	Calls: none
//
//	History Log: 
//	8/18/14 - BA - Uploaded Tutorial to Youtube
//	8/25/15 - KM - Created inital structure of function
// 
//-------------------------------------------------------------------------------------------------
void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Press <Enter> to quit";
	std::cin.get();

	SDL_QUIT; //Turbs SDL off
	exit(1); //Forcibl exits the program

}

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
	if (_window == nullptr)
		fatalError("SDL Window could not be created!");

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr)
		fatalError("SDL_GL context could not be created!");

	GLenum error = glewInit();
	if (error != GLEW_OK)//Can be configured to check for any errors GLEW returns
		fatalError("Could not initialize GLEW");

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);//turns double buffering on

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);//Sets the "clear buffer" color. RGBA
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

		drawGame();
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

//-------------------------------------------------------------------------------------------------
//	Function: DrawGame
//
//	Title: Display Function
//
//	Description: 
//	Displays the buffered information to the screen
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
//		none
//
//	Output:
//		glBegin()-glEnd() -- Pushes informations from the buffers to the screen
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
//	8/26/15 - KM - Changed temporary tringle to account for "normalized device coordinates".
// 
//-------------------------------------------------------------------------------------------------
void MainGame::drawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Allows two variables to e used as one

#pragma region Bad Practices
	//What follows is 'Immediate OpenGL'.
	//It is advised to NEVER use this; it exists here only for teaching purposes.
	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1, -1);
	//In OpenGL, 0 is center of screen. Positive #s go go and right, negative go down and left
	glVertex2f(0, -1);
	glVertex2f(0, 0);

	glEnd();
#pragma endregion

	SDL_GL_SwapWindow(_window);//Pushes the buffer to the window
}