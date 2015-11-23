#pragma once
#include "BaseObject.h"
#include <GL\glew.h>
#include <GL\GLU.h>

namespace spacey{ namespace objects{

	class BaseEnemy : BaseObject{
	public:
		BaseEnemy(); //Constructor
		~BaseEnemy(); //Destructor

		BaseEnemy(int x, int y); //Overload Function

		void draw(int xInput, int yInput, int colCode);
	private:
		void move(); //Moving entity along with the background
		int m_xInput, m_yInput, m_colCode;
	};

} }