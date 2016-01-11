#include "Bullet.h"

namespace spacey{ 	namespace objects{

	Bullet::Bullet(){
		m_direction = 0;
	}

	Bullet::Bullet(int direction, float x, float y){
		m_direction = direction;
		bx_coord = bX = x;
		by_coord = bY = y;
		b_imageLoaded = loadImage("ship.png", m_bimage, b_u2, b_v2, b_u3, b_v3, b_width, b_height);
	}

	void Bullet::Fire(){

		if (b_imageLoaded){
			// Enable the texture for OpenGL.
			glEnable(GL_TEXTURE_2D);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //GL_NEAREST = no smoothing
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, 4, b_u2, b_v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &m_bimage[0]);

			//Draw the image on a polygon
			glPushMatrix();
			Move();
			glBegin(GL_QUADS);
			glTexCoord2d(0, b_v3);	glVertex2d(bX - 1, bY - 2);
			glTexCoord2d(0, 0);		glVertex2d(bX - 1, bY + 2);
			glTexCoord2d(b_u3, 0);	glVertex2d(bX + 1, bY + 2);
			glTexCoord2d(b_u3, b_v3);	glVertex2d(bX + 1, bY - 2);
			glEnd();
			
			glPopMatrix();

		}
		else{

			glPushMatrix();
			Move();
			glColor3f(1, 1, 0.5);
			glBegin(GL_QUADS);
			glVertex2f(bX - 1, bY);
			glVertex2f(bX + 1, bY);
			glVertex2f(bX + 1, bY - 2);
			glVertex2f(bX - 1, bY - 2);
			glEnd();
			
			glPopMatrix();
		}
		
	}

	bool Bullet::limit(){

		if ((bX - 100) > bx_coord || (bX + 100) < bx_coord){
			return true;
		}

		else if ((bY - 100) > by_coord || (bY + 100) < by_coord){
			return true;
		}
		else{
			return false;
		}
	}

	void Bullet::Move(){
		switch (m_direction){
		case 1: //Move Up
			bY += 0.5f;
			break;
		case 2: //Move Up Right
			bX += 0.5f;
			bY += 0.5f;
			break;
		case 3: //Move Right
			bX += 0.5f;
			break;
		case 4: //Move Down Right
			bX += 0.5f;
			bY -= 0.5f;
			break;
		case 5: //Move Down
			bY -= 0.5f;
			break;
		case 6: //Move Down Left
			bX -= 0.5f;
			bY -= 0.5f;
			break;
		case 7: //Move Left
			bX -= 0.5f;
			break;
		case 8: //Move Up Left
			bX -= 0.5f;
			bY += 0.5f;
			break;
		default: //Print out an error message
			std::cout << "Error: Bullet orientation is invalid.\n";
			std::cout << "Direction Code is: " <<m_direction << std::endl;
			break;
		}
		
	}
} }