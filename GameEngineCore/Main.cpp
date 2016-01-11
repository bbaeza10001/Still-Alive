#include "src\include\Includes.h"
#include "src\objects\Bullet.h"
#include "src\objects\Wall.h"
#include "src\objects\BaseEnemy.h"
#include "src\graphics\lodepng.h"

#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace std;
using namespace level;
using namespace input;
using namespace motion;

/*
	TO DO IN CLUB:

	-Use the BG class to update any bullets fired by entities as well as the entities themselves
	-Use the BG class to check for bullet collisions among other entities
	-Add health aspect to all killable entities
	-Use health & bullet collisions together to make entities killable (Do in BG class)
	-Add the wall class to the BG 
	-Make temporary art assets for each thing
	-Make the enemy movements more random 

	TO DO:
	
	** Shooting System: 
		-Adjust to allow shooting while moving

	ISSUES:

	--COLLISION DETECTIONS--
		**If the direction is continually tapped after colliding, the player can move through an object

*/

#if 1
int main(){
	//Width and height for the game window
	int width = 800;
	int height = 600;

	//Start Screen
	static Window start("Still Alive - Start", width, height);

	//OpenGl Coordinate Grid Setup
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	button b_start(&start, 250, 400, 50, 40, "ship.png");
	button b_exit(&start, 550, 400, 50, 40, "ship.png");
	bool exit = true;

	while (!start.closed()){
		start.clear();

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

		//Game Window
		static Window window("Still Alive", width, height);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Game background color

		//OpenGL Coordinate Grid Setup
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0); //Sets coordinate system to start in 
		                                                                    //the middle of the screen like a standard graph
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		// Construction
		PlayerObject player(&window, "ship.png");
		BG test(&window);
		Motion motion;

		test.loadEntity("Enemy.txt", "BASE_ENEMY");

		//Music playing
		sf::Music music; //Music object setup
		music.openFromFile("music.ogg"); //Loading the music into memory
		music.play(); //Playing the music, plays in it's own thread

		while (!window.closed()){
			window.clear();

			checkForInput(&window, &motion, test); //Getting input values from the player in the current window
			
			test.update(&motion);

			player.Draw(&motion);

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
	int width = 800;
	int height = 600;

	//Game Window
	static Window window("Still Alive", width, height);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Game background color

	//OpenGL Coordinate Grid Setup
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0); //Sets coordinate system to start in 
	//the middle of the screen like a standard graph
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Construction
	PlayerObject player(&window, "ship.png");
	BG test(&window);
	Motion motion;

	test.loadEntity("Enemy.txt", "BASE_ENEMY");

	sf::Music music;
	music.openFromFile("music.ogg");
	music.play();

	while (!window.closed()){
		window.clear();

		checkForInput(&window, &motion, test); //Getting input values from the player in the current window

		test.update(&motion);

		player.Draw(&motion);

		window.update();
		Sleep(0.5); //Controls how fast the game loop runs at max
	}
}
#endif