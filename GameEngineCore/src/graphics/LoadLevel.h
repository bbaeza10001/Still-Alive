#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "../objects/CircleObject.h"
#include "../objects/BaseEnemy.h"
#include "../objects/Wall.h"
#include "../objects/MeleeEnemy.h"
#include "../objects/Door.h"

namespace spacey{ namespace level{

	using namespace objects;
	using namespace environment;
	using namespace std;

	void loadObject(vector<CircleObject> &container, string fileName);
	void loadObject(vector<BaseEnemy> &container, string fileName);
	void loadObject(vector<Wall> &container, string fileName);
	void loadObject(vector<MeleeEnemy> &container, string fileName);
	void loadObject(vector<Door> &container, string fileName);

} }