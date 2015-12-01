#pragma once
#include "BaseObject.h"
#include <GL\glew.h>
#include <GL\GLU.h>
#include "Bullet.h"
#include <vector>
#include <stdlib.h>

namespace spacey{ namespace objects{

	class BaseEnemy : Bullet{	
	public:
		BaseEnemy(); //Constructor
		~BaseEnemy(); //Destructor

		BaseEnemy(int x, int y); //Overload Function

		void draw(int xInput, int yInput, int colCode);
	private:
		std::vector<Bullet> delaware;
		int m_xInput, m_yInput, m_colCode;
		int counter, steps;
		int direction = 3;
		
		void createNewBullet(); //Creates new bullet every x ticks
		void bulletFill(); //Fills bullet vector
		void move(); //Moving entity along with the background
		void walk(); //Enemy moves
	};

} }