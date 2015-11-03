#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include <iostream>

namespace spacey{
	namespace objects{
		struct BaseObject{
			float x_coord;
			float y_coord;
			int orientation;

			void translate(int inputValue);
		};
	}
}