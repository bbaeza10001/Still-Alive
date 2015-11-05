#include "PlayerObject.h"

namespace spacey{
	namespace objects{
		PlayerObject::PlayerObject(Window* currentWindow){
			x_coord = 0;
			y_coord = 0;
			m_window = currentWindow;
		}

		void PlayerObject::Draw(){
			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0); //Sets the color of the ship each time it's drawn
			glBegin(GL_TRIANGLES);
			glVertex2d(x_coord - 5.0f, y_coord - 10.0f);
			glVertex2d(x_coord, y_coord + 10.0f); //Nose of Ship
			glVertex2d(x_coord + 5.0f, y_coord - 10.0f);
			glEnd();

			checkRotation();
			checkFire();

			glPopMatrix();
		}

		void PlayerObject::checkRotation(){
			//Horizontal turn
			if (m_window->isKeyPressed(GLFW_KEY_A)){
				orientation = 1;
				bY = 0;
				bX = 0;
			}
			else if (m_window->isKeyPressed(GLFW_KEY_D)){
				orientation = 2;
				bY = 0;
				bX = 0;
			}

			//Vertical Turn
			if (m_window->isKeyPressed(GLFW_KEY_W)){
				orientation = 3;
				bX = 0;
				bY = 0;
			}
			else if (m_window->isKeyPressed(GLFW_KEY_S)){
				orientation = 4;
				bX = 0;
				bY = 0;
			}
		}

		void PlayerObject::checkFire(){
			if (m_window->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)){
				Fire();
			}
		}
	}
}