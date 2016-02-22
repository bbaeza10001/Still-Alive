#pragma once

#include <iostream>
#include <vector>
#include "CircleObject.h"
#include "BaseEnemy.h"
#include "PlayerObject.h"
#include "MeleeEnemy.h"
#include "Wall.h"
#include "../graphics/Window.h"
#include "../graphics/LoadLevel.h"
#include "../motion/Orbits.h"
#include "../motion/MotionController.h"

namespace spacey{
	namespace background{

		using namespace std;
		using namespace objects;
		using namespace level;
		using namespace motion;
		using namespace graphics;

		class BG{
		public: //Set up functions
			BG();
			BG(Window* window);
			void loadEntity(string filename, string type);

			void update(Motion* motion, PlayerObject* player);
			//Add functions to load in enemies and 
			//other background elements

		public: //Other Functions
			int testCollision();

		private: //Personal Functions
			void move(Motion* motion);
			void collided();
			void checkBullets(PlayerObject* player);

		private: //Objects
			vector<CircleObject> planets;
			vector<BaseEnemy> B_Enemy;
			vector<Wall> walls;
			vector<MeleeEnemy> Ml_Enemy;

		private: //Tools
			Window* m_window;
			Orbit orb;
			bool hit = false;
			int colCode;
		};
	}
}