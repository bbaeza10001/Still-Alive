#pragma once

#include "BaseObject.h"

namespace spacey{
	namespace objects{
		class Wall : public BaseObject{
		public:
			Wall();
			Wall(int width, int height, int x, int y);
			void draw(int xIN, int yIN, int colCode);
			int m_width, m_height;
		private:
			void move();
			int m_xIN, m_yIN, m_colCode;
		};
	}
}