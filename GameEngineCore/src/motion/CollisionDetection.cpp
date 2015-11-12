#include "CollisionDetection.h"

namespace spacey{ namespace motion{

	int motion::checkCollision(vector<CircleObject> &terrain, int xInput, int yInput){

		vector<bool> collided;
		vector<int> direction;

		for (int i = 0; i < terrain.size(); i++){

			/*
				The following formula only works with detecting collisions of a square, if collision of circles is required,
				use a formula including sin/cos
			*/

			if (terrain[i].x_coord + terrain[i].radius >= -5 && terrain[i].x_coord - terrain[i].radius <= 5){

				if (terrain[i].y_coord + terrain[i].radius >= -10 && terrain[i].y_coord - terrain[i].radius <= 10){
					//Fix the return value, it is returning what is currently being pressed once you collide with an object
					
					collided.push_back(true);
					if (xInput != 0){
						direction.push_back(xInput);
					}
					else{
						direction.push_back(yInput);
					}
				}
			}
			else {
				collided.push_back(false);
				direction.push_back(0);
			}
		}
		//The below section ensures that if only one object is collided into, the entire world stops moving
		for (int i = 0; i < collided.size(); i++){
			if (collided[i] == true){
				return direction[i];
			}
		}

		collided.clear();
		direction.clear();
	}

	int motion::checkCollision(vector<Wall> &terrain, int xInput, int yInput){

		vector<bool> collided;
		vector<int> direction;

		for (int i = 0; i < terrain.size(); i++){

			if (terrain[i].x_coord + terrain[i].m_width >= -5 && terrain[i].x_coord - terrain[i].m_width <= 5){

				if (terrain[i].y_coord + terrain[i].m_height >= -10 && terrain[i].y_coord - terrain[i].m_height <= 10){
					//Fix the return value, it is returning what is currently being pressed once you collide with an object

					collided.push_back(true);
					if (xInput != 0){
						direction.push_back(xInput);
					}
					else{
						direction.push_back(yInput);
					}
				}
			}
			else {
				collided.push_back(false);
				direction.push_back(0);
			}
		}
		//The below section ensures that if only one object is collided into, the entire world stops moving
		for (int i = 0; i < collided.size(); i++){
			if (collided[i] == true){
				return direction[i];
			}
		}

		collided.clear();
		direction.clear();
	}

} }