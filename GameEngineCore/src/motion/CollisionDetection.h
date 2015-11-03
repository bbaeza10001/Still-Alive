#pragma once
#include <vector>
#include <Windows.h>
#include "../objects/CircleObject.h"
#include <algorithm>
#include <iterator>

namespace spacey{ namespace motion{
	
	using namespace objects;
	using namespace std;

	bool checkCollision(vector<CircleObject> &terrain);

} }