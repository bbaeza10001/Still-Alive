#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include <vector>
#include "../graphics/Window.h"
#include "Bullet.h"

namespace spacey{ namespace objects{
	using namespace graphics;
	using namespace std;

	class PlayerObject : public Bullet{
		public:
			PlayerObject(Window* window);
			void Draw(int xInput, int yInput, int colCode);
		private: 
			void checkRotation();
			void checkFire();
			Window* m_window;
			vector<Bullet> shot;
			int m_xInput, m_yInput, m_colCode;
			int direction = 0;
		private:
			float x1 = -5.0f;
			float x2 = 0.0f;
			float x3 = 5.0f;
			float y1 = -10.0f;
			float y2 = 10.0f;
			float y3 = -10.0f;
		};
} }