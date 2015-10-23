#pragma once

#include "BaseObject.h"
#include <iostream>

namespace spacey{ namespace objects{

	class Bullet : public BaseObject{
	public:
		void Fire();
		void reset();

		float bX = x_coord;
		float bY = y_coord;
	private:
		void Move();
		int counter;
	};

} }