#pragma once

#include "BaseObject.h"

namespace spacey{
	namespace objects{
		class Wall : public BaseObject{
		public:
			Wall();
			Wall(int width, int height, int x, int y);
			void Draw();
			unsigned m_width, m_height;
			
		};
	}
}