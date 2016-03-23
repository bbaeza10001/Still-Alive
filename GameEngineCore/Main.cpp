#include "src\include\Includes.h"
<<<<<<< HEAD
#include "src\objects\Bullet.h"
#include "src\objects\Wall.h"
#include "src\objects\BaseEnemy.h"
#include "src\graphics\lodepng.h"
#include "src\objects\BaseMedic.h"
=======
>>>>>>> master
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

	-Create a basic medic character
	-Give all enemy types a logical basic AI

	TO DO:
	
	**Fix image jitter when moving diagonally

	ISSUES:

	--COLLISION DETECTIONS--
		**If the direction is continually tapped after colliding, the player can move through an object

*/

#if 0
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
		BaseMedic casual(-100, -100, "ship.png");
		BaseEnemy josh(-10, 10, "ship.png");

	//	test.loadEntity("Enemy.txt", "BASE_ENEMY");
		test.loadEntity("Wall.txt", "WALL");

		//Music playing
		sf::Music music; //Music object setup
		music.openFromFile("music.ogg"); //Loading the music into memory
		music.setLoop(true);
		//music.play(); //Playing the music, plays in it's own thread

		while (!window.closed()){
			window.clear();

			checkForInput(&window, &motion, test); //Getting input values from the player in the current window
			
			test.update(&motion, &player);
			josh.Draw(&motion);
			player.Draw(&motion);
			casual.Draw(&motion);
			casual.Heal(josh);

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
#if 1
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
	PlayerObject player(&window, "Multi-Layer.png", 37, 37);
	BG test(&window);
	Motion motion;
	test.loadEntity("Wall.txt", "WALL");
	test.loadEntity("Enemy.txt", "BASE_ENEMY");
	test.loadEntity("MeleeEnemy.txt", "MELEE_ENEMY");
	test.loadEntity("Doors.txt", "DOOR");

	/*sf::Music music;
	music.openFromFile("music.ogg");
	music.play();*/

	while (!window.closed()){
		window.clear();

		checkForInput(&window, &motion, test); //Getting input values from the player in the current window

		test.update(&motion, &player);
		player.Draw(&motion);

		window.update();
		Sleep(0.5); //Controls how fast the game loop runs at max
	}
}
#endif