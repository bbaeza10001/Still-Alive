#include "CollisionDetection.h"

namespace spacey{ namespace motion{

	int motion::checkCollision(vector<CircleObject> &terrain, int xInput, int yInput){

		vector<bool> collided;
		int direction;

		for (int i = 0; i < terrain.size(); i++){

			/*
				The following formula only works with detecting collisions of a square, if collision of circles is required,
				use a formula including sin/cos
			*/

			if (terrain[i].x_coord + terrain[i].radius >= -5 && terrain[i].x_coord - terrain[i].radius <= 5){

				if (terrain[i].y_coord + terrain[i].radius >= -10 && terrain[i].y_coord - terrain[i].radius <= 10){
					collided.push_back(true);
					if (xInput != 0){
						direction = xInput;
					}
					else{
						direction = yInput;
					}
				}
			}
		}

		//The below section ensures that if only one object is collided into, the entire world stops moving
		if (find(collided.begin(), collided.end(), true) != collided.end()){
			return direction;
		}
		else{
			return 0;
		}
	}

} }