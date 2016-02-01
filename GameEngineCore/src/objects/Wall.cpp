#include "Wall.h"

namespace spacey{
	namespace objects{

		Wall::Wall(){
			m_width = 0;
			m_height = 0;
		}

		Wall::Wall(int width, int height, int x, int y){
			m_width = width;
			m_height = height;
			x_coord = x;
			y_coord = y;

			imageLoaded = loadImage("Basic_Wall.png", m_image, u2, v2, u3, v3, m_width, m_height);
		}

		void Wall::Draw(){

			if (imageLoaded){
				// Enable the texture for OpenGL.
				glEnable(GL_TEXTURE_2D);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //GL_NEAREST = no smoothing
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//GL_LINEAR = smoothing
				glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &m_image[0]);

				//Draw the texture
				glPushMatrix();

				glTranslatef(x_coord, y_coord, 0);
				glBegin(GL_QUADS);
				glTexCoord2d(0, v3);		 glVertex2d(x_coord - (width / 2), y_coord - (height / 2));
				glTexCoord2d(0, 0);		 glVertex2d(x_coord - (width / 2), y_coord + (height / 2));
				glTexCoord2d(u3, 0);	 glVertex2d(x_coord + (width / 2), y_coord + (height / 2));
				glTexCoord2d(u3, v3);		 glVertex2d(x_coord + (width / 2), y_coord - (height / 2));
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