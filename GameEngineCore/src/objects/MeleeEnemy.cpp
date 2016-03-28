#include "MeleeEnemy.h"

namespace spacey{
	namespace objects{
		MeleeEnemy::MeleeEnemy(){
			x_coord = 0;
			y_coord = 0;
		}

		MeleeEnemy::MeleeEnemy(int x, int y, string filename){
			x_coord = x;
			y_coord = y;

			imageLoaded = loadImage(filename, m_image, u2, v2, u3, v3, width, height);

			width = height = 32;
		}

		MeleeEnemy::~MeleeEnemy(){

		}

		void MeleeEnemy::Draw(Motion* motion){

			if (imageLoaded){

				// Enable the texture for OpenGL.
				glEnable(GL_TEXTURE_2D);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //GL_NEAREST = no smoothing
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//GL_LINEAR = smoothing
				glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &m_image[0]);

				//Draw the texture
				glPushMatrix();

				glBegin(GL_QUADS);
				glTexCoord2d(0, v3);		 glVertex2d(x_coord - 16, y_coord - 16);
				glTexCoord2d(0, 0);		 glVertex2d(x_coord - 16, y_coord + 16);
				glTexCoord2d(u3, 0);	 glVertex2d(x_coord + 16, y_coord + 16);
				glTexCoord2d(u3, v3);		 glVertex2d(x_coord + 16, y_coord - 16);
				glEnd();

				glPopMatrix();

			}
			else{

				glPushMatrix();
				glBegin(GL_QUADS);
				glVertex2d(x_coord - 5, y_coord - 10); //Bottom Left Corner
				glVertex2d(x_coord - 5, y_coord + 10); //Top left corner
				glVertex2d(x_coord + 5, y_coord - 10); //Top Right Corner
				glVertex2d(x_coord + 5, y_coord + 10);//Bottolm right corner
				glEnd();
				glPopMatrix();

			}

			

			walk();
		}

		

		void MeleeEnemy::walk(){
			if (steps >= STEP_MAX){
				steps = 0;
				direction = rand() % 8 + 1;
			}
			else{
				switch (direction){
				case 1: //Up
					y_coord += 0.4;
					break;
				case 2: //Up Right
					x_coord += 0.4;
					y_coord += 0.4;
					break;
				case 3:  //Right
					x_coord += 0.4;
					break;
				case 4: //Down Right
					x_coord += 0.4;
					y_coord -= 0.4;
					break;
				case 5: //Down
					y_coord -= 0.4;
					break;
				case 6: //Left Down
					x_coord -= 0.4;
					y_coord -= 0.4;
					break;
				case 7: //Left
					x_coord -= 0.4;
					break;
				case 8: //Left Up
					x_coord -= 0.4;
					y_coord += 0.4;
					break;
				default:
					std::cout << "Not a valid enemy movement key.\n";
					break;
				}

				steps++;
			}
		}
		MeleeEnemy MeleeEnemy::operator=(MeleeEnemy right){
			right.counter = counter;
			right.direction = direction;
			right.health = health;
			right.height = height;
			right.imageLoaded = imageLoaded;
			right.m_image = m_image;
			right.pointing = pointing;
			right.steps = steps;
			right.u2 = u2;
			right.u3 = u3;
			right.v2 = v2;
			right.v3 = v3;
			right.width = width;
			right.x_coord = x_coord;
			right.y_coord = y_coord;

			return right;
		}

}
}