#include "InputController.h"

namespace spacey{ namespace input{

	void input::checkForInput(Window* window, Motion* motionController){

		//Horizontal Movement
		if (window->isKeyPressed(GLFW_KEY_D)){
			motionController->dirRight();

		}
		else if (window->isKeyPressed(GLFW_KEY_A)){
			motionController->dirLeft();

		}
		else{
			motionController->xacceleration = 0;
		}

		//Vertical Movement
		if (window->isKeyPressed(GLFW_KEY_W)){
			motionController->dirUp();

		} 
		else if (window->isKeyPressed(GLFW_KEY_S)){
			motionController->dirDown();

		}
		else{
			motionController->yacceleration = 0;
		}

		//Turning
		if (window->isKeyPressed(GLFW_KEY_W)){
			
		}
		else if (window->isKeyPressed(GLFW_KEY_S)){
			
		}
		else if (window->isKeyPressed(GLFW_KEY_A)){

		}
		else if (window->isKeyPressed(GLFW_KEY_D)){

		}

	}

} }