#include "src\include\Includes.h"
#include "src\graphics\Texture.h"
#include "src\objects\Bullet.h"
#include "src\motion\CollisionDetection.h"
#include "src\objects\Wall.h"
#include "src\objects\BaseEnemy.h"
#include "src\graphics\lodepng.h"

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace std;
using namespace level;
using namespace input;
using namespace motion;

/*
	TO DO:
	
	** Shooting System: 
		-Adjust to allow shooting while moving
		-Adjust to allow diagonal shooting

	** Begin a sound engine

	** Add param to text doc to set object images
	
	** Add background photos

	ISSUES:

	--COLLISION DETECTIONS--
		**If the direction is continually tapped after colliding, the player can move through an object
		**Change colCode variables to size 2 arrays to support multi-directional movement?
	--BULLET SYSTEM--
		**Add diagonal shooting
	--USER INPUT SYSTEM--
		**Change from two seperate variables for x and y to a single, size 2 array

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
		PlayerObject player(&window);
		vector<CircleObject> testC = loadPlanets(testC, "Circles.txt"); //Loading in the planets from the "level.txt" file
		vector<Wall> testW = loadPlanets(testW, "Walls.txt"); //Play around with the numbers in the files, see what it does :)
		BaseEnemy dave(50, 50);

		int input[2], colCode, WColCode = 0, CColCode = 0; //Ints having to do with collision detection

		while (!window.closed()){
			window.clear();

			input[0] = checkForXInput(&window); //Getting input values from the player in the current window
			input[1] = checkForYInput(&window);

			if ((input[0] != WColCode || input[1] != WColCode) && input[0] != 0 && input[1] != 0){ //Player input != the last collision code
			
				WColCode = 0; //There is no longer a collision
			}
			if ((input[0] != CColCode || input[1] != CColCode) && input[0] != 0 && input[1] != 0){ //Player input != the last collision code

				CColCode = 0; //There is no longer a collision
			}
			
			// Update Background
			for (unsigned int i = 0; i < testC.size(); i++){
				testC[i].Draw(input[0], input[1], CColCode);
			}

			dave.draw(input[0], input[1], 0);

			/*for (unsigned int i = 0; i < testW.size(); i++){
				testW[i].draw(input[0], input[1], WColCode);
			}*/

			//Update the player
			if (CColCode != 0 || WColCode != 0){
				if (WColCode != 0){
					player.Draw(input[0], input[1], WColCode);
				}
				player.Draw(input[0], input[1], CColCode);
			}

			WColCode = 0; //checkCollision(testW, input[0], input[1]); //Reset the collision code
			CColCode = checkCollision(testC, input[0], input[1]);

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

	//Start Screen
	static Window start("Still Alive - Start", width, height);

	//OpenGL Coordinates Setup
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width * 2, height * 2, 0); //Adjusts coordinate system to start from top left
	                                         //and be the correct width and height
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	button b_start(&start, 250, 400, 50, 40, "ship.png");
	button b_exit(&start, 550, 400, 50, 40, "ship.png");
	bool exit = false;

	while (!start.closed()){
	start.clear();

	b_start.draw();
	b_exit.draw();
	if (b_start.clicked()){
	start.~Window();
	}
	else if (b_exit.clicked()){
	start.~Window();
	exit = true;
	}

	start.update();
	}
}
#endif