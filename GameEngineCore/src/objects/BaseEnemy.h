#pragma once
#include "BaseEntity.h"
#include "Bullet.h"
#include "../motion/MotionController.h"
#include <GL\glew.h>
#include <GL\GLU.h>
#include <vector>
#include <stdlib.h>

namespace spacey{ namespace objects{

	using namespace motion;

	class BaseEnemy : public Bullet, public BaseEntity{	
	public:
		BaseEnemy(); //Constructor
		~BaseEnemy(); //Destructor

		BaseEnemy(int x, int y, int tWidth, int tHeight, string filename); //Overload Function

		std::vector<Bullet> delaware; 
		
		const int STEP_MAX = 300;
		int steps;

		int health = 50;
	private:
		int counter;
		int direction = 3;
		int pointing = 0;
		
		void createNewBullet(); //Creates new bullet every x ticks
		void bulletFill(); //Fills bullet vector
		void walk(); //Enemy moves

	public:
		void AI(string indicator);
		int m_width = 16;
		int m_height = 16;
	public:
		BaseEnemy operator=(BaseEnemy right);
	};

} }