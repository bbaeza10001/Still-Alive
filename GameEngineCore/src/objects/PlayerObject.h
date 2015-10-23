#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include "../graphics/Window.h"
#include "Bullet.h"

namespace spacey{ namespace objects{
	using namespace graphics;

	class PlayerObject : public Bullet{
		public:
			PlayerObject(Window* currentWindow);
			void Draw();
		private: 
			void checkRotation();
			void checkFire();
			Window* m_window;
		};
} }