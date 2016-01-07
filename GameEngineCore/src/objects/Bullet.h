#pragma once

#include "BaseObject.h"
#include <iostream>

namespace spacey{ namespace objects{

	class Bullet {
	public:
		Bullet();
		Bullet(int direction);
		void Fire();

		bool limit();

		float bX;
		float bY;

		float bx_coord;
		float by_coord;
	private:
		void Move();
		int m_direction;
	};

} }