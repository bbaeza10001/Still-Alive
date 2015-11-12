#include "Wall.h"

namespace spacey{
	namespace objects{

		Wall::Wall(){
			m_width = 0;
			m_height = 0;
		}

		Wall::Wall(int width, int height, int x, int y){
			m_width = width;
			m_height = height;
			x_coord = x;
			y_coord = y;
		}

		void Wall::draw(int xIN, int yIN, int colCode){
			m_xIN = xIN;
			m_yIN = yIN;
			m_colCode = colCode;

			move();

			glPushMatrix();
			glTranslatef(x_coord, y_coord, 0);
			glBegin(GL_QUADS);
			glVertex2f(x_coord, y_coord);
			glVertex2f(x_coord, y_coord + m_height);
			glVertex2f(x_coord + m_width, y_coord + m_height);
			glVertex2f(x_coord + m_width, y_coord);
			glEnd();

			glPopMatrix();
		}

		void Wall::move(){
			//X Movements
			if (m_xIN == 1 && m_colCode != 1){
				x_coord++;
			}
			else if (m_xIN == 2 && m_colCode != 2){
				x_coord--;
			}

			//Y Movements
			if (m_yIN == 3 && m_colCode != 3){
				y_coord--;
			}
			else if (m_yIN == 4 && m_colCode != 4){
				y_coord++;
			}
		}
	}
}