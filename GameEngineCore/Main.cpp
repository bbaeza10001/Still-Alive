#include "src\include\Includes.h"
#include "src\graphics\Texture.h"
#include "src\objects\Bullet.h"
#include "src\motion\CollisionDetection.h"

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

	** Fix the image loader

	** Add param to text doc to set object images
	
	** Add background photos

	ISSUES:

	--COLLISION DETECTIONS--
		**Player collides with but something is wrong with the collision detection.cpp and it's direction tracking
			so...????
	--BULLET SYSTEM--
		**Add multi-directional shooting (Look in the playerobject.cpp for the comments on where to do that

*/
int main(){
	//Width and height for the game window
	int width = 800;
	int height = 600;

	//Start Screen
	//static Window start("Still Alive - Start", width, height);

	//// opengl setup
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D(0, width * 2, height * 2, 0); //Adjusts coordinate system to start from top left
	//                                         //and be the correct width and height
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	//button b_start(&start, 250, 400, 50, 40, "Brandenbrug Tor.jpg");
	//button b_exit(&start, 550, 400, 50, 40, "sample.bmp");
	bool exit = false; //Exit bool having to do with the commented out code above (Start Window)

	//Texture test("Brandenbrug Tor.jpg"); //Texturing test --DOES NOT WORK YET--

	//while (!start.closed()){
	//	start.clear();

	//	b_start.draw();
	//	b_exit.draw();
	//	if (b_start.clicked()){
	//		start.~Window();
	//	}
	//	else if (b_exit.clicked()){
	//		start.~Window();
	//		exit = true;
	//	}
	//	start.update();
	//}
	
	if (exit == false){

		//Game Window
		static Window window("Still Alive", width, height);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Game background color

		// opengl setup
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0); //Sets coordinate system to start in 
		                                                                    //the middle of the screen like a standard graph
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		// Construction
		PlayerObject player(&window);
		vector<CircleObject> test = loadPlanets(test, "level.txt"); //Loading in the planets from the "level.txt" file
																	//Play around with the numbers in the file, see what it does :)
		
		int xIN, yIN, colCode, lastColCode = 0; //Ints having to do with collision detection

		while (!window.closed()){
			window.clear();

			xIN = checkForXInput(&window); //Getting input values from the player in the current window
			yIN = checkForYInput(&window);

			if ((xIN != lastColCode || yIN != lastColCode) && xIN != 0 && yIN != 0){ //Player input != the last collision code
			
				lastColCode = 0; //There is no longer a collision
			}
			
			// Update Background
			for (unsigned int i = 0; i < test.size(); i++){
				test[i].Draw(xIN, yIN, lastColCode);
			}

			// Update Player 
			player.Draw(xIN, yIN, lastColCode);

			lastColCode = checkCollision(test, xIN, yIN); //Reset the collision code
		
			window.update();
			Sleep(0.5); //Controls how fast the game loop runs at max
		}

	}
	return 0;
}
