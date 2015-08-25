//-------------------------------------------------------------------------------------------------
//	File: main.cpp
//
//	Functions:
//	main
//
//-------------------------------------------------------------------------------------------------
#include <SDL/SDL.h>

//-------------------------------------------------------------------------------------------------
//	Function: main()
//
//	Title: main function
//
//	Description: 
//	Opens the SDL Window
//
//	Programmer(s):
//	Kevin Manning
//	(Based on Tutorial Series by Ben Arnold - https://www.youtube.com/user/makinggameswithben/)
//
//	Date: 8/24/2015
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
//	Output: SDL Window
//
//	Parameters:
//	int argc -- the number of arguments being passed into the function
//  char *argv[] -- the arguments (in c-string format) being passed into the function
// 
//
//	Returns:
//	0 at completion of program
// 
// 
//	Called By: none
// 
//	Calls: none
//
//	History Log: 
//	8/12/14 - BA - Uploaded Tutorial to Youtube
//	8/24/15 - KM - Created inital structure of program
//	8/25/15 - KM - Added comment headers
// 
//-------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);

	return 0;
};