#pragma once
#include "../graphics/Window.h"

namespace spacey{ namespace input{
	using namespace graphics;

	int checkForXInput(Window* window);
	int checkForYInput(Window* window);

} }