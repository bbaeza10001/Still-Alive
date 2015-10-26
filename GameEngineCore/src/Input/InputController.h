#pragma once
#include "../graphics/Window.h"
#include "../motion/MotionController.h"

namespace spacey{ namespace input{
	using namespace graphics;
	using namespace motion;

	void checkForInput(Window* window, Motion* motionController);

} }