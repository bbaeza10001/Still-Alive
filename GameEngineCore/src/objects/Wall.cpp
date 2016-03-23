#include "Wall.h"

namespace spacey{
	namespace objects{

		Wall::Wall(){
			m_width = 0;
			m_height = 0;
			x_coord = 0;
			y_coord = 0;
		}

		Wall::Wall(int width, int height, int x, int y, string type){
			m_width = width;
			m_height = height;
			x_coord = x;
			y_coord = y;

			string filename;

			if (type == "TEST"){
				filename = "Basic_Wall.png";
			}
			else if (type == "BRICK"){

			}
			else if (type == "STONE"){

			}

			unsigned temp, temp2;

			imageLoaded = loadImage(filename, m_image, u2, v2, u3, v3, temp, temp2);
		}

		void Wall::Draw(){

			if (imageLoaded){
				// Enable the texture for OpenGL.
				glEnable(GL_TEXTURE_2D);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//GL_LINEAR = smoothing
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &m_image[0]);

				u3 = m_width / u2;
				v3 = m_height / v2;

				//Draw the texture
				glPushMatrix();

				glBegin(GL_QUADS);
				glTexCoord2d(0, v3);	 glVertex2d(x_coord - (m_width / 2), y_coord - (m_height / 2));
				glTexCoord2d(0, 0);		 glVertex2d(x_coord - (m_width / 2), y_coord + (m_height / 2));
				glTexCoord2d(u3, 0);	 glVertex2d(x_coord + (m_width / 2), y_coord + (m_height / 2));
				glTexCoord2d(u3, v3);	 glVertex2d(x_coord + (m_width / 2), y_coord - (m_height / 2));
				glEnd();

				glPopMatrix();
			}
			else{

				glPushMatrix();
				glTranslatef(x_coord, y_coord, 0);
				glBegin(GL_QUADS);
				glVertex2f(x_coord, y_coord);
				glVertex2f(x_coord, y_coord + m_height);
				glVertex2f(x_coord + m_width, y_coord + m_height);
				glVertex2f(x_coord + m_width, y_coord);
				glEnd();

			}
			glPopMatrix();
		}
	}
}