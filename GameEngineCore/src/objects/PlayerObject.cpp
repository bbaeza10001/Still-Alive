#include "PlayerObject.h"

namespace spacey{
	namespace objects{
		PlayerObject::PlayerObject(Window* currentWindow){
			x_coord = 0;
			y_coord = 0;
			m_window = currentWindow;
		}

		void PlayerObject::Draw(int xInput, int yInput, int colCode){

			m_xInput = xInput;
			m_yInput = yInput;
			m_colCode = colCode;

			glPushMatrix();
			glColor3f(1.0, 0.0, 0.0); //Sets the color of the ship each time it's drawn
			glBegin(GL_TRIANGLES);
			glVertex2d(x_coord - 5.0f, y_coord - 10.0f);
			glVertex2d(x_coord, y_coord + 10.0f); //Nose of Ship
			glVertex2d(x_coord + 5.0f, y_coord - 10.0f);
			glEnd();
			
			checkFire();
			checkRotation();
			glPopMatrix();

			if (!shot.empty()){
				for (int i = 0; i < shot.size(); i++){
					shot[i].Fire(xInput, yInput, colCode);
					if (shot[i].limit()){
						shot.erase(shot.begin() + i);
					}
				}
			}


		}

		void PlayerObject::checkRotation(){
			//Horizontal turn
			if (m_window->isKeyPressed(GLFW_KEY_A)){
				//Make Bullet move left from then on
			}
			else if (m_window->isKeyPressed(GLFW_KEY_D)){
				//Make Bullet move right from then on

			}

			//Vertical Turn
			if (m_window->isKeyPressed(GLFW_KEY_W)){
				//Make Bullet move up from then on

			}
			else if (m_window->isKeyPressed(GLFW_KEY_S)){
				//Make Bullet move down from then on

			}
		}

		void PlayerObject::checkFire(){
			if (m_window->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)){
				Bullet bullet;
				shot.push_back(bullet);
			}
		}
	}
}