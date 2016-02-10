#include "MotionController.h"

namespace spacey{ namespace motion{

	void Motion::dirRight(){
		xspeed = speed;
		animFlag = "WALK_RIGHT";
	}

	void Motion::dirLeft(){
		xspeed = -speed;
		animFlag = "WALK_LEFT";
	}

	void Motion::dirUp(){
		yspeed = speed;
		animFlag = "WALK_UP";
	}

	void Motion::dirDown(){
		yspeed = -speed;
		animFlag = "WALK_DOWN";
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