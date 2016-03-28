#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include <ctime>
#include <vector>
#include <GL/glu.h>
#include <GL/gl.h>
#include "Bullet.h"
#include "../graphics/Window.h"
#include "../motion/MotionController.h"

namespace spacey{ namespace objects{
	using namespace std;
	using namespace graphics;
	using namespace motion;

	class PlayerObject : public Bullet, public BaseObject{
		public:
			PlayerObject(Window* window, string filename, int texWidth, int texHeight);
			void Draw(Motion* motion);
		
			int health = 100;
			vector<Bullet> shot;
			void takeDamage(int amount);

		private: 
			void checkRotation(Motion* motion);
			void checkFire();
			void regenHealth();
		private: //Misc
			Window* m_window;
			int direction = 3;

		private: //Clock varaibles
			clock_t start;
			double passed;
			const double wait = 0.5;

			clock_t delay; //Clock for how fast you can shoot
			double waited;
			const double shotLast = 2;

			clock_t healthStart;
			double healthPassed;
			const double healthWait = 30.0;
		private: //Animation
			bool checkAnimState(Motion* motion);
			void animate(int frameSpeed, int startFrame, int maxFrames);

			int framesPerRow;
			int counter = 0;
			int currentFrame = 0;

			int m_texWidth;
			int m_texHeight;

		};
} }