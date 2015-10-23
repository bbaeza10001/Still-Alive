#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "../objects/CircleObject.h"

namespace spacey{ namespace level{

	using namespace objects;
	using namespace std;

	class Level{

	public:
		vector<CircleObject> loadPlanets(vector<CircleObject> systemVector, string fileName);
	private:

	};

} }