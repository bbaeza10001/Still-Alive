#pragma once
#include "BaseObject.h"
#include "BaseEntity.h"
#include "../motion/MotionController.h"
#include <GL\glew.h>
#include <GL\GLU.h>
#include <vector>
#include <stdlib.h>
//Note: Everything in relation to the basic melee enemy was made and commented by Evan Martin unless their is a comment saying otherwise
namespace spacey{
	namespace objects{

		using namespace motion;

		class MeleeEnemy : public BaseEntity{
		public:
			MeleeEnemy(); //Constructor
			~MeleeEnemy(); //Destructor

			MeleeEnemy(int x, int y, int tWidth, int tHeight, string filename); //Overload Function


			int health = 100;
		private: //Direction and Movement Tracking
			const int STEP_MAX = 300;
			int counter;
			int direction = 3;
			int steps = 400;
			int pointing = 0;

		public: //AI
			void AI(string indicator);
			void walk();

		public: //Size
			float m_width = 32;
			float m_height = 32;
		};

	}
}
	
