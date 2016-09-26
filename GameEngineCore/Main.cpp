#include "src\include\Includes.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
#include "src\graphics\bg_Texture.h"

#include "src\objects\Inventory.h"

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
NOTES:

-Give the door class its own draw function
-Figure out which parts of code can be done in parallel
-Change the collision detection to read from black/white image outlines and check collisions
  with the image locations
-Fix the start screen matrix
*/

#if 1

int main(){
	//Width and height for the game window
	int width = 960;
	int height = 720;

	//Start Screen
	static Window start("Arorbis - Start", width, height);

	//OpenGl Coordinate Grid Setup
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, height, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	bg_Texture background(&start, "Resources/Images/BG.png", 0, 0, 960, 720, false);

	button b_start(&start, width / 2, height / 2, 50, 40, "Resources/Images/start.png");
	button b_exit(&start, width / 2, (height / 2) + 50, 50, 40, "Resources/Images/exit.png");
	bool exit = true;

	while (!start.closed()){
		start.clear();

		background.Draw();

		b_start.draw();
		b_exit.draw();

		if (b_start.clicked()){
			start.~Window();
			exit = false;
		}
		else if (b_exit.clicked()){
			start.~Window();
		}

		start.update();
	}
	//bullshit from George's anus
	
	if (exit == false){

		glViewport(0, 0, width, height);

		//Changing the in-game window's width and height to something more eye catching
		width = 960;
		height = 720;

		//Game Window
		static Window window("Arorbis - DEMO", width, height);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Game background color

		//OpenGL Coordinate Grid Setup
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0); //Sets coordinate system to start in 					
		glMatrixMode(GL_MODELVIEW);											//the middle of the screen like a standard graph
		glLoadIdentity();
		
		bg_Texture floor(&window, "Resources/Images/FloorTile1.png", -800, -600, 1600, 1200, true);

		// Construction
		Motion motion;
		PlayerObject player(&window, &motion, "Resources/Images/Multi-Layer.png", 37, 37);
		BG test(&window);
		test.loadFile("Resources/Levels/Wall.txt", "ENVIRONMENT");
		//test.loadFile("Resources/Levels/Doors.txt", "ENVIRONMENT");
		/*test.loadFile("Resources/Levels/Medics.txt", "ENTITY");
		test.loadFile("Resources/Levels/Enemy.txt", "ENTITY");
		test.loadFile("Resources/Levels/MeleeEnemy.txt", "ENTITY");*/
				
		while (!window.closed()){
			window.clear();

			checkForInput(&window, &motion, test); //Getting input values from the player in the current window


			floor.Draw();
			test.update(&motion, &player);
			player.Draw();

			window.update();
			Sleep(0.5); //Controls how fast the game loop runs at max
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