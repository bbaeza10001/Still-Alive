#pragma once
#include "CircleObject.h"
#include <vector>
#include <fstream>
#include <string>

namespace spacey { namespace objects {

	using namespace std;

	class BG{
	public:
		void loadObjects(char* filename);
	
	private:
		void draw();
		vector<CircleObject> circles;

	};

} }
