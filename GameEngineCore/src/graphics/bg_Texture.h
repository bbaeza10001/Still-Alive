#pragma once
#include "../objects/BaseObject.h"
#include "Window.h"
#include <vector>
#include <string>
#include <iostream>

namespace spacey{
	namespace graphics{
		using namespace objects;
		using namespace std;

		class bg_Texture : BaseObject{
		public:
			bg_Texture();
			bg_Texture(Window* window, string filename);
			void Draw();
		private:
			void parallax();
			bool loadBG(string filename);
			Window* m_window;

			unsigned width;
			unsigned height;
		};
	}
}