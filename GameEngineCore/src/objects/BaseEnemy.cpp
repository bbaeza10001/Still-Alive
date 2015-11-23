#include "BaseEnemy.h"

namespace spacey{ namespace objects{

	BaseEnemy::BaseEnemy(){
		x_coord = 0;
		y_coord = 0;
	}

	BaseEnemy::~BaseEnemy(){
		
	}

	void BaseEnemy::draw(){

		glPushMatrix();
		glBegin(GL_TRIANGLES);
		glVertex2d(x_coord - 5, y_coord - 10); //Bottom Left Corner
		glVertex2d(x_coord, y_coord + 10); //Nose of Ship
		glVertex2d(x_coord + 5, y_coord - 10); //Top Right Corner
		glEnd();
		glPopMatrix();


	}

	BaseEnemy::BaseEnemy(int x, int y){
		x_coord = x;
		y_coord = y;
	}

} }