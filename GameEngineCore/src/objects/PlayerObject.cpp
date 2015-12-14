#include "PlayerObject.h"

namespace spacey{
	namespace objects{
		PlayerObject::PlayerObject(Window* window){
			x_coord = 0;
			y_coord = 0;
			m_window = window;
		}

		void PlayerObject::Draw(int xInput, int yInput, int colCode){

			m_xInput = xInput;
			m_yInput = yInput;
			m_colCode = colCode;
			
			checkFire();
			glPushMatrix();
			checkRotation();

			glColor3f(0.0, 1.0, 0.0); //Sets the color of the ship each time it's drawn
			glBegin(GL_TRIANGLES);
			glVertex2d(x1, y1); //Bottom Left Corner
			glVertex2d(x2, y2); //Nose of Ship
			glVertex2d(x3, y3); //Top Right Corner
			glEnd();
			

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
			if (m_xInput == 1){
				//Make Bullet move left from then on
				x1 = 10;
				y1 = -5;

				x2 = -10;
				y2 = 0;
				
				x3 = 10;
				y3 = 5;

				direction = 1;
			}
			else if (m_xInput == 2){
				//Make Bullet move right from then on

				x1 = -10;
				y1 = 5;

				x2 = 10;
				y2 = 0;

				x3 = -10;
				y3 = -5;

				direction = 2;
			}

			//Vertical Turn
			if (m_yInput == 3){
				//Make Bullet move up from then on

				x1 = -5;
				y1 = -10;

				x2 = 0;
				y2 = 10;

				x3 = 5;
				y3 = -10;

				direction = 3;
			}
			else if (m_yInput == 4){
				//Make Bullet move down from then on

				x1 = 5;
				y1 = 10;

				x2 = 0;
				y2 = -10;

				x3 = -5;
				y3 = 10;

				direction = 4;
			}
		}

		void PlayerObject::checkFire(){
			if (m_window->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)){
				Bullet bullet(direction);
				shot.push_back(bullet);
			}
		}
	}
}