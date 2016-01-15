#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include <vector>
#include "Bullet.h"
#include "../graphics/Window.h"
#include "../motion/MotionController.h"

namespace spacey{ namespace objects{
	using namespace std;
	using namespace graphics;
	using namespace motion;

	class PlayerObject : public Bullet, public BaseObject{
		public:
			PlayerObject(Window* window, string filename);
			void Draw(Motion* motion);
		
			int health = 100;
			void takeDamage(int amount);
		private: 
			void checkRotation(Motion* motion);
			void checkFire();
		private:
			Window* m_window;
			vector<Bullet> shot;
			int direction = 3;
		};
} }