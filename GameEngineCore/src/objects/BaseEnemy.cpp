#include "BaseEnemy.h"

namespace spacey{ namespace objects{

	BaseEnemy::BaseEnemy(){
		x_coord = 0;
		y_coord = 0;
	}

	BaseEnemy::~BaseEnemy(){
		
	}

	void BaseEnemy::draw(int xInput, int yInput, int colCode){

		m_xInput = xInput;
		m_yInput = yInput;
		m_colCode = colCode;

		glPushMatrix();
		glBegin(GL_TRIANGLES);
		glVertex2d(x_coord - 5, y_coord - 10); //Bottom Left Corner
		glVertex2d(x_coord, y_coord + 10); //Nose of Ship
		glVertex2d(x_coord + 5, y_coord - 10); //Top Right Corner
		glEnd();
		glPopMatrix();

		move();
	}

	BaseEnemy::BaseEnemy(int x, int y){
		x_coord = x;
		y_coord = y;
	}

	void BaseEnemy::move(){
		//X Movements
		if (m_xInput == 1 && m_colCode != 1){
			x_coord++;
		}
		else if (m_xInput == 2 && m_colCode != 2){
			x_coord--;
		}

		//Y Movements
		if (m_yInput == 3 && m_colCode != 3){
			y_coord--;
		}
		else if (m_yInput == 4 && m_colCode != 4){
			y_coord++;
		}
	}

} }