#pragma once

#include "../graphics/Window.h"
#include "../graphics/Texture.h"
#include "../graphics/lodepng.h"
#include <vector>
#include <string>

namespace spacey{ namespace input{

	using namespace graphics;
	using namespace std;

	class button{
	public:
		button();
		button(Window* window, double x, double y, double width, double height, string filename);
		void draw();
		bool clicked();

	private:
		//Member Variables
		Window* m_window;
		double m_x;
		double m_y;
		double m_width;
		double m_height;
		string m_filename;

		//Image Variables
		std::vector<unsigned char> image;
		double u3;
		double v3;
	};

} }