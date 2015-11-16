#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "../objects/CircleObject.h"
#include "../objects/Wall.h"

namespace spacey{ namespace level{

	using namespace objects;
	using namespace std;

	vector<CircleObject> loadPlanets(vector<CircleObject> systemVector, string fileName);
	vector<Wall> loadPlanets(vector<Wall> terrainVector, string fileName);


} }