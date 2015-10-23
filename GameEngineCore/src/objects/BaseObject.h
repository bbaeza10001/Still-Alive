#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>

namespace spacey{
	namespace objects{
		struct BaseObject{
			float x_coord;
			float y_coord;
			int orientation;
		};
	}
}