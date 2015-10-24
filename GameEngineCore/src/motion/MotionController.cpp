#include "MotionController.h"

namespace spacey{ namespace motion{

	void Motion::dirRight(){
		if (xacceleration < accelMax)
			xacceleration = 0.3;

	}

	void Motion::dirLeft(){
		if (xacceleration > -accelMax)
			xacceleration = -0.3;
	}

	void Motion::dirUp(){
		if (yacceleration < accelMax)
			yacceleration = 0.3;
	}

	void Motion::dirDown(){
		if (yacceleration > -accelMax)
			yacceleration = -0.3;
	}

	void Motion::applySpeed(){
		// use -= to move background opposite to input
		xspeed -= xacceleration;
		yspeed -= yacceleration;

		glTranslatef(xspeed, yspeed, 0);
	}

	void Motion::rotateLeft(int amount){

	}

	void Motion::rotateRight(int amount){

	}

} }