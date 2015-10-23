#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include <iostream>

namespace spacey{ namespace motion{

	class Motion{
	public:
		//For Translations
		float xacceleration = 0;
		float yacceleration = 0;
		
		void dirRight();
		void dirLeft();
		void dirUp();
		void dirDown();

		//For Rotations
		void rotateLeft(int amount);
		void rotateRight(int amount);
		float angleIncriment = 0.1f;

		//Movement Application
		void applySpeed();
		void applyRotation();

	private:
		//For Translations
		float xspeed = 0;
		float yspeed = 0;

		//For Rotations
		float angle = 0;

		//Max Value
		float const accelMax = 10;
	};

} }