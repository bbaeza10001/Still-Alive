#pragma once
#include "../graphics/Window.h"
#include "../motion/MotionController.h"

namespace spacey{ namespace input{
	using namespace graphics;
	using namespace motion;

	class Input{
	public:
		void checkForInput(Window* window, Motion* motionObject);
	};

} }