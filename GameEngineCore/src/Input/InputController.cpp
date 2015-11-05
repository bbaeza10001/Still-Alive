#include "InputController.h"

namespace spacey{ namespace input{

	int input::checkForXInput(Window* window){

		//Horizontal Movement
		if (window->isKeyPressed(GLFW_KEY_D)){
			return 2;
		}
		else if (window->isKeyPressed(GLFW_KEY_A)){
			return 1;
		}
		else{
			return 0;
		}

	}

	int input::checkForYInput(Window* window){

		//Vertical Movement
		if (window->isKeyPressed(GLFW_KEY_W)){
			return 3;
		}
		else if (window->isKeyPressed(GLFW_KEY_S)){
			return 4;
		}
		else{
			return 0;
		}

	}
}
} 