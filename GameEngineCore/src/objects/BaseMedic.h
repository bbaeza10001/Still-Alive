//Written by Will and Kenny
#pragma once
#include "BaseEnemy.h"
#include "../motion/MotionController.h"
#include <GL\glew.h>
#include <GL\GLU.h>
#include <vector>
#include <stdlib.h>

namespace spacey{
	namespace objects{

		using namespace motion;

		class BaseMedic : public BaseEnemy{
		public:
			BaseMedic(); //Constructor
			~BaseMedic(); //Destructor
void Heal(BaseEnemy &enem);
			BaseMedic(int x, int y, string filename); //Overload Function

			void Draw(Motion* motion);

			int health = 100;
		private:
			int counter;
			int direction = 3;
			int pointing = 0;

			
		};
	}
}