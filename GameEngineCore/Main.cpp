#include "src\include\Includes.h"
#include "src\graphics\Texture.h"
#include "src\objects\Bullet.h"

using namespace spacey;
using namespace graphics;
using namespace objects;
using namespace motion;
using namespace input;
using namespace std;
using namespace level;

/*
	TO DO:

	** Figure out if turning some classes into structs rather is more efficient

	** Add background photos

	** Begin a sound engine

	** Change player rotation to directional movement

	** Add param to text doc to set object images

	** Add collision detection

	** Fix the image loader
	
	** Beautify the shooting system

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

		Motion motion;
		Input input; //see if changing to a library type file is possible/better
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

			input.checkForInput(&window, &motion);

			// Update Background
			glPushMatrix();
			motion.applySpeed();
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

