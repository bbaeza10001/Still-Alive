#include "BaseEnemy.h"

namespace spacey{ namespace objects{

	BaseEnemy::BaseEnemy(){
		x_coord = 0;
		y_coord = 0;
	}

	BaseEnemy::BaseEnemy(int x, int y){
		x_coord = x;
		y_coord = y;
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

		if (!delaware.empty()){
			for (int i = 0; i < delaware.size(); i++){
				delaware[i].Fire(xInput, yInput, colCode);
				if (delaware[i].limit()){
					delaware.erase(delaware.begin() + i);
				}
			}
		}

		move();
		createNewBullet();
		walk();
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

	void BaseEnemy::bulletFill(){
		Bullet bullet(direction);
		bullet.bX = x_coord;
		bullet.bY = y_coord;
		bullet.x_coord = x_coord;
		bullet.y_coord = y_coord;
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