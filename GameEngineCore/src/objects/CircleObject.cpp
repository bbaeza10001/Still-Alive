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

		void CircleObject::Draw(int inputValue){
			const float full_angle = 2.0f*3.141592654f;
			float xN = 0.0f;
			float yN = 0.0f;

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

			move(inputValue);
		}

		void CircleObject::move(int inputValue){
			switch (inputValue){
			case 1:
				x_coord++;
				break;
			case 2:
				x_coord--;
				break;
			case 3:
				y_coord--;
				break;
			case 4:
				y_coord++;
				break;
			}
		}
	}
}