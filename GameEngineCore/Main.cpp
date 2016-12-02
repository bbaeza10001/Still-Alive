#include "src\include\Includes.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include "src\graphics\bg_Texture.h"

#include "src\objects\Inventory.h"

#include <stdlib.h>

#include <thread>

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace std;
using namespace level;
using namespace input;
using namespace motion;

using namespace GUI;

/*
TO DO:


*/

#if 1
int main(){
	//Width and height for the game window
	int width = 960;
	int height = 720;

	//Start Screen Creation
	static Window start("Untitled Game :( - Start", width, height);

	//OpenGl Coordinate Grid Setup (Start Screen Coordinate Setup)
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, height, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Setting the background image
	bg_Texture background(&start, "Resources/Images/start_screen.png", 0, 0, 960, 720, false);

	//Creating buttons for the start screen
	button b_start(&start, 900, 135, 220, 120, "Resources/Images/empty_button.png");
	button b_exit(&start, (width / 2) + 20, (height / 2) + 60, 50, 40, "Resources/Images/empty_button.png");
	bool exit = true; //This value keeps track of if the player wants the exit the program

	//While loop for events happening in the start screen
	while (!start.closed()){
		//Clear all drawn images
		start.clear(); 

		//Draw the background first
		background.Draw(); 

		//Draw the buttons over the background
		b_start.draw();
		b_exit.draw();

		//Check if the start or exit button were clicked by checking the return value of their "clicked" function
		if (b_start.clicked()){
			start.~Window();
			exit = false;
		}
		else if (b_exit.clicked()){
			start.~Window();
		}

		//Update the start screen to display all of the image changes
		start.update();
	}
	//bullshit from George's anus <-----Curtosey of Evan 
	
	if (exit == false){ //If the player does NOT want to quit the game

		//Resetting the viewport for the main game
		glViewport(0, 0, width, height); 

		//Changing the in-game window's width and height to something more eye catching
		width = 960;
		height = 720;

		//Game Window Creation
		static Window window("Untitled Game :( - DEMO", width, height);
		//Level background color
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 

		//OpenGL Coordinate Grid Setup (Game Screen Coordinate Setup)
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0); //Sets coordinate system to start in 					
		glMatrixMode(GL_MODELVIEW);											//the middle of the screen like a standard graph
		glLoadIdentity();
		
		//Background (or floor) image setup
		bg_Texture floor(&window, "Resources/Images/FloorTile1.png", -800, -600, 1600, 1200, true);

		//Object (class) initialization (set-up) for objects we will need during runtime
		
		Motion motion; //Keeps track of all moving objects: speed, roations, etc
		PlayerObject player(&window, &motion, "Resources/Images/Multi-Layer.png", 37, 37); //Player instance, handles input
		BG test(&window); //BG (background) object, contains all in game objects: Walls, enemies, collision detection, etc
		
		//File loading for level setup
		test.loadFile("Resources/Levels/Wall.txt", "ENVIRONMENT");
		//test.loadFile("Resources/Levels/Doors.txt", "ENVIRONMENT");
		/*test.loadFile("Resources/Levels/Medics.txt", "ENTITY");
		test.loadFile("Resources/Levels/Enemy.txt", "ENTITY");
		test.loadFile("Resources/Levels/MeleeEnemy.txt", "ENTITY");*/
				
		//Main game loop
		while (!window.closed()){
			window.clear(); //Clear the screen

			//Get input values from the player in the current window
			checkForInput(&window, &motion, test); 
			
			floor.Draw(); //Draw the floor first
			test.update(&motion, &player); //Update (and draw) all in game objects
			player.Draw(); //Draw the player on the very top so it is always visible

			window.update(); //Update the window to display all new changes
			Sleep(0.5); //Controls how fast the game loop runs at max, ignore this line
		}

	}
	return 0;
}
#endif

/*This alternate main function can be activated to test specific items that 
would otherwise be too messy to test in the main game version. To activate this 
instead of the game's main function, change the 0 after #if to 1, then change the #if 1 
above the original main function to #if 0 (This part is above this current text, almost at the top of the page)*/
#if 0
int main(){
	int width = 1920;
	int height = 1080;

	//Game Window
	static Window window("Still Alive", width, height);

	//OpenGL Coordinate Grid Setup
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0); //Sets coordinate system to start in 					
	glMatrixMode(GL_MODELVIEW);											//the middle of the screen like a standard graph
	glLoadIdentity();

	// Construction
	Motion motion;
	PlayerObject player(&window, &motion, "Multi-Layer.png", 37, 37);
	BG test(&window);
	test.loadEntity("Wall.txt", "WALL");
	test.loadEntity("Enemy.txt", "BASE_ENEMY");
	test.loadEntity("Medics.txt", "BASE_MEDIC");
	test.loadEntity("MeleeEnemy.txt", "MELEE_ENEMY");
	test.loadEntity("Doors.txt", "DOOR");

	while (!window.closed()){
		window.clear();

		checkForInput(&window, &motion, test); //Getting input values from the player in the current window

		test.update(&motion, &player);

		player.Draw();

		window.update();
		Sleep(0.5); //Controls how fast the game loop runs at max
	}
}
#endif
