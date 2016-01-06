#include "BG.h"

namespace spacey{
	namespace background{
	
		BG::BG(){
			planets.clear();
		}

		BG::BG(Window* window){
			m_window = window;
		}

		void BG::loadEntity(string filename, string type){
			if (type == "PLANET")
				loadObject(planets, filename);

			if (type == "BASE_ENEMY")
				loadObject(B_Enemy, filename);

			cout << "Elements added to BG vector\n";
		}

		void BG::update(Motion* motion){
			glPushMatrix();
			motion->applySpeed();
			move(motion);

			for (unsigned int i = 0; i < planets.size(); i++){
				if (planets[i].x_coord < 800 && planets[i].x_coord > -800){
					if (planets[i].y_coord < 600 && planets[i].y_coord > -600){
						planets[i].Draw();
					}
				}
			}
			orb.orbit(planets);

			for (unsigned int i = 0; i < B_Enemy.size(); i++){
				if (B_Enemy[i].x_coord < 800 && B_Enemy[i].x_coord > -800){
					if (B_Enemy[i].y_coord < 600 && B_Enemy[i].y_coord > -600){
						B_Enemy[i].Draw(motion);
					}
				}
			}


			glPopMatrix();
		}

		void BG::move(Motion* motion){
			
			for (unsigned int i = 0; i < planets.size(); i++){
				planets[i].x_coord += motion->xspeed;
				planets[i].y_coord += motion->yspeed;

			}

			for (unsigned int i = 0; i < B_Enemy.size(); i++){
				B_Enemy[i].x_coord += motion->xspeed;
				B_Enemy[i].y_coord += motion->yspeed;

			}
			
		}

		int BG::testCollision(){
			collided();

			if (hit && m_window->isKeyPressed(GLFW_KEY_A) &&
				colCode == 0){
				colCode = 1;
			}
			else if (hit && m_window->isKeyPressed(GLFW_KEY_D) &&
				colCode == 0){
				colCode = 2;
			}
			else if (hit && m_window->isKeyPressed(GLFW_KEY_W) &&
				colCode == 0){
				colCode = 3;
			}
			else if (hit && m_window->isKeyPressed(GLFW_KEY_S) &&
				colCode == 0){
				colCode = 4;
			}
			else if (!hit){
				colCode = 0;
			}

			return colCode;
		}

		void BG::collided(){
			hit = false;

			for (int i = 0; i < planets.size(); i++){
				if (planets[i].x_coord + (planets[i].radius / 2) >= -5 && planets[i].x_coord - (planets[i].radius / 2) <= 5){
					if (planets[i].y_coord + (planets[i].radius / 2) >= -5 && planets[i].y_coord - (planets[i].radius / 2) <= 5){
						hit = true;
					}
				}
			}

		}

	}
}