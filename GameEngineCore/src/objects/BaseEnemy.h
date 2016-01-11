#pragma once
#include "BaseObject.h"
#include "Bullet.h"
#include "../motion/MotionController.h"
#include <GL\glew.h>
#include <GL\GLU.h>
#include <vector>
#include <stdlib.h>

namespace spacey{ namespace objects{

	using namespace motion;

	class BaseEnemy : Bullet, public BaseObject{	
	public:
		BaseEnemy(); //Constructor
		~BaseEnemy(); //Destructor

		BaseEnemy(int x, int y, string filename); //Overload Function

		void Draw(Motion* motion);
	private:
		std::vector<Bullet> delaware; 
		int counter, steps;
		int direction = 3;
		int pointing = 0;
		
		void createNewBullet(); //Creates new bullet every x ticks
		void bulletFill(); //Fills bullet vector
		void walk(); //Enemy moves
	};

} }