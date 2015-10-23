#include "Bullet.h"

namespace spacey{ 	namespace objects{

	void Bullet::Fire(){

		glColor3f(1, 1, 0);
		glBegin(GL_QUADS);
		glVertex2f(bX - 1, bY);
		glVertex2f(bX + 1, bY);
		glVertex2f(bX + 1, bY - 1);
		glVertex2f(bX - 1, bY - 1);
		glEnd();

		Move();
		reset();
	}

	void Bullet::reset(){

		if ((bX - 40) > x_coord || (bX + 40) < x_coord){
			bX = 0;
		}
		if ((bY - 40) > y_coord || (bY + 40) < y_coord){
			bY = 0;
		}
	}

	void Bullet::Move(){
		switch (orientation){
		case 1: //Move left
			bX -= 0.1f;
			break;
		case 2: //Move right
			bX += 0.1f;
			break;
		case 3: //Move up
			bY += 0.1f;
			break;
		case 4: //Move down
			bY -= 0.1f;
			break;
		default: //Print out an error message
			std::cout << "Error: Movement direction is invalid.\n";
			std::cout << "Direction Code is: " << orientation << std::endl;
			break;
		}
		
	}
} }