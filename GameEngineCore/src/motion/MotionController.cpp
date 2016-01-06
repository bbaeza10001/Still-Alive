#include "MotionController.h"

namespace spacey{ namespace motion{

	void Motion::dirRight(){
		xspeed = speed;
	}

	void Motion::dirLeft(){
		xspeed = -speed;
	}

	void Motion::dirUp(){
		yspeed = speed;
	}

	void Motion::dirDown(){
		yspeed = -speed;
	}

	void Motion::rotateLeft(){
		angle -= angleIncriment;

		//Angle resetting to stay within 360 degrees
		while (angle >= 360){
			angle -= 360;
		}
		while (angle < 0){
			angle += 360;
		}
	}

	void Motion::rotateRight(){
		angle += angleIncriment;

		//Angle resetting to stay within 360 degrees
		while (angle >= 360){
			angle -= 360;
		}
		while (angle < 0){
			angle += 360;
		}
	}

	void Motion::applySpeed(){
		// use -= to move background opposite to input
		xspeed = -xspeed;
		yspeed = -yspeed;

		glTranslatef(xspeed, yspeed, 0);

	}

	void Motion::applyRotation(){
		glRotatef(-angle, 0, 0, 1);
	}
} }