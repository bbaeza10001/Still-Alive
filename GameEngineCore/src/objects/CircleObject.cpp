#include "CircleObject.h"

namespace spacey{
	namespace objects{
		CircleObject::CircleObject(){
			radius = 1;
			x_coord = 0;
			y_coord = 0;
		}

		CircleObject::CircleObject(float x_in, float y_in, float radius_in){
			x_coord = x_in;
			y_coord = y_in;
			radius = radius_in;
		}

		void CircleObject::Draw(int xInput, int yInput, int colCode){
			const float full_angle = 2.0f*3.141592654f;
			float xN = 0.0f;
			float yN = 0.0f;

			m_xInput = xInput;
			m_yInput = yInput;
			m_colCode = colCode;
			
			move();

			glPushMatrix();
			glTranslatef(x_coord, y_coord, 0);
			glBegin(GL_POLYGON);
			for (float i = 0; i < 180; i++)
			{
				xN = radius * (std::cos(i * full_angle / 180.0f));
				yN = radius * (std::sin(i * full_angle / 180.0f));

				
				glColor3f((xN * 0.01), (yN * 0.01), 0.5f); //Sets color of planets
				glVertex2d(xN, yN);
			}
			glEnd();
			
			glPopMatrix();

		}

		void CircleObject::move(){
			//X Movements
			if (m_xInput == 1 && m_colCode != 1){
				x_coord++;
			}
			else if (m_xInput == 2 && m_colCode != 2){
				x_coord--;
			}

			//Y Movements
			if (m_yInput == 3 && m_colCode != 3){
				y_coord--;
			}
			else if (m_yInput == 4 && m_colCode != 4){
				y_coord++;
			}
		}
	}
}