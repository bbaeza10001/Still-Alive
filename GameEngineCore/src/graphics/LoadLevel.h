#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "../objects/CircleObject.h"
#include "../objects/BaseEnemy.h"

namespace spacey{ namespace level{

	using namespace objects;
	using namespace std;

	void loadObject(vector<CircleObject> &container, string fileName);
	void loadObject(vector<BaseEnemy> &container, string fileName);


} }