#include "MotionController.h"

namespace spacey{ namespace motion{

	void Motion::dirRight(){
			xacceleration = 0.3;

	}

	void Motion::dirLeft(){
			xacceleration = -0.3;
	}

	void Motion::dirUp(){
			yacceleration = 0.3;
	}

	void Motion::dirDown(){
			yacceleration = -0.3;
	}

	void Motion::applySpeed(){
		// use -= to move background opposite to input
		xspeed -= xacceleration;
		yspeed -= yacceleration;

		glTranslatef(xspeed, yspeed, 0);
	}

	void Motion::rotate(const char* direction){
		if (direction == "UP"){

		}
		if (direction == "DOWN"){

		}
		if (direction == "LEFT"){

		}
		if (direction == "RIGHT"){

		}
	}

} }