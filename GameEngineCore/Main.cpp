#include "src\include\Includes.h"
#include "src\graphics\Texture.h"
#include "src\objects\Bullet.h"

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace std;
using namespace level;
using namespace input;

/*
	TO DO:

	** Add collision detection:
		-Check if player and backgorund are on the same matrix
		-If they are, track x & y of objects and stop movement if they reach player
		-If they are not, 
			EITHER: Define point on the objects matrix that they cannot move into
			OR: Move player to the same matrix and then act on the first if
	
	** Shooting System: 
		-Adjust to allow shooting while moving
		-Adjust to allow bullets to continue firing when click is released
		-Adjust to allow diagonal shooting

	** Find a way to use functions in other .h files without having to create class objects

	** Begin a sound engine

	** Fix the image loader

	** Add param to text doc to set object images
	
	** Add background photos

*/

int main(){
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
	bool exit = false;

	//Texture test("Brandenbrug Tor.jpg");

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
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		Input inputController;
		Motion motionController;
		Level load;  //And this

		// opengl setup
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-width / 2.0, width / 2.0, -height / 2.0, height / 2.0); //Sets coordinate system to start in 
		                                                                    //the middle of the screen like a standard graph
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		// Construction
		PlayerObject player(&window);
		vector<CircleObject> test = load.loadPlanets(test, "level.txt");
		Bullet bullet(player);


		while (!window.closed()){
			window.clear();

			inputController.checkForInput(&window, &motionController);

			// Update Background
			glPushMatrix();
			motionController.applySpeed();
			for (unsigned int i = 0; i < test.size(); i++){
				test[i].Draw();
			}
			glPopMatrix();

			// Update Player 
			glPushMatrix();
			player.Draw(); // Bullet movements offsetting
			glPopMatrix();

			window.update();
			Sleep(0.5); //Controls how fast the game loop runs
		}

	}
	return 0;
}

