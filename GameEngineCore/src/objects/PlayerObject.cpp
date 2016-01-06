#include "PlayerObject.h"

namespace spacey{
	namespace objects{
		PlayerObject::PlayerObject(Window* window, string filename){
			x_coord = 0;
			y_coord = 0;
			m_window = window;

			if (filename != "")
				imageLoaded = loadImage(filename, m_image, u2, v2, u3, v3, width, height);

		}

		void PlayerObject::Draw(Motion* motion){
			
			checkFire();
			checkRotation();

			if (imageLoaded){
				// Enable the texture for OpenGL.
				glEnable(GL_TEXTURE_2D);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &m_image[0]);

				//Draw the image on a polygon
				glPushMatrix();
				motion->applyRotation();
				glBegin(GL_QUADS);
				glTexCoord2d(0, v3);	glVertex2d(-15.0f, -15.0f);
				glTexCoord2d(0, 0);		glVertex2d(-15.0f, 15.0f);
				glTexCoord2d(u3, 0);	glVertex2d(15.0f, 15.0f);
				glTexCoord2d(u3, v3);	glVertex2d(15.0f, -15.0f);
				glEnd();

				glPopMatrix();

			}
			else {

				glPushMatrix();

				glColor3f(1.0, 0.0, 0.0); //Sets the color of the ship each time it's drawn
				glBegin(GL_TRIANGLES);
				glVertex2d(-5.0f, -10.0f);
				glVertex2d(0, 10.0f); //Nose of Ship
				glVertex2d(5.0f, -10.0f);
				glEnd();

				glPopMatrix();
			}


			if (!shot.empty()){
				for (int i = 0; i < shot.size(); i++){
					shot[i].Fire();
					if (shot[i].limit()){
						shot.erase(shot.begin() + i);
					}
				}
			}


		}

		void PlayerObject::checkRotation(){
			//Use the motion controller to check how far the player needs to turn
		}

		void PlayerObject::checkFire(){
			if (m_window->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)){
				Bullet bullet(direction);
				shot.push_back(bullet);
			}
		}
	}
}