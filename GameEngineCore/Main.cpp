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

	** Implement Basic Enemies
		-Allow them to shoot every once in a while
		-Allow them basic movements every once in a while
	
	** Shooting System: 
		-Adjust to allow shooting while moving
		-Adjust to allow diagonal shooting

	** Begin a sound engine

	** Fix the image loader

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

#if 0
int main(){
	//Width and height for the game window
	int width = 800;
	int height = 600;

	int x = 0, y = 0, z = 0;

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

	/*Texture test("Brandenbrug Tor.jpg"); 

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
	}*/
	
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


			/* Camera Testing */
			if (window.isKeyPressed(GLFW_KEY_LEFT)){
				gluLookAt(x, y, z, 1, y, z, 0, -1, 0);
				cout << "Moved Camera Left\n";
			}

			window.update();
			Sleep(0.5); //Controls how fast the game loop runs at max
		}

	}
	return 0;
}
#endif

int main(){
	int s_width = 800;
	int s_height = 600;

	//Start Screen
	static Window start("Still Alive - Start", s_width, s_height);

	/*button b_start(&start, 250, 400, 50, 40, "Brandenbrug Tor.jpg");
	button b_exit(&start, 550, 400, 50, 40, "sample.bmp");*/
	bool exit = false; //Exit bool having to do with the commented out code above (Start Window)

	const char* filename = "ship.png";

	// Load file and decode image.
	std::vector<unsigned char> image;
	unsigned width, height;
	unsigned error = lodepng::decode(image, width, height, filename);

	// If there's an error, display it.
	if (error != 0)
	{
		std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
		return 1;
	}

	// Here the PNG is loaded in "image". All the rest of the code is SDL and OpenGL stuff.

	int screenw = width;
	if (screenw > 1024) screenw = 1024;
	int screenh = height;
	if (screenh > 768) screenw = 768;

	// The official code for "Setting Your Raster Position to a Pixel Location" (i.e. set up a camera for 2D screen)
	glViewport(0, 0, screenw, screenh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, screenw, screenh, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Make some OpenGL properties better for 2D and enable alpha channel.
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);

	if (glGetError() != GL_NO_ERROR)
	{
		std::cout << "Error initing GL" << std::endl;
		return 1;
	}

	// Texture size must be power of two for the primitive OpenGL version this is written for. Find next power of two.
	size_t u2 = 1; while (u2 < width) u2 *= 2;
	size_t v2 = 1; while (v2 < height) v2 *= 2;
	// Ratio for power of two version compared to actual version, to render the non power of two image with proper size.
	double u3 = (double)width / u2;
	double v3 = (double)height / v2;

	// Make power of two version of the image.
	std::vector<unsigned char> image2(u2 * v2 * 4);
	for (size_t y = 0; y < height; y++)
		for (size_t x = 0; x < width; x++)
			for (size_t c = 0; c < 4; c++)
			{
				image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];
			}

	// Enable the texture for OpenGL.
	glEnable(GL_TEXTURE_2D);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image2[0]);

	glColor4ub(255, 255, 255, 255);

	while (!start.closed()){
	start.clear();

	/*b_start.draw();
	b_exit.draw();
	if (b_start.clicked()){
	start.~Window();
	}
	else if (b_exit.clicked()){
	start.~Window();
	exit = true;
	}*/

	// Draw the texture on a quad, using u3 and v3 to correct non power of two texture size.
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex2f(0, 0);
	glTexCoord2d(u3, 0); glVertex2f(width, 0);
	glTexCoord2d(u3, v3); glVertex2f(width, height);
	glTexCoord2d(0, v3); glVertex2f(0, height);
	glEnd();


	start.update();
	// Redraw and clear screen.
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}
