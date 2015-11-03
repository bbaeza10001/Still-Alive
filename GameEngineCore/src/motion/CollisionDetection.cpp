#include "CollisionDetection.h"

namespace spacey{ namespace motion{

	bool motion::checkCollision(vector<CircleObject> &terrain){

		vector<bool> collided;

		for (int i = 0; i < terrain.size(); i++){

			if (terrain.at(i).x_coord >= -10 && terrain.at(i).x_coord <= 10){

				if (terrain.at(i).y_coord >= -10 && terrain.at(i).y_coord <= 10){
					collided.push_back(true);
				}
			}
		}

		if (find(collided.begin(), collided.end(), true) != collided.end()){
			return true;
		}
		else{
			return false;
		}
	}

} }