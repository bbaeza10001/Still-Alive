#pragma once
#include <GL\glew.h>
#include <GL\GLU.h>
#include <cmath>
#include <math.h>
#include "BaseObject.h"

namespace spacey{ namespace objects{
		
	class CircleObject : public BaseObject{
		public:
			CircleObject();
			CircleObject(float x_in, float y_in, float radius_in);
			void Draw(int xInput, int yInput, int colCode);
			float radius;
		private:
			void move();
			int m_xInput, m_yInput, m_colCode;
		};
} }