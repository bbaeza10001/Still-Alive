#include "InputController.h"

namespace spacey{ namespace input{

	void Input::checkForInput(Window* window, Motion* motionController){

		//Horizontal Movement
		if (window->isKeyPressed(GLFW_KEY_D)){
			motionController->dirRight();

		}
		else if (window->isKeyPressed(GLFW_KEY_A)){
			motionController->dirLeft();

		}

		//Vertical Movement
		if (window->isKeyPressed(GLFW_KEY_W)){
			motionController->dirUp();

		} 
		else if (window->isKeyPressed(GLFW_KEY_S)){
			motionController->dirDown();

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