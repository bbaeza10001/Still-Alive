#pragma once
#include "BaseObject.h"
#include "../motion/MotionController.h"
#include <GL\glew.h>
#include <GL\GLU.h>
#include <vector>
#include <stdlib.h>
//Note: Everything in relation to the basic melee enemy was made and commented by Evan Martin unless their is a comment saying otherwise
namespace spacey{
	namespace objects{

		using namespace motion;

		class MeleeEnemy : public BaseObject{
		public:
			MeleeEnemy(); //Constructor
			~MeleeEnemy(); //Destructor

			MeleeEnemy(int x, int y, string filename); //Overload Function

			void Draw(Motion* motion);
			

			const int STEP_MAX = 300;
			int steps = 400;

			int health = 100000;
			int direction = 3;
		private:
			int counter;
			
			int pointing = 0;

			void walk(); //Enemy moves

		public:
			MeleeEnemy operator=(MeleeEnemy right);
		};

	}
}
	
