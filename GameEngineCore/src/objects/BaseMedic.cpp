//Made by Kenny and Will
#include "BaseMedic.h"

namespace spacey{
	namespace objects{

		BaseMedic::BaseMedic(){
			x_coord = 0;
		}

		BaseMedic::~BaseMedic(){

		}



		BaseMedic::BaseMedic(int x, int y, string filename){
			x_coord = x;
			y_coord = y;

			imageLoaded = loadImage(filename, m_image, u2, v2, u3, v3, width, height);


		}


		void BaseMedic::Draw(){

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
				glBegin(GL_TRIANGLES);
				glVertex2d(x_coord - 5, y_coord - 10); //Bottom Left Corner
				glVertex2d(x_coord, y_coord + 10); //Nose of Ship
				glVertex2d(x_coord + 5, y_coord - 10); //Top Right Corner
				glEnd();
				glPopMatrix();


			}

		}

		void BaseMedic::Heal(BaseEnemy &enem, unsigned int i){

			if (enem.health <= 50 && healing == i){
				available = false;

				if (enem.x_coord > x_coord){
					x_coord++;
				} 

				if (enem.x_coord < x_coord){
					x_coord--;
				}
				
				if (enem.y_coord > y_coord){
					y_coord++;
				}
				
				if (enem.y_coord < y_coord){
					y_coord--;
				}

				if ((x_coord - (m_width / 2) <= enem.x_coord + (enem.m_width / 2) && x_coord + (m_width / 2) >= enem.x_coord - (enem.m_width / 2)
					&& y_coord + (m_height / 2) >= enem.y_coord - (enem.m_height / 2) && y_coord - (m_height / 2) <= enem.y_coord - (enem.m_height / 2))){
					enem.health += 10;

					if (enem.health > 50){
						available = true;
					}
					cout << "Enemy has been healed 10 single points" << endl;
					cout << "Current Health: " << enem.health << endl;
					cout << "Y U DO ANAL?" << endl;
				}
			}
			else if (enem.health <= 50 && available == true){
				healing = i;
			}

		}


	}
}