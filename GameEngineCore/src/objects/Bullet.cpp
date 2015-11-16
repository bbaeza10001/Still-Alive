#include "Bullet.h"

namespace spacey{ 	namespace objects{

	Bullet::Bullet(){
		m_direction = 0;
	}

	Bullet::Bullet(int direction){
		m_direction = direction;
	}

	void Bullet::Fire(int xInput, int yInput, int colCode){

		glPushMatrix();
		glColor3f(1, 1, 0.5);
		glBegin(GL_QUADS);
		glVertex2f(bX - 1, bY);
		glVertex2f(bX + 1, bY);
		glVertex2f(bX + 1, bY - 2);
		glVertex2f(bX - 1, bY - 2);
		glEnd();

		Move(xInput, yInput, colCode);
		glPopMatrix();
	}

	bool Bullet::limit(){

		if ((bX - 100) > x_coord || (bX + 100) < x_coord){
			return true;
		}

		else if ((bY - 100) > y_coord || (bY + 100) < y_coord){
			return true;
		}
		else{
			return false;
		}
	}

	void Bullet::Move(int m_xInput, int m_yInput, int m_colCode){
		switch (m_direction){
		case 1: //Move left
			bX -= 0.5f;
			break;
		case 2: //Move right
			bX += 0.5f;
			break;
		case 3: //Move up
			bY += 0.5f;
			break;
		case 4: //Move down
			bY -= 0.5f;
			break;
		default: //Print out an error message
			std::cout << "Error: Bullet orientation is invalid.\n";
			std::cout << "Direction Code is: " << m_xInput << std::endl;
			break;
		}

		//X Movements
		if (m_xInput == 1 && m_colCode != 1){
			bX++;
		}

		if (m_xInput == 2 && m_colCode != 2){
			bX--;
		}

		//Y Movements
		if (m_yInput == 3 && m_colCode != 3){
			bY--;
		}
		else if (m_yInput == 4 && m_colCode != 4){
			bY++;
		}
		
	}
} }