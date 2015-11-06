#pragma once

#include "BaseObject.h"
#include <iostream>

namespace spacey{ namespace objects{

	class Bullet : public BaseObject{
	public:
		void Fire(int xInput, int yInput, int colCode);

		bool limit();

		float bX = x_coord;
		float bY = y_coord;
		int orientation = 3;
	private:
		void Move(int xInput, int yInput, int colCode);
	};

} }