#include "BaseEnemy.h"

namespace spacey{ namespace objects{

	BaseEnemy::BaseEnemy(){
		x_coord = 0;
		y_coord = 0;
	}

	BaseEnemy::BaseEnemy(int x, int y, int tWidth, int tHeight, string filename){
		x_coord = x;
		y_coord = y;
		m_texWidth = tWidth;
		m_texHeight = tHeight;
		imageLoaded = loadAnimateable(filename, m_image, u2, v2, width, height);

		framesPerRow = width / m_texWidth;
	}

	BaseEnemy::~BaseEnemy(){
		
	}

	void BaseEnemy::AI(string indicator){

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
				mObj.animFlag = "WALK_UP";
				break;
			case 2: //Up Right
				x_coord += 0.2;
				y_coord += 0.2;
				break;
			case 3:  //Right
				x_coord += 0.2;
				mObj.animFlag = "WALK_RIGHT";
				break;
			case 4: //Down Right
				x_coord += 0.2;
				y_coord -= 0.2;
				break;
			case 5: //Down
				y_coord -= 0.2;
				mObj.animFlag = "WALK_DOWN";
				break;
			case 6: //Left Down
				x_coord -= 0.2;
				y_coord -= 0.2;
				break;
			case 7: //Left
				x_coord -= 0.2;
				mObj.animFlag = "WALK_LEFT";
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
		right.bX = bX;
		right.bY = bY;
		right.counter = counter;
		right.delaware = delaware;
		right.direction = direction;
		right.health = health;
		right.height = height;
		right.imageLoaded = imageLoaded;
		right.m_image = m_image;
		right.pointing = pointing;
		right.steps = steps;
		right.u2 = u2;
		right.u3 = u3;
		right.v2 = v2;
		right.v3 = v3;
		right.width = width;
		right.x_coord = x_coord;
		right.y_coord = y_coord;
		
		return right;
	}

} }