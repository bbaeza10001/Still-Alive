#include "src\include\Includes.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>

#include "src\Items\BaseItem.h"
#include "src\graphics\bg_Texture.h"

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace std;
using namespace level;
using namespace input;
using namespace motion;

using namespace items;

#if 1
int main(){
	//Width and height for the game window
	int width = 800;
	int height = 600;

	//Start Screen
	static Window start("A World... - Start", width, height);

	//OpenGl Coordinate Grid Setup
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	bg_Texture background(&start, "Resources/Images/BG.png");

	button b_start(&start, 400, 350, 50, 40, "Resources/Images/start.png");
	button b_exit(&start, 400, 400, 50, 40, "Resources/Images/exit.png");
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
	
	if (exit == false){

		//Changing the in-game window's width and height to something more eye catching
		width = 1920;
		height = 1080;

		//Game Window
		static Window window("A World...", width, height);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Game background color

		//OpenGL Coordinate Grid Setup
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0); //Sets coordinate system to start in 					
		glMatrixMode(GL_MODELVIEW);											//the middle of the screen like a standard graph
		glLoadIdentity();
		
		// Construction
		Motion motion;
		PlayerObject player(&window, &motion, "Resources/Images/Multi-Layer.png", 37, 37);
		BG test(&window);
		test.loadEntity("Resources/Levels/Wall.txt", "WALL");
		test.loadEntity("Resources/Levels/Doors.txt", "DOOR");
		test.loadEntity("Resources/Levels/Medics.txt", "BASE_MEDIC");
		test.loadEntity("Resources/Levels/Enemy.txt", "BASE_ENEMY");
		test.loadEntity("Resources/Levels/MeleeEnemy.txt", "MELEE_ENEMY");

		while (!window.closed()){
			window.clear();

			checkForInput(&window, &motion, test); //Getting input values from the player in the current window

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