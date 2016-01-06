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

	}

	BaseEnemy::~BaseEnemy(){
		
	}
	
	void BaseEnemy::Draw(Motion* motion){

		if (imageLoaded){

			//Draw circle w/ a texture
			// Enable the texture for OpenGL.
			glEnable(GL_TEXTURE_2D);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //GL_NEAREST = no smoothing
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//GL_LINEAR = smoothing
			glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &m_image[0]);

			//Draw the texture
			glPushMatrix();

			glTranslatef(x_coord, y_coord, 0);
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
		Bullet bullet(direction);
		bullet.bX = x_coord;
		bullet.bY = y_coord;
		bullet.bx_coord = x_coord;
		bullet.by_coord = y_coord;
		delaware.push_back(bullet);
	}

	void BaseEnemy::createNewBullet(){
		if (counter < 100){
			counter++;
		}
		else{
			bulletFill();
			counter = 0;
		}
	}

	void BaseEnemy::walk(){
		if (steps >= 300){
			steps = 0;
			direction = rand() % 4 + 1;
		}
		else{
			switch (direction){
			case 1:
				x_coord -= 0.2;
				break;
			case 2:
				x_coord += 0.2;
				break;
			case 3: 
				y_coord += 0.2;
				break;
			case 4: 
				y_coord -= 0.2;
				break;
			default:
				std::cout << "Not a valid enemy movement key.\n";
				break;
			}

			steps++;
		}
	}

} }