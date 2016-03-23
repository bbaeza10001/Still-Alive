#include "BaseEnemy.h"

namespace spacey{ namespace objects{

	BaseEnemy::BaseEnemy(){
		x_coord = 0;
		y_coord = 0;
	}

	BaseEnemy::BaseEnemy(int x, int y, string filename){
		x_coord = x;
		y_coord = y;

		imageLoaded = loadImage(filename, m_image, u2, v2, u3, v3, width, height);

		width = height = 32;
	}

	BaseEnemy::~BaseEnemy(){
		
	}
	
	void BaseEnemy::Draw(Motion* motion){

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

		if (!delaware.empty()){
			for (int i = 0; i < delaware.size(); i++){
				delaware[i].Fire();
				if (delaware[i].limit()){
					delaware.erase(delaware.begin() + i);
				}
			}
		}

		createNewBullet();
		walk();
	}

	void BaseEnemy::bulletFill(){
		Bullet bullet(direction, x_coord, y_coord);
		delaware.push_back(bullet);
	}

	void BaseEnemy::createNewBullet(){
		if (counter < 500){
			counter++;
		}
		else{
			bulletFill();
			counter = 0;
		}
	}

	void BaseEnemy::walk(){
		if (steps >= STEP_MAX){
			steps = 0;
			direction = rand() % 8 + 1;
		}
		else{
			switch (direction){
			case 1: //Up
				y_coord += 0.2;
				break;
			case 2: //Up Right
				x_coord += 0.2;
				y_coord += 0.2;
				break;
			case 3:  //Right
				x_coord += 0.2;
				break;
			case 4: //Down Right
				x_coord += 0.2;
				y_coord -= 0.2;
				break;
			case 5: //Down
				y_coord -= 0.2;
				break;
			case 6: //Left Down
				x_coord -= 0.2;
				y_coord -= 0.2;
				break;
			case 7: //Left
				x_coord -= 0.2;
				break;
			case 8: //Left Up
				x_coord -= 0.2;
				y_coord += 0.2;
				break;
			default:
				std::cout << "Not a valid enemy movement key.\n";
				break;
			}

			steps++;
		}
	}

	BaseEnemy BaseEnemy::operator=(BaseEnemy right){
		BaseEnemy temp;

		temp.bX = right.bX;
		temp.bY = right.bY;
		temp.counter = right.counter;
		temp.delaware = right.delaware;
		temp.direction = right.direction;
		temp.health = right.health;
		temp.height = right.height;
		temp.imageLoaded = right.imageLoaded;
		temp.m_image = right.m_image;
		temp.pointing = right.pointing;
		temp.steps = right.steps;
		temp.u2 = right.u2;
		temp.u3 = right.u3;
		temp.v2 = right.v2;
		temp.v3 = right.v3;
		temp.width = right.width;
		temp.x_coord = right.x_coord;
		temp.y_coord = right.y_coord;

		return temp;
	}
} }